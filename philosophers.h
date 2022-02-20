/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:41:07 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/20 21:32:38 by mouassit         ###   ########.fr       */
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
	pthread_t thread_id;
	int		nb_philo;
}	data_t;

int				check_info(int argc, char **argv,info_t *data);
data_t			*info_philo(info_t data);
pthread_mutex_t	*info_fork(int nb_philo);
void			create_threads(info_t data ,data_t *philosophers, pthread_mutex_t *forks);
int				ft_atoi(const char *str);