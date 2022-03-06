/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:41:07 by mouassit          #+#    #+#             */
/*   Updated: 2022/03/06 16:45:11 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_info{
	long			start_time;
	int				number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	pthread_mutex_t	message;
}	t_info;

typedef struct s_data
{
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	check_eat;
	t_info			*info;
	int				nb_philo;
	long			start_time;
	int				eat;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_must_eat;
	long			last_eat;
}	t_data;

int				check_info(int argc, char **argv, t_info *data);
t_data			*info_philo(t_info data);
pthread_mutex_t	*info_fork(int nb_philo);
void			create_threads(t_info data, t_data *philosophers,
					pthread_mutex_t *forks);
long			get_time(void);
void			put_forks(t_data *philosophers);
void			edit_usleep(long time);
void			*supervisor(t_data *philosophers, t_info data);
void			print_state(t_data *philosophers, char *str);
void			fix_usleep(useconds_t time);
void			*routine(void *arg);
void			create_philo_pair(t_data *philosophers, t_info data,
					t_info *info, pthread_mutex_t *forks);
void			create_philo_unpair(t_data *philosophers, t_info data,
					t_info *info, pthread_mutex_t *forks);
int				check_must_eat(t_data *philosophers, t_info data);
int				must_eat(t_info data, t_data *philosophers);
long			get_time_us(void);
int				ft_atoi(const char *str);
int				ft_isdigit(int n);
size_t			ft_strlen(const char *str);

#endif