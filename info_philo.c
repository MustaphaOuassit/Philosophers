/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:49:51 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/19 19:52:31 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int get_len(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

void	info_philo(int nb, data_t **fill)
{
	int i;
	i = 0;
	
	fill = (data_t **)malloc(sizeof(data_t *) * (nb + 1));
	while (i < nb)
	{
		fill[i] = malloc(sizeof(data_t));
		i++;
	}
	fill[i] = NULL;
}

int		check_info(int argc)
{
	if (argc < 2)
	{
		printf("Error : arguments\n");
		return (1);
	}
	return(0);
}

void	fill_data(data_t *data, char **argv)
{
	data->info.number_of_philosopher = ft_atoi(argv[1]);
}
