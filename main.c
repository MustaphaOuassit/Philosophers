/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:40:24 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/14 00:00:35 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *routine(void *arg)
{
    info_t *data;

    data = arg;
    printf("hello : %d\n",data->number_of_philosopher);
    data->number_of_philosopher = 105605;
    return NULL;
}

int main(){
    long long time;
    long long current;
    struct timeval current_time;
    
    gettimeofday(&current_time,NULL);
    time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
    while (1)
    {
        gettimeofday(&current_time,NULL);
        current = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
        printf("%lld\n",current - time);
        if(current - time >= 60)
            break;
    }
    
    
}