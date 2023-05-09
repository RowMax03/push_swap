/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:42:21 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/09 18:20:06 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

#define MAX_SIZE 100

/*
** push_swap.c
** 42 School Style
*/

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

// void	push_swap(int *a, int *b, int na, int nb)
// {
// 	int i, j;

// 	while (!ft_is_sorted(a, na))
// 	{
// 		i = ft_smallest(a, na);
// 		if (i > na / 2)
// 		{
// 			while (i--)
// 				rra(a, na--);
// 			pb(a, b, &na, &nb);
// 		}
// 		else
// 		{
// 			while (i--)
// 				ra(a, na--);
// 			pb(a, b, &na, &nb);
// 		}
// 	}
// 	while (nb)
// 	{
// 		i = ft_biggest(b, nb);
// 		while (i--)
// 			pa(a, b, &na, &nb);
// 	}
// }
static void	algo_select(t_stacks *s)
{
	if (s->na <= 3)
		sort_3(s);
	else if (s->na <= 5)
		sort_5(s);
	else
		make_ranges(s);
}

int	main(int argc, char **argv)
{
	int			*a;
	int			*b;
	int			na;
	int			nb;
	t_stacks	*s;

	if (argv++ && argc == 2)
		argv = ft_split(argv[0], ' ');
	if (input_check(argv))
	{
		ft_printf("Error\n");
		return (-1);
	}
	a = malloc(sizeof(int) * argc);
	b = malloc(sizeof(int) * argc);
	if (!a || !b)
		return (free(a), free(b), -1);
	na = 0;
	nb = 0;
	while ((na + 1) < argc)
	{
		a[na] = atoi(argv[na]);
		na++;
	}
	if (check_duplicates(a, na))
	{
		ft_printf("Error\n");
		return (free(a), free(b), -1);
	}
	s = init_stacks(a, b, na, nb);
	change_to_index(s);
	algo_select(s);
	return (free(a), free(b), free(s), 0);
}
