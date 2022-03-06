/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:34:34 by mouassit          #+#    #+#             */
/*   Updated: 2022/03/06 16:53:28 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_two_forks(t_data *philosophers)
{
	pthread_mutex_lock(philosophers->left_fork);
	print_state(philosophers, "has taken a fork");
	pthread_mutex_lock(philosophers->right_fork);
	print_state(philosophers, "has taken a fork");
}

void	eating(t_data *philosophers)
{
	philosophers->eat = 1;
	pthread_mutex_lock(&philosophers->check_eat);
	philosophers->last_eat = get_time();
	print_state(philosophers, "is eating");
	philosophers->eat = 0;
	pthread_mutex_unlock(&philosophers->check_eat);
	fix_usleep(philosophers->time_to_eat * 1000);
	philosophers->philo_must_eat++;
	put_forks(philosophers);
}

void	sleeping(t_data *philosophers)
{
	print_state(philosophers, "is sleeping");
	fix_usleep(philosophers->time_to_sleep * 1000);
}

void	*routine(void *arg)
{
	t_data	*philosophers;

	philosophers = arg;
	while (1)
	{
		take_two_forks(philosophers);
		eating(philosophers);
		sleeping(philosophers);
		print_state(philosophers, "is thinking");
	}
	return (NULL);
}

void	create_threads(t_info data, t_data *philosophers
, pthread_mutex_t *forks)
{
	t_info			*info;
	pthread_mutex_t	message;

	info = malloc(sizeof(*info));
	pthread_mutex_init(&message, NULL);
	info->message = message;
	data.start_time = get_time();
	create_philo_pair(philosophers, data, info, forks);
	usleep(100);
	create_philo_unpair(philosophers, data, info, forks);
}
