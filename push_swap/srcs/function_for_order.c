/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_for_order.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:35:38 by albrusso          #+#    #+#             */
/*   Updated: 2023/04/18 17:47:28 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ft(t_value *a)
{
	t_stack	*lst;

	lst = a->lst;
	a->min = ft_find_min(lst);
	a->max = ft_find_max(lst);
	while (lst)
	{
		lst->to_push = 0;
		lst->move_a = 0;
		lst->move_b = 0;
		lst = lst->next;
	}
}

int	ft_two_nbr(t_value *a)
{
	if (ft_isorder(&a->lst) == 0)
		sa(a, 1);
	return (0);
}

int	ft_three_numbers(t_value *a, int count)
{
	t_stack	*temp;

	temp = a->lst;
	a->min = ft_find_min(temp);
	a->max = ft_find_max(temp);
	ft_sorted_sequence(a);
	while (ft_isorder(&a->lst) == 0)
	{
		if ((a->lst->content == a->min && a->lst->next->content == a->max)
			|| ((a->lst->content != a->min && a->lst->content != a->max)
				&& (a->lst->next->content == a->max)))
			rra(a, 1);
		if ((a->lst->content == a->max && a->lst->next->content == a->min)
			|| (a->lst->content == a->max && a->lst->next->content != a->min))
			ra(a, 1);
		if ((a->lst->content != a->min && a->lst->content != a->min)
			&& (a->lst->next->content == a->min))
			sa(a, 1);
		count++;
	}
	return (count);
}

int	ft_five_numbers(t_value *a, t_value *b)
{
	t_stack	*lst_b;
	int		i;

	i = 0;
	if (ft_isorder(&a->lst) == 1)
		return (0);
	if (a->ac == 5)
		pb(a, b, 1);
	else
	{
		pb(a, b, 1);
		pb(a, b, 1);
	}
	i++;
	lst_b = b->lst;
	i = 0;
	ft_five_numbers_sort(a, b, 0, lst_b);
	return (0);
}

int	ft_onehundred_numbers(t_value *a, t_value *b)
{
	int		i;
	int		lstsize;

	ft_ft(a);
	i = ft_sorted_sequence(a);
	ft_set_topush(a, i);
	ft_add_tob(a, b);
	lstsize = ft_lstsize(b->lst);
	i = 0;
	while (lstsize > 0)
	{
		ft_refresh(a, b);
		i = ft_find_lis(b);
		ft_sort(a, b, i);
		lstsize--;
	}
	ft_fixlst(a);
	return (0);
}
