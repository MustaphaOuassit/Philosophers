/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:34:21 by mouassit          #+#    #+#             */
/*   Updated: 2022/03/02 18:52:47 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*info_fork(int nb_philo)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(*forks) * nb_philo);
	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

void	fix_usleep(useconds_t time)
{
	long	start_time;

	start_time = get_time_us();
	usleep(time - 20000);
	while (get_time_us() - start_time < time)
		;
}

void	print_state(t_data *philosophers, char *str)
{
	pthread_mutex_lock(&philosophers->info->message);
	printf("%ld %d %s\n", get_time() - philosophers->start_time,
		philosophers->nb_philo, str);
	pthread_mutex_unlock(&philosophers->info->message);
}

void	create_philo_pair(t_data *philosophers, t_info data, t_info *info
, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data.number_of_philosopher)
	{
		philosophers[i].start_time = data.start_time;
		philosophers[i].last_eat = get_time();
		philosophers[i].info = info;
		philosophers[i].left_fork = &forks[i];
		philosophers[i].right_fork = &forks[(i + 1)
			% data.number_of_philosopher];
		pthread_create(&philosophers[i].thread_id, NULL, routine,
			&philosophers[i]);
		i += 2;
	}
}

void	create_philo_unpair(t_data *philosophers, t_info data, t_info *info
, pthread_mutex_t *forks)
{
	int	i;

	i = 1;
	while (i < data.number_of_philosopher)
	{
		philosophers[i].start_time = data.start_time;
		philosophers[i].last_eat = get_time();
		philosophers[i].info = info;
		philosophers[i].left_fork = &forks[i];
		philosophers[i].right_fork = &forks[(i + 1)
			% data.number_of_philosopher];
		pthread_create(&philosophers[i].thread_id, NULL, routine,
			&philosophers[i]);
		i += 2;
	}
}
