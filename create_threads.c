/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:34:34 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/27 17:25:15 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    take_two_forks(data_t *philosophers)
{
    pthread_mutex_lock(philosophers->left_fork);
    print_state(philosophers, "has taken a fork");
    pthread_mutex_lock(philosophers->right_fork);
    print_state(philosophers, "has taken a fork");
}

void    eating(data_t *philosophers)
{
    philosophers->eat = 1;
    philosophers->last_eat = get_time();
    print_state(philosophers, "is eating");
    usleep((philosophers->time_to_eat * 1000) - 20000);
    philosophers->eat = 0;
    put_forks(philosophers);
}

void    sleeping(data_t *philosophers)
{
    print_state(philosophers, "is sleeping");
    usleep((philosophers->time_to_sleep * 1000) - 20000);
}

void    *routine(void *arg)
{
    data_t  *philosophers;
    
    philosophers = arg;
    while (1)
    {
        take_two_forks(philosophers);
        eating(philosophers);
        sleeping(philosophers);
    }
    return NULL;
}

void	create_threads(info_t data ,data_t *philosophers, pthread_mutex_t *forks)
{
    int     i;
    info_t  *info;
    pthread_mutex_t message;
       
    i = 0;
    info = malloc(sizeof(*info));
    pthread_mutex_init(&message, NULL);
    data.start_time = get_time();
    info->message = message;
    while (i < data.number_of_philosopher)
    {
        philosophers[i].start_time = data.start_time;
        philosophers[i].last_eat = data.start_time;
        philosophers[i].info = info;
        philosophers[i].left_fork = &forks[i];
        philosophers[i].right_fork = &forks[(i + 1) % data.number_of_philosopher];
        pthread_create(&philosophers[i].thread_id, NULL, routine, &philosophers[i]);
        i++;
    }
}