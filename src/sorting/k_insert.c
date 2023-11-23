/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_insert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:41:58 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/23 18:56:46 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int num)
{
	int	res;

	res = 0;
	while (res * res < num)
		res++;
	return (res);
}

void	k_sort(t_stacks *s)
{
	int	range;
	int	i;

	i = 1;
	range = ft_sqrt(s->na) * 14 / 10;
	ft_printf("");
	while (s->na)
	{
		if (s->a[0] <= i)
		{
			pb(s);
			rb(s);
			i++;
		}
		else if (s->a[0] <= i + range)
		{
			pb(s);
			i++;
		}
		else
			ra(s);
	}
	quick_sort(s);
}

void	k_sort_range(t_stacks *s, int bot, int top, int na)
{
	int	range;
	int	i;

	i = 1;
	range = ft_sqrt(na) * 16 / 10;
	while (s->na && i <= top - bot + 1)
	{
		if (s->a[0] <= i + bot)
		{
			pb(s);
			rb(s);
			i++;
		}
		else if (s->a[0] <= i + bot + range)
		{
			pb(s);
			i++;
		}
		else
			ra(s);
	}
}
