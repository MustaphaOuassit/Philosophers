/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:41:07 by mouassit          #+#    #+#             */
/*   Updated: 2022/03/01 03:33:13 by mouassit         ###   ########.fr       */
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
	long			start_time;
	int				number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	message;
}	info_t;

typedef struct s_data
{
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	info_t			*info;
	int				nb_philo;
	long			start_time;
	int				eat;
	int				time_to_eat;
	int				time_to_sleep;
	long			last_eat;
}	data_t;

int				check_info(int argc, char **argv,info_t *data);
data_t			*info_philo(info_t data);
pthread_mutex_t	*info_fork(int nb_philo);
void			create_threads(info_t data ,data_t *philosophers, pthread_mutex_t *forks);
long			get_time();
void			put_forks(data_t *philosophers);
void			edit_usleep(long time);
void			*supervisor(data_t *philosophers, int time_to_die);
void			print_state(data_t *philosophers, char *str);
void			fix_usleep(useconds_t time);
int				ft_atoi(const char *str);