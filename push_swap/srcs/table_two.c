/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:34:54 by albrusso          #+#    #+#             */
/*   Updated: 2023/04/06 13:05:23 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_plus_a(t_value *a, t_value *b, t_stack *lst_b)
{
	while (lst_b->move_a > 0)
	{
		lst_b->move_a = lst_b->move_a - 1;
		ra(a, 1);
	}
	while (lst_b->move_b < 0)
	{
		lst_b->move_b = lst_b->move_b + 1;
		rrb(b, 1);
	}
	pa(a, b, 1);
}

void	ft_plus_b(t_value *a, t_value *b, t_stack *lst_b)
{
	while (lst_b->move_a < 0)
	{
		lst_b->move_a = lst_b->move_a + 1;
		rra(a, 1);
	}
	while (lst_b->move_b > 0)
	{
		lst_b->move_b = lst_b->move_b - 1;
		rb(b, 1);
	}
	pa(a, b, 1);
}

int	ft_find_lis(t_value *b)
{
	int		top;
	int		n;
	int		ret;
	t_stack	*lst_b;

	n = 1000000;
	lst_b = b->lst;
	top = 1000;
	ret = ft_find_lis_two(b, lst_b, n, top);
	return (ret);
}

void	ft_sort(t_value *a, t_value *b, int number)
{
	t_stack	*lst_b;

	lst_b = b->lst;
	while (lst_b->content != number)
		lst_b = lst_b->next;
	if (lst_b->move_a >= 0 && lst_b->move_b >= 0)
		ft_plus_concorde(a, b, lst_b);
	else if (lst_b->move_a < 0 && lst_b->move_b < 0)
		ft_minus_concorde(a, b, lst_b);
	else if (lst_b->move_a >= 0 && lst_b->move_b < 0)
		ft_plus_a(a, b, lst_b);
	else if (lst_b->move_a < 0 && lst_b->move_b >= 0)
		ft_plus_b(a, b, lst_b);
}

void	ft_refresh(t_value *a, t_value *b)
{
	ft_tofirst(b);
	ft_set_fora(a, b);
}
