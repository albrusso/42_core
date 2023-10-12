/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:16:05 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/12 16:31:46 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	valid_args(int ac, char *av[])
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (false);
			j++;
		}
		if (ft_atoi(av[i]) < 1)
			return (false);
		i++;
	}
	return (true);
}

void	init_data(int ac, char *av[], t_data *d)
{
	if (valid_args(ac, av))
		return ;
	d->p_nbr = ft_atoi(av[1]);
	d->t_die = ft_atoi(av[2]);
	d->t_eat = ft_atoi(av[3]);
	d->t_sleep = ft_atoi(av[4]);
	if (ac == 5)
		d->r_nbr = -1;
	else
		d->r_nbr = ft_atoi(av[5]);
	
}