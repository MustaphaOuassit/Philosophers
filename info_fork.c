/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:34:21 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/28 16:41:20 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t *info_fork(int nb_philo)
{
    pthread_mutex_t *forks;
    int i;

    forks = malloc(sizeof(*forks) * nb_philo);
    i = 0;
    while (i < nb_philo)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
    return(forks);
}