/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keta_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:41:58 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/21 20:51:26 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_sqrt(int num)
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
	int i;

	i = 1;
	range = ft_sqrt(s->na) * 14 / 10;
	ft_printf("");
	while (s->na)
	{
		// ft_printf("s index: %d\n", s->a[0]);
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

