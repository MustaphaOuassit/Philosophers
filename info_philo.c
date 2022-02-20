/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:49:51 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/20 22:05:00 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

data_t	*info_philo(info_t data)
{
	data_t *philo;
	int 	i;
	
	philo = malloc(sizeof(*philo) * data.number_of_philosopher);
	i = 0;
	while (i < data.number_of_philosopher)
	{
		philo[i].nb_philo = i + 1;
		i++;
	}
	return(philo);
}

int		check_info(int argc, char **argv, info_t *data)
{
	int i;
	
	i = 0;
	if (argc < 2)
	{
		printf("Error : arguments\n");
		return (1);
	}
	data->number_of_philosopher = ft_atoi(argv[1]);
	return(0);
}