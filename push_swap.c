/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:42:21 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/11 03:07:15 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	ft_is_sorted_a(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->na - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_smallest(int *s, int n)
{
	int	i;
	int	min;

	min = 2147483647;
	i = 0;
	while (i < n)
	{
		if (s[i] < min)
		{
			min = s[i];
		}
		i++;
	}
	return (min);
}

int	ft_biggest(int *b, int n)
{
	int	i;
	int	max;

	i = 0;
	max = -2147483648;
	while (i < n)
	{
		if (b[i] > max)
		{
			max = b[i];
		}
		i++;
	}
	return (max);
}

static void	algo_select(t_stacks *s)
{
	if (!ft_is_sorted_a(s))
	{
		if (s->na <= 3)
			sort_3(s);
		else if (s->na <= 5)
			sort_5(s);
		else
			make_ranges(s);
	}
	return ;
}

int	main(int argc, char **argv)
{
	int			*a;
	int			*b;
	int			na;
	int			nb;
	t_stacks	*s;

	argv++;
	argv = rm_space(argv, 0, 0);
	if (input_check(argv))
		return (ft_putstr_fd("Error\n", 2), free_str_array(argv), -1);
	a = malloc(sizeof(int) * (arg_count(argv) + 1));
	b = malloc(sizeof(int) * (arg_count(argv) + 1));
	if (!a || !b)
		return (ft_putstr_fd("Error\n", 2), free(a), free(b), -1);
	na = -1;
	nb = argc - argc;
	while ((++na) < arg_count(argv))
		a[na] = ft_atoi_l(argv[na]);
	free_str_array(argv);
	if (check_duplicates(a, na))
		return (ft_putstr_fd("Error\n", 2), free(a), free(b), -1);
	s = init_stacks(a, b, na, nb);
	change_to_index(s);
	algo_select(s);
	return (free(a), free(b), free(s), 0);
}
