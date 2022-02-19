/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:10:23 by mouassit          #+#    #+#             */
/*   Updated: 2022/02/19 19:10:26 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		a;
	long	somme;

	i = 0;
	a = 1;
	somme = 0;
	while (str[i] <= 32 && str[i] > 0)
		if (str[i++] == 27)
			return (0);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			a = -1;
	while (str[i] != '\0' && (str[i] <= '9' && str[i] >= '0'))
		somme = (str[i++] - '0') + somme * 10;
	return (a * somme);
}