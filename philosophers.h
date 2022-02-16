/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:41:07 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/16 23:21:21 by mouassit         ###   ########.fr       */
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
    int number_of_philosopher;
    char   time_to_die;
    int  time_to_eat;
    int  time_to_sleep;
    char   *str;
} info_t;
typedef struct s_data
{
    int nb_philo;
} data_t;
