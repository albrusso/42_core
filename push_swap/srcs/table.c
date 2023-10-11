/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:37:32 by albrusso          #+#    #+#             */
/*   Updated: 2023/04/06 13:05:00 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_lis_two(t_value *b, t_stack *lst_b, int n, int top)
{
	int	ret;
	int	i;

	i = 0;
	while (i < ft_lstsize(b->lst) && lst_b)
	{
		if ((lst_b->move_a >= 0 && lst_b->move_b >= 0)
			|| (lst_b->move_a < 0 && lst_b->move_b < 0))
			n = ft_concorde(lst_b, n);
		if ((lst_b->move_a < 0 && lst_b->move_b >= 0)
			|| (lst_b->move_a >= 0 && lst_b->move_b < 0))
			n = ft_discorde(lst_b);
		if (n < top)
		{
			top = n;
			ret = lst_b->content;
		}
		if (top == 0)
			break ;
		lst_b = lst_b->next;
		i++;
	}
	return (ret);
}

void	ft_plus_concorde_two(t_value *a, t_value *b, t_stack *lst_b)
{
	while (lst_b->move_b > 0 && lst_b->move_a > 0)
	{
		lst_b->move_a = lst_b->move_a - 1;
		lst_b->move_b = lst_b->move_b - 1;
		rr(a, b, 1);
	}
	while (lst_b->move_a > 0)
	{
		lst_b->move_a = lst_b->move_a - 1;
		ra(a, 1);
	}
	pa(a, b, 1);
}

void	ft_plus_concorde_three(t_value *a, t_value*b, t_stack *lst_b)
{
	while (lst_b->move_a > 0 && lst_b->move_b > 0)
	{
		lst_b->move_a = lst_b->move_a - 1;
		lst_b->move_b = lst_b->move_b - 1;
		rr(a, b, 1);
	}
	while (lst_b->move_b > 0)
	{
		lst_b->move_b = lst_b->move_b - 1;
		rb(b, 1);
	}
	pa(a, b, 1);
}

void	ft_minus_concorde_two(t_value *a, t_value *b, t_stack *lst_b)
{
	while (lst_b->move_a < 0 && lst_b->move_b < 0)
	{
		lst_b->move_a = lst_b->move_a + 1;
		lst_b->move_b = lst_b->move_b + 1;
		rrr(a, b, 1);
	}
	while (lst_b->move_b < 0)
	{
		lst_b->move_b = lst_b->move_b + 1;
		rrb(b, 1);
	}
	pa(a, b, 1);
}
