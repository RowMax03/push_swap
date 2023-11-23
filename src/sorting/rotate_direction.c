/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:57:04 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/23 18:31:45 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	closest_high(int *s, int n, int num)
{
	int	i;
	int	closest_high;

	i = 0;
	closest_high = ft_biggest(s, n);
	if (num > closest_high)
		return (-1);
	while (i < n)
	{
		if (s[i] > num && s[i] < closest_high)
			closest_high = s[i];
		i++;
	}
	return (closest_high);
}

int	num_getter_range(t_stacks *s, int low, int high)
{
	int	top;
	int	bot;

	top = 0;
	bot = s->na - 1;
	while (top < s->na)
	{
		if (s->a[top] >= low && s->a[top] <= high)
			break ;
		top++;
	}
	while (bot >= 0)
	{
		if (s->a[bot] >= low && s->a[bot] <= high)
			break ;
		bot--;
	}
	if (s->na - bot > top)
		return (s->a[top]);
	return (s->a[bot]);
}

void	rotation_decide(t_stacks *s, int num)
{
	int	i;

	i = 0;
	if (num == -1)
		return ;
	while (num != s->a[i])
		i++;
	if (i <= s->na / 2)
	{
		while (i)
		{
			ra(s);
			i--;
		}
	}
	else
	{
		while (s->na - i)
		{
			rra(s);
			i++;
		}
	}
}

void	rotation_decide_b(t_stacks *s, int num)
{
	int	i;

	i = 0;
	if (s->nb && s->b[0] == num)
	{
		pa(s);
		return ;
	}
	if (num == -1)
		return ;
	while (num != s->b[i])
		i++;
	if (i == 0)
		return ;
	if (i <= s->nb / 2)
	{
		while (i-- >= 1)
			rb(s);
	}
	else
	{
		while (s->nb - i++ >= 1)
			rrb(s);
	}
}
