/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:40:24 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/16 23:25:26 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t mutex;

void    *routine(void *arg)
{
    data_t *id;

    id = (data_t *)arg;
    id->nb_philo++;
    printf("--%d--\n",id->nb_philo);
    return NULL;
}

int     check_time(long long time)
{
    struct timeval current_time;
    long long current;
    
    gettimeofday(&current_time,NULL);
    current = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
    return(current - time);
}

int main(){
    long long time;
    struct timeval current_time;
    int *i;
    data_t **data;
    pthread_t *thread_id;
    data_t *philo;
    
    data = (data_t **)malloc(sizeof(data_t *) * 2);
    pthread_mutex_init(&mutex,NULL); 
   thread_id = (pthread_t *)malloc(sizeof(pthread_t) * 2);
    i = malloc(4);
    *i = 0;
    gettimeofday(&current_time,NULL);
    time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
    while (*i < 2)
    {
        pthread_create(&thread_id[*i],NULL,routine,&philo);
        usleep(1);
        *i = *i + 1;
    }
    pthread_mutex_destroy(&mutex);
}