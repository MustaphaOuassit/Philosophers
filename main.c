/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:40:24 by mouassit          #+#    #+#             */
/*   Updated: 2022/03/02 18:11:14 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	info_t			data;
	data_t			*philosophers;
	pthread_mutex_t	*forks;

	if (!check_info(argc, argv, &data))
	{
		philosophers = info_philo(data);
		forks = info_fork(data.number_of_philosopher);
		create_threads(data, philosophers, forks);
		supervisor(philosophers, data);
	}
}
