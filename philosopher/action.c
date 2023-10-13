/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:35:10 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/13 15:49:27 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_die(t_data *d, int i)
{
	if (d->p[i].last_meal - d->t_start - 100 > d->t_die)
	{
		pthread_mutex_lock(&d->s);
		if (d->stop == false)
			printf("%lld %d %s", get_time() - d->t_start, i + 1, DIE);
		d->stop = true;
		pthread_mutex_unlock(&d->s);
	}
}

void	p_eat(t_data *d, int i)
{
	pthread_mutex_lock(&d->f[d->p[i].f.l]);
	print(d, i + 1, FORK);
	pthread_mutex_lock(&d->f[d->p[i].f.r]);
	print(d, i + 1, FORK);
	print(d, i + 1, EAT);
	pthread_mutex_lock(&d->m);
	d->p[i].last_meal = get_time();
	d->p[i].meal_count++;
	pthread_mutex_unlock(&d->m);
	usleep(d->t_eat * 1000);
	pthread_mutex_unlock(&d->f[d->p[i].f.l]);
	pthread_mutex_unlock(&d->f[d->p[i].f.r]);
}

void	p_sleep(t_data *d, int i)
{
	print(d, i, SLEEP);
	usleep(d->t_sleep * 1000);
}