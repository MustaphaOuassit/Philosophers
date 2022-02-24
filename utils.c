/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 06:17:52 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/24 08:41:43 by mouassit         ###   ########.fr       */
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