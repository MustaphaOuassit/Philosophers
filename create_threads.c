/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:34:34 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/19 19:40:35 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *routine(void *arg)
{
    data_t *data;

    data = (data_t *)arg;
	data->nb_philo++;
	printf("%d\n",data->nb_philo);
    return NULL;
}

void	create_threads(int nb_philo, data_t *data)
{
	pthread_t	*thread_id;
	int			i;
	
	thread_id = (pthread_t *)malloc(sizeof(pthread_t) * nb_philo);
	i = 0;
	while (i < nb_philo)
	{
		pthread_create(&thread_id[i], NULL, routine, data);
        i++;
    }
}