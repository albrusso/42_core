/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:21:58 by albrusso          #+#    #+#             */
/*   Updated: 2023/04/18 16:20:28 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_add_lst(t_value *a, t_value *b, char *argv[], int k)
{
	int	i;

	if (k == 1)
		i = 1;
	else
		i = 2;
	a->lst = ft_lstnew(ft_atoi(argv[i - 1]));
	b->lst = NULL;
	while (i < a->ac)
	{
		ft_lstadd_back(&a->lst, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}	
}

int	ft_read_rules(char *rules, t_value *a, t_value *b)
{
	while (1)
	{
		rules = get_next_line(0);
		if (rules == NULL)
		{
			free(rules);
			break ;
		}
		if (ft_execute_rules(rules, a, b) != 0)
			free (rules);
		else
		{
			write(1, "Erroreee\n", 8);
			free(rules);
			rules = NULL;
			a->lst = ft_free_bonus(a->lst);
			b->lst = ft_free_bonus(b->lst);
			exit (1);
		}
	}
	return (1);
}

t_stack	*ft_free_bonus(t_stack *lst)
{
	t_stack	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
	lst = NULL;
	return (lst);
}

void	ft_main_bonus(t_value *a, t_value *b, char *argv[], int k)
{
	char	*rules;

	rules = NULL;
	ft_add_lst(a, b, argv, k);
	ft_read_rules(rules, a, b);
	if (ft_isorder(&a->lst) == 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char *argv[])
{
	t_value	a;
	t_value	b;
	int		k;

	k = 0;
	if (argc == 2 && ft_strlen(argv[1]) != 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_new_argc(argv);
		k = 1;
	}
	if (argc < 2)
		ft_close(k, argv);
	a.ac = argc;
	if (ft_check_num(a.ac, argv) == 0)
	{
		write(1, "Error\n", 7);
		return (0);
	}
	else
		ft_main_bonus(&a, &b, argv, k);
	a.lst = ft_free_bonus(a.lst);
	return (0);
}
