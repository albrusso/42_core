/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:23:20 by albrusso          #+#    #+#             */
/*   Updated: 2023/03/31 14:12:53 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_five_numbers_sort(t_value *a, t_value *b, int count, t_stack *lst_b)
{
	int	i;

	i = 0;
	ft_three_numbers(a, count);
	while (i < 2)
	{
		lst_b = b->lst;
		ft_refresh(a, b);
		ft_sort(a, b, lst_b->content);
		i++;
	}
	ft_fixlst(a);
}

void	ft_fixlst(t_value *a)
{
	int	k;
	int	lstsize_a;

	a->min = ft_find_min(a->lst);
	k = ft_lst_findposition(a->lst, a->min);
	lstsize_a = ft_lstsize(a->lst);
	if (k >= lstsize_a / 2)
		k = k - lstsize_a;
	if (k > 0)
	{
		while (k > 0)
		{
			ra(a, 1);
			k--;
		}
	}
	else if (k < 0)
	{
		while (k < 0)
		{
			rra(a, 1);
			k++;
		}
	}
}
