/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_wap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:42:21 by mreidenb          #+#    #+#             */
/*   Updated: 2023/01/25 16:31:38 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/*
** push_swap.c
** 42 School Style
*/

#include "push_swap.h"

int	ft_is_sorted(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
			return (0);
	}
	return (1);
}

int	ft_smallest(int *a, int n)
{
	int	i;
	int	j;
	int	pos;
	int	min;

	min = 2147483647;
	for (i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			pos = i;
		}
	}
	return (pos);
}

int	ft_biggest(int *b, int n)
{
	int	i;
	int	j;
	int	pos;
	int	max;

	max = -2147483648;
	for (i = 0; i < n; i++)
	{
		if (b[i] > max)
		{
			max = b[i];
			pos = i;
		}
	}
	return (pos);
}

void	push_swap(int *a, int *b, int na, int nb)
{
	int i, j;
	while (!ft_is_sorted(a, na))
	{
		i = ft_smallest(a, na);
		if (i > na / 2)
		{
			while (i--)
				rra(a, na--);
			pb(a, b, &na, &nb);
		}
		else
		{
			while (i--)
				ra(a, na--);
			pb(a, b, &na, &nb);
		}
	}
	while (nb)
	{
		i = ft_biggest(b, nb);
		while (i--)
			pa(a, b, &na, &nb);
	}
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	na;
	int	nb;
	int	i;

	i = 1;
	a = malloc(sizeof(int) * argc);
	b = malloc(sizeof(int) * argc);
	if (!a || !b)
		return (free(a), free(b), -1);
	if (argc < 2)
		return (0);
	na = 0;
	nb = 0;
	while (i++)
		a[na++] = atoi(argv[i]);
	push_swap(a, b, na, nb);
	return (0);
}
