/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:14:26 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/13 13:10:38 by albrusso         ###   ########.fr       */
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

void	p_die(t_data *d, int i)
{
	if (&d->p[i].last_meal - d->t_start > d->t_die)
	{
		pthread_mutex_lock(&d->m);
		printf("%lld %d %s", get_time() - d->t_start, i, DIE);
		d->stop = true;
		pthread_mutex_unlock(&d->m);
	}
}

void	p_eat(t_data *d, int i)
{
	pthread_mutex_lock(&d->f[d->p[i].f.l]);
	pthread_mutex_lock(&d->m);
	printf("%lld %d %s", get_time() - d->t_start, i, FORK);
	pthread_mutex_unlock(&d->m);
	pthread_mutex_lock(&d->f[d->p[i].f.r]);
	pthread_mutex_lock(&d->m);
	printf("%lld %d %s", get_time() - d->t_start, i, FORK);
	pthread_mutex_unlock(&d->m);
	pthread_mutex_lock(&d->m);
	printf("%lld %d %s", get_time() - d->t_start, i, EAT);
	d->p[i].last_meal = get_time();
	d->p[i].meal_count++;
	pthread_mutex_unlock(&d->m);
	usleep(d->t_eat);
	pthread_mutex_unlock(&d->f[d->p[i].f.l]);
	pthread_mutex_unlock(&d->f[d->p[i].f.r]);
}

void	p_sleep(t_data *d, int i)
{
	pthread_mutex_lock(&d->m);
	printf("%lld %d %s", get_time() - d->t_start, i, SLEEP);
	usleep(d->t_sleep);
	pthread_mutex_unlock(&d->m);
}

void	*routine(void *_d)
{
	t_data	*d;

	d = (t_data *)_d;
	while (d->stop == false)
	{
		p_eat(d, d->t_id);
		p_sleep(d, d->t_id);
		pthread_mutex_lock(&d->m);
		printf("%lld %d %s", get_time() - d->t_start, d->t_id, THINK);
		pthread_mutex_unlock(&d->m);
		p_die(d, d->t_id);
		all_eat(d);
	}
	

}

void	launch_thread(t_data *d)
{
	int	i;

	i = 0;
	d->t_start = get_time();
	while (i < d->p_nbr)
	{
		d->t_id = i;
		if (pthread_create(&d->p[i].t, NULL, routine, (void *)d) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < d->p_nbr)
	{
		if (pthread_join(&d->p[i].t, NULL) != 0)
			return ;
		i++;
	}
	
}

int	main(int ac, char *av[])
{
	t_data	d;
	
	if (ac != 5 && ac != 6)
	{
		printf("%s\n", ARGS);
		return (1);
	}
	init_data(ac, av, &d);
	init_philo(&d);
	launch_thread(&d);
	return (0);
}