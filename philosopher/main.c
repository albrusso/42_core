/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:14:26 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/13 15:32:43 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	launch_thread(t_data *d)
{
	int	i;

	i = 0;
	d->t_start = get_time();
	while (i < d->p_nbr)
	{
		if (pthread_create(&d->p[i].t, NULL, routine, (void *)&d->p[i]) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < d->p_nbr)
	{
		if (pthread_join(d->p[i].t, NULL) != 0)
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