/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 09:28:41 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/21 14:48:48 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

//sorting for a stack of 3 2op max
void	sort_3(t_stacks *s)
{
	if (!ft_is_sorted_a(s))
	{
		if (s->a[0] > s->a[2] && s->a[2] > s->a[1])
			return (ra(s));
		if (s->a[0] > s->a[2] && s->a[0] < s->a[1])
			return (rra(s));
		if (s->a[0] < s->a[2] && s->a[2] > s->a[1])
			return (sa(s));
		sa(s);
		sort_3(s);
	}
}

void	sort_5(t_stacks *s)
{
	int	i;

	i = 0;
	pb(s);
	pb(s);
	sort_3(s);
	if (s->a[0] > s->b[0] && s->b[0] > s->b[1])
		return (pa(s), pa(s));
	else if (s->a[0] > s->b[0] && s->b[0] < s->b[1] && s->a[0] > s->b[1])
		return (sb(s), pa(s), pa(s));
	if (s->b[0] < s->b[1])
		sb(s);
	while ((!ft_is_sorted_a(s) || s->nb != 0) && i < 8)
	{
		if (!(s->b[0] > s->a[s->na - 1]) && s->nb > 0)
			rotation_decide(s, s->b[0] + 1);
		if (s->nb > 0)
			pa(s);
		if (s->a[0] != s->b[0] + 1)
			rotation_decide(s, ft_smallest(s->a, s->na));
		i++;
	}
}
