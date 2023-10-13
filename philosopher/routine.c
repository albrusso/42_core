/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:13:08 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/13 15:50:43 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_eat(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (d->r_nbr == -1)
		return ;
	else
	{
		while (i < d->p_nbr)
		{
			if (d->p[i].meal_count == d->r_nbr)
				j++;
			i++;
		}
		if (j == d->r_nbr)
			d->stop = true;
	}
}

void	*routine(void *_p)
{
	t_philo	*p;

	p = (t_philo *)_p;
	if (p->id % 2 == 0)
		usleep(p->d->t_eat);
	while (p->d->stop == false)
	{
		p_eat(p->d, p->id - 1);
		p_sleep(p->d, p->id);
		print(p->d, p->id, THINK);
		p_die(p->d, p->id - 1);
		all_eat(p->d);
	}
	return (NULL);
}