/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:16:05 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/13 12:35:48 by albrusso         ###   ########.fr       */
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
			if (av[i][j]>= '0' && av[i][j] <= '9')
				j++;
			return (false);
		}
		if (ft_atoi(av[i]) < 1)
			return (false);
		i++;
	}
	return (true);
}

void	init_data(int ac, char *av[], t_data *d)
{
	int	i;

	i = 0;
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
	d->stop = false;
	d->p = (t_philo *)malloc(sizeof(t_philo) * d->p_nbr);
	d->f = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * d->p_nbr);
	if (!d->p || !d->f)
		return ;
	while (i < d->p_nbr)
	{
		if (pthread_mutex_init(d->f + i, NULL) != 0)
			return ;
		i++;
	}
	if (pthread_mutex_init(&d->m, NULL) != 0)
		return ;
}

void	init_philo(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->p_nbr)
	{
		d->p[i].id = i + 1;
		d->p[i].last_meal = 0;
		d->p[i].meal_count = 0;
		d->p[i].f.l = i;
		d->p[i].f.r = (i + i) % d->p_nbr;
		i++;
	}
}