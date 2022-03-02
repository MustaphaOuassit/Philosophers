/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:41:07 by mouassit          #+#    #+#             */
/*   Updated: 2022/03/02 16:05:19 by mouassit         ###   ########.fr       */
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
	int				must_eat;
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
	int				philo_must_eat;
	long			last_eat;
}	data_t;

int				check_info(int argc, char **argv,info_t *data);
data_t			*info_philo(info_t data);
pthread_mutex_t	*info_fork(int nb_philo);
void			create_threads(info_t data ,data_t *philosophers, pthread_mutex_t *forks);
long			get_time();
void			put_forks(data_t *philosophers);
void			edit_usleep(long time);
void			*supervisor(data_t *philosophers, info_t data);
void			print_state(data_t *philosophers, char *str);
void			fix_usleep(useconds_t time);
void			*routine(void *arg);
void			create_philo_pair(data_t *philosophers, info_t data, info_t *info, pthread_mutex_t *forks);
void			create_philo_unpair(data_t *philosophers, info_t data, info_t *info, pthread_mutex_t *forks);
int				ft_atoi(const char *str);
int				ft_isdigit(int n);
size_t			ft_strlen(const char *str);