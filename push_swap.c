/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:42:21 by mreidenb          #+#    #+#             */
/*   Updated: 2023/04/29 19:04:18 by mreidenb         ###   ########.fr       */
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
		quickSort(s);
}

int	main(int argc, char **argv)
{
	int			*a;
	int			*b;
	int			na;
	int			nb;
	//int			i;
	t_stacks	*s;

	s = malloc(sizeof(t_stacks));
	a = malloc(sizeof(int) * argc);
	b = malloc(sizeof(int) * argc);
	if (!a || !b)
		return (free(a), free(b), -1);
	if (argc < 2)
		return (0);
	na = 0;
	nb = 0;
	while ((na + 1) < argc)
	{
		a[na] = atoi(argv[na + 1]);
		na++;
	}
	s = init_stacks(a, b, na, nb);
	change_to_index(s);
	//i = 0;
	//while (i < s->na)
	//	{printf("Stack in the Beginning: Index: %d Number: %d\n",i ,s->a[i]); i++;}
	//printf("%d\n", s->na);
	algo_select(s);
	//i = 0;
	//while (i < s->na)
	//	{printf("Stack in the End: Index: %d Number: %d\n",i ,s->a[i]); i++;}
	//printf("%d\n", s->na);
	return (0);
}
