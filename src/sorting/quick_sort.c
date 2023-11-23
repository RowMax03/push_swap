/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:28:19 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/23 18:57:57 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_ranges(t_stacks *s)
{
	int	num_stacks;
	int	*stacks;
	int	i;

	i = 1;
	if (s->na < 20)
		num_stacks = 1;
	else if (s->na <= 100)
		num_stacks = s->na / 20;
	else
		num_stacks = s->na / 75 + 5;
	stacks = malloc(sizeof(int) * (num_stacks + 1));
	stacks[0] = 0;
	while (i <= num_stacks)
	{
		stacks[i] = (s->na / num_stacks) * i - 1;
		i++;
	}
	stacks[num_stacks] = s->na - 1;
	insertion_sort(s, stacks, num_stacks);
}

void	insertion_sort(t_stacks *s, int *stacks, int num_stacks)
{
	int	i;
	int	tmp;
	int	na;

	i = 0;
	na = s->na;
	while (i < num_stacks && s->na)
	{
		while (1)
		{
			tmp = num_getter_range(s, stacks[i], stacks[i + 1]);
			if (s->na && tmp == s->a[0])
				pb(s);
			else
				break ;
		}
		k_sort_range(s, stacks[i], stacks[i + 1], na);
		i++;
	}
	quick_sort(s);
}

void	quick_sort(t_stacks *s)
{
	int	pivot;

	pivot = s->nb - 1;
	while (s->nb >= 1)
	{
		if (s->b[0] == pivot)
		{
			pa(s);
			pivot--;
		}
		else
			rotation_decide_b(s, pivot);
	}
}
