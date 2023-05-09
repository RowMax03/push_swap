/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:28:19 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/03 18:43:53 by mreidenb         ###   ########.fr       */
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
	int	j;
	int tmp;

	i = 0;
	while (i < num_stacks && s->na)
	{
		j = 0;
		while (j < stacks[i + 1] - stacks[i] + 1 && s->na)
		{
			tmp = num_getter_range(s, stacks[i], stacks[i + 1]);
			rotation_decide(s, tmp);
			rotation_decide_b(s, closest_high(s->b, s->nb, tmp));
			pb(s);
			j++;
		}
		i++;
	}
	quickSort(s);
}


void	quickSort(t_stacks *s)
{
	int	pivot;
	int	i;

	pivot = s->nb - 1;
	i = 0;
	while (s->nb != 0)
	{
		if (s->b[0] == pivot)
		{
			pa(s);
			pivot--;
		}
		else
			rotation_decide_b(s, pivot);
	}
	//printf(" A size: %d\n",s->na);
	//printf(" B size: %d\n",s->nb);
	//printf(" A size: %d\n",s->na);
	//printf(" B size: %d\n",s->nb);
}
