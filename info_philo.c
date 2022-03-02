/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:49:51 by mouassit          #+#    #+#             */
/*   Updated: 2022/03/02 18:35:55 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

data_t	*info_philo(info_t data)
{
	data_t	*philo;
	int		i;

	philo = malloc(sizeof(*philo) * data.number_of_philosopher);
	i = 0;
	while (i < data.number_of_philosopher)
	{
		philo[i].nb_philo = i + 1;
		philo[i].time_to_eat = data.time_to_eat;
		philo[i].time_to_sleep = data.time_to_sleep;
		philo[i].philo_must_eat = 0;
		i++;
	}
	return (philo);
}

int	check_digit(int argc, char **argv)
{
	int		i;
	size_t	check;

	i = 1;
	check = 0;
	while (i < argc)
	{
		check = 0;
		while (check < ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][check]))
				return (0);
			check++;
		}
		i++;
	}
	return (1);
}

int	check_len_nb(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 10 || ft_atoi(argv[i]) < 0
			|| ft_atoi(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_info(int argc, char **argv, info_t *data)
{
	int	i;

	i = 0;
	if (argc > 6 || argc < 5)
	{
		printf("Error : Arguments\n");
		return (1);
	}
	if (!check_digit(argc, argv) || !check_len_nb(argc, argv))
	{
		printf("Error : Invalid arguments\n");
		return (1);
	}
	data->number_of_philosopher = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_eat = -1;
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	return (0);
}
