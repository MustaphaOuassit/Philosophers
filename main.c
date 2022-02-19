/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:40:24 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/19 19:49:42 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc,char **argv)
{
    data_t      *data;
	data_t		**fill;
	
    if (!check_info(argc))
    {
    	data = malloc(sizeof(data_t));
		fill = NULL;
		fill_data(data, argv);
		info_philo(data->info.number_of_philosopher, fill);
		data->nb_philo = 0;
		create_threads(data->info.number_of_philosopher,data);
    }
}