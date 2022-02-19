/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:41:07 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/19 19:35:40 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef struct s_info
{
	int		number_of_philosopher;
	char	time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
}	info_t;

typedef struct s_data
{
	int nb_philo;
	info_t info;
}	data_t;

void	info_philo(int nb, data_t **fill);
int		check_info(int argc);
int		ft_atoi(const char *str);
void	fill_data(data_t *data, char **argv);
void	create_threads(int nb_philo, data_t *data);