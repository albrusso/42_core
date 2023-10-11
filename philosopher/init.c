/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:28:34 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/11 16:35:07 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_data	*init_data(int ac, char *av[])
{
	t_data	*d;

	d->nbr_philo = ft_aoti(av[1]);
	d->time_die = ft_atoi(av[2]);
	d->time_eat = ft_atoi(av[3]);
	d->time_sleep = ft_atoi(av[4]);
	if (ac == 5)
		d->nbr_repeat = -1;
	else
		d->nbr_repeat = ft_atoi(av[5]);
	return (d);
}