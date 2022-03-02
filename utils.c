/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 06:17:52 by mouassit          #+#    #+#             */
/*   Updated: 2022/03/02 18:52:47 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	get_time_us(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + time.tv_usec);
}

void	put_forks(t_data *philosophers)
{
	pthread_mutex_unlock(philosophers->left_fork);
	pthread_mutex_unlock(philosophers->right_fork);
}

int	check_must_eat(t_data *philosophers, t_info data)
{
	int	i;

	i = 0;
	while (i < data.number_of_philosopher)
	{
		if (philosophers[i].philo_must_eat < data.must_eat)
			return (0);
		i++;
	}
	return (1);
}

void	*supervisor(t_data *philosophers, t_info data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data.number_of_philosopher)
		{
			if (get_time() - philosophers[i].last_eat >= data.time_to_die)
			{
				pthread_mutex_lock(&philosophers[i].info->message);
				printf("%ld %d died\n", get_time() - philosophers[i].start_time,
					philosophers[i].nb_philo);
				return (NULL);
			}
			i++;
		}
		if (data.must_eat != -1)
		{
			if (check_must_eat(philosophers, data))
				return (NULL);
		}
	}
}
