/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:36:47 by albrusso          #+#    #+#             */
/*   Updated: 2023/04/04 17:47:26 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_minus_concorde_three(t_value *a, t_value *b, t_stack *lst_b)
{
	while (lst_b->move_b < 0 && lst_b->move_a < 0)
	{
		lst_b->move_a = lst_b->move_a + 1;
		lst_b->move_b = lst_b->move_b + 1;
		rrr(a, b, 1);
	}
	while (lst_b->move_a < 0)
	{
		lst_b->move_a = lst_b->move_a + 1;
		rra(a, 1);
	}
	pa(a, b, 1);
}

int	ft_concorde(t_stack *lst_b, int n)
{
	if (lst_b->move_a >= 0 && lst_b->move_b >= 0)
	{
		if (lst_b->move_a < lst_b->move_b)
			n = lst_b->move_b;
		if (lst_b->move_a >= lst_b->move_b)
			n = lst_b->move_a;
	}
	else
	{
		if (lst_b->move_a < lst_b->move_b)
			n = lst_b->move_a * (-1);
		if (lst_b->move_a > lst_b->move_b)
			n = lst_b->move_b * (-1);
	}
	return (n);
}

int	ft_discorde(t_stack *lst_b)
{
	int	n;

	if (lst_b->move_a < 0 && lst_b->move_b >= 0)
		n = (lst_b->move_a * (-1) + lst_b->move_b);
	if (lst_b->move_a >= 0 && lst_b->move_b < 0)
		n = (lst_b->move_b * (-1) + lst_b->move_a);
	return (n);
}

void	ft_plus_concorde(t_value *a, t_value *b, t_stack *lst_b)
{
	if (lst_b->move_a >= lst_b->move_b)
		ft_plus_concorde_two(a, b, lst_b);
	else if (lst_b->move_a <= lst_b->move_b)
		ft_plus_concorde_three(a, b, lst_b);
}

void	ft_minus_concorde(t_value *a, t_value *b, t_stack *lst_b)
{
	if (lst_b->move_a >= lst_b->move_b)
		ft_minus_concorde_two(a, b, lst_b);
	else if (lst_b->move_a < lst_b->move_b)
		ft_minus_concorde_three(a, b, lst_b);
}
