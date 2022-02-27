/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 06:17:52 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/27 17:52:06 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long    get_time()
{
    struct timeval	time;
    
    gettimeofday(&time, NULL);
    return((time.tv_sec * 1000) + (time.tv_usec / 100));
}

void    put_forks(data_t *philosophers)
{
    pthread_mutex_unlock(philosophers->left_fork);
    pthread_mutex_unlock(philosophers->right_fork);
}

void    edit_usleep(long time)
{
    printf("--------------%ld----------\n",time);
}

void    *supervisor(data_t *philosophers, int time_to_die)
{
    int i;
    
    while (1)
    {
        i = 0;
        while (i < 10)
        {
            if (get_time() - philosophers[i].last_eat >= time_to_die)
            {
                
                pthread_mutex_lock(&philosophers[i].info->message);
                printf("%ld %d died\n",get_time() - philosophers[i].last_eat,philosophers[i].nb_philo);
                return NULL;

            }
            i++;
        }   
    }
}

void    print_state(data_t *philosophers, char *str)
{
    pthread_mutex_lock(&philosophers->info->message);
    printf("%ld %d %s\n",get_time() - philosophers->start_time,philosophers->nb_philo ,str);
    pthread_mutex_unlock(&philosophers->info->message);
}