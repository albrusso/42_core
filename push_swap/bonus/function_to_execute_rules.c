/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_to_execute_rules.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:10:12 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/11 15:41:15 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_execute_rules_help(char *rules, t_value *a, t_value *b)
{
	if (ft_strcmp(rules, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(rules, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(rules, "ss\n") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(rules, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(rules, "pb\n") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(rules, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(rules, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(rules, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(rules, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(rules, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(rules, "rrr\n") == 0)
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_execute_rules(char *rules, t_value *a, t_value *b)
{
	int	i;

	i = -1;
	i = ft_execute_rules_help(rules, a, b);
	return (i);
}
