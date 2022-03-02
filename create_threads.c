/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:34:34 by mouassit          #+#    #+#             */
/*   Updated: 2022/03/02 11:02:00 by mouassit         ###   ########.fr       */
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
    print_state(philosophers, "is eating");
    fix_usleep(philosophers->time_to_eat * 1000);
    philosophers->philo_must_eat++;
    philosophers->last_eat = get_time();
    put_forks(philosophers);
}

void    sleeping(data_t *philosophers)
{
    print_state(philosophers, "is sleeping");
    fix_usleep(philosophers->time_to_sleep * 1000);
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
        print_state(philosophers, "is thinking");
    }
    return NULL;
}

void	create_threads(info_t data ,data_t *philosophers, pthread_mutex_t *forks)
{
    info_t  *info;
    pthread_mutex_t message;
    
    info = malloc(sizeof(*info));
    pthread_mutex_init(&message, NULL);
    info->message = message;
    data.start_time = get_time();
    create_philo_pair(philosophers,data,info,forks);
    usleep(100);
    create_philo_unpair(philosophers,data,info,forks);
}