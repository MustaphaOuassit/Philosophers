/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:34:34 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/20 22:18:16 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *routine(void *arg)
{
    data_t  *philosophers;

    philosophers = arg;
    return NULL;
}

void	create_threads(info_t data ,data_t *philosophers, pthread_mutex_t *forks)
{
    int i;
    forks = NULL;

    i = 0;
    while (i < data.number_of_philosopher)
    {
        pthread_create(&philosophers[i].thread_id, NULL, routine, &philosophers[i]);
        i++;
    }
    
	//philo_list[i].r_fork = &forks_list[(i + 1) % data.n_philo];
}