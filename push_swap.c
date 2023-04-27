/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:42:21 by mreidenb          #+#    #+#             */
/*   Updated: 2023/04/27 18:41:41 by mreidenb         ###   ########.fr       */
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

int	ft_smallest(t_stacks *s)
{
	int	i;
	int	pos;
	int	min;

	min = 2147483647;
	i = 0;
	while (i < s->na)
	{
		if (s->a[i] < min)
		{
			min = s->a[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

// int	ft_biggest(int *b, int n)
// {
// 	int	i;
// 	int	j;
// 	int	pos;
// 	int	max;

// 	max = -2147483648;
// 	for (i = 0; i < n; i++)
// 	{
// 		if (b[i] > max)
// 		{
// 			max = b[i];
// 			pos = i;
// 		}
// 	}
// 	return (pos);
// }

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

int	main(int argc, char **argv)
{
	int			*a;
	int			*b;
	int			na;
	int			nb;
	int			i;
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
	i = 0;
	while (i < s->na)
		{printf("Stack in the Beginning: Index: %d Number: %d\n",i ,s->a[i]); i++;}
	printf("%d\n", s->na);
	quickSort(s);
	pb(s);
	pb(s);
	i = 0;
	while (i < s->na)
		{printf("Stack in the End: Index: %d Number: %d\n",i ,s->a[i]); i++;}
	printf("%d\n", s->na);
	return (0);
}
