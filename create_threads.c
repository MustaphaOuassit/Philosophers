/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:34:34 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/24 09:17:17 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    take_two_forks(data_t *philosophers)
{
    pthread_mutex_lock(philosophers->left_fork);
    printf("%d has taken a fork\n",philosophers->nb_philo);
    pthread_mutex_lock(philosophers->right_fork);
    printf("%d has taken a fork\n",philosophers->nb_philo);
}

void    eating(data_t *philosophers)
{
    philosophers->eat = 1;
    printf("%d is eating\n",philosophers->nb_philo);
}

void    *routine(void *arg)
{
    data_t  *philosophers;
    
    philosophers = arg;
    while (1)
    {
        take_two_forks(philosophers);
        eating(philosophers);
    }
    return NULL;
}

void	create_threads(info_t data ,data_t *philosophers, pthread_mutex_t *forks)
{
    int     i;
    
    i = 0;
    while (i < data.number_of_philosopher)
    {
        philosophers[i].start_time = data.start_time;
        philosophers[i].left_fork = &forks[i];
        philosophers[i].right_fork = &forks[(i + 1) % data.number_of_philosopher];
        pthread_create(&philosophers[i].thread_id, NULL, routine, &philosophers[i]);
        i++;
    }
}