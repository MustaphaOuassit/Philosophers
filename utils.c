/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 06:17:52 by mouassit          #+#    #+#             */
/*   Updated: 2022/03/02 13:01:31 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long    get_time()
{
    struct timeval	time;
    
    gettimeofday(&time, NULL);
    return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long    get_time_us()
{
    struct timeval	time;
    
    gettimeofday(&time, NULL);
    return((time.tv_sec * 1000000) + time.tv_usec);
}

void    put_forks(data_t *philosophers)
{
    pthread_mutex_unlock(philosophers->left_fork);
    pthread_mutex_unlock(philosophers->right_fork);
}

int     check_must_eat(data_t *philosophers, info_t data)
{
    int i;

    i = 0;
    while (i < data.number_of_philosopher)
    {
        if(philosophers[i].philo_must_eat < data.must_eat)
            return(0);
        i++;
    }
    return(1);
}

void    *supervisor(data_t *philosophers, info_t data)
{
    int i;
    while (1)
    {
        i = 0;
        while (i < data.number_of_philosopher)
        {
            if (get_time() - philosophers[i].last_eat >= data.time_to_die)
            {
                pthread_mutex_lock(&philosophers[i].info->message);
                printf("%ld %d died\n",get_time() - philosophers[i].start_time,philosophers[i].nb_philo);
                return NULL;
            }
            i++;
        }
        if(data.must_eat != -1)
        {
            if(check_must_eat(philosophers, data))
                return NULL;
        }
    }
}

void    fix_usleep(useconds_t time)
{
    long    start_time;

    start_time = get_time_us();
    usleep(time - 20000);
    while (get_time_us() - start_time < time);
    
}

void    print_state(data_t *philosophers, char *str)
{
    pthread_mutex_lock(&philosophers->info->message);
    printf("%ld %d %s\n",get_time() - philosophers->start_time,philosophers->nb_philo ,str);
    pthread_mutex_unlock(&philosophers->info->message);
}

void    create_philo_pair(data_t *philosophers, info_t data, info_t *info, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
    while (i < data.number_of_philosopher)
    {
        philosophers[i].start_time = data.start_time;
        philosophers[i].last_eat = get_time();
        philosophers[i].info = info;
        philosophers[i].left_fork = &forks[i];
        philosophers[i].right_fork = &forks[(i + 1) % data.number_of_philosopher];
        pthread_create(&philosophers[i].thread_id, NULL, routine, &philosophers[i]);
        i += 2;
    }
}

void    create_philo_unpair(data_t *philosophers, info_t data, info_t *info, pthread_mutex_t *forks)
{
	int	i;

	i = 1;
    while (i < data.number_of_philosopher)
    {
        philosophers[i].start_time = data.start_time;
        philosophers[i].last_eat = get_time();
        philosophers[i].info = info;
        philosophers[i].left_fork = &forks[i];
        philosophers[i].right_fork = &forks[(i + 1) % data.number_of_philosopher];
        pthread_create(&philosophers[i].thread_id, NULL, routine, &philosophers[i]);
        i += 2;
    }
}