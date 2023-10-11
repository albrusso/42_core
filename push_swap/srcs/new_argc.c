/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_argc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:45:53 by albrusso          #+#    #+#             */
/*   Updated: 2023/04/19 14:59:50 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_new_argc(char *av[])
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void	ft_close(int k, char *argv[])
{
	if (ft_check_alpha(argv[1 - k]) == 0)
		write(1, "Error\n", 6);
	if (k == 1)
		ft_second_free(argv);
	exit (0);
}

int	ft_is_digit(char *av[], int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
