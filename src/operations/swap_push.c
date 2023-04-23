/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:12:41 by mreidenb          #+#    #+#             */
/*   Updated: 2023/04/23 16:26:05 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *s)
{
	int	temp;

	if (s->na >= 2)
	{
		temp = s->a[0];
		s->a[0] = s->a[1];
		s->a[1] = temp;
	}
}

void	sb(t_stacks *s)
{
	int	temp;

	if (s->nb >= 2)
	{
		temp = s->b[0];
		s->b[0] = s->b[1];
		s->b[1] = temp;
	}
}

void	ss(t_stacks *s)
{
	sa(s);
	sb(s);
}

void	pa(t_stacks *s)
{
	int	i;

	i = 0;
	if (s->nb >= 1)
	{
		s->a[0] = s->b[0];
		(s->na)++;
		(s->nb)--;
		while (i < s->nb)
		{
			s->b[i] = s->b[i + 1];
			i++;
		}
	}
}

void	pb(t_stacks *s)
{
	int	i;

	i = 0;
	if (s->na >= 1)
	{
		s->b[0] = s->a[0];
		(s->nb)++;
		(s->na)--;
		while (i < s->na)
		{
			s->a[i] = s->a[i + 1];
			i++;
		}
	}
}
