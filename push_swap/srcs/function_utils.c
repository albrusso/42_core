/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:28:56 by albrusso          #+#    #+#             */
/*   Updated: 2023/04/19 14:46:37 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_num_two(long int *a, char *av[], int ac)
{
	int	k;
	int	j;

	j = 1;
	while (j < ac)
	{
		k = 0;
		if (ft_check_alpha(av[j]) == 0 || (ft_atoi(av[j]) < -2147483648
				|| ft_atoi(av[j]) > 2147483647))
			return (0);
		if (j == 1)
			a[0] = ft_atoi(av[j]);
		else
		{
			while (k < j - 1)
			{
				if (a[k] == ft_atoi(av[j]))
					return (0);
				k++;
			}
			a[j - 1] = ft_atoi(av[j]);
		}
		j++;
	}
	return (1);
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	result = 0;
	i = 0;
	sign = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (sign == -1 || str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (5646456468);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_check_num(int ac, char *av[])
{
	int			i;
	long int	*a;

	a = (long int *)malloc(sizeof(long int) * (ac - 1));
	i = ft_check_num_two(a, av, ac);
	free(a);
	return (i);
}

int	ft_find_min(t_stack *lst)
{
	t_stack	*temp;
	int		min;

	temp = lst;
	min = lst->content;
	temp = temp->next;
	while (temp != NULL)
	{
		if (temp->content < min)
			min = temp->content;
		else
			temp = temp->next;
	}
	return (min);
}

int	ft_find_max(t_stack *lst)
{
	t_stack	*temp;
	int		max;

	temp = lst;
	max = lst->content;
	temp = temp->next;
	while (temp != NULL)
	{
		if (temp->content > max)
			max = temp->content;
		else
			temp = temp->next;
	}
	return (max);
}
