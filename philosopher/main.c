/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:48:34 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/11 16:35:02 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char *av[])
{
	t_data	*data;

	if (ac != 5 && ac != 6)
	{
		printf("Error: args will be ./pihlo [nbr_of_philo] [time_to_die] ");
		printf("[time_to_eat] [time_to_sleep] ([nbr_of_repeat])\n");
		return (0);
	}
	data = init_data(ac, av);
	return (0);
}