/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:12:41 by mreidenb          #+#    #+#             */
/*   Updated: 2023/04/28 16:16:01 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_stacks *s)
{
	int	temp;

	if (s->na >= 2)
	{
		temp = s->a[0];
		s->a[0] = s->a[1];
		s->a[1] = temp;
	}
	ft_printf("sa\n");
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
	ft_printf("sb\n");
}

void	ss(t_stacks *s)
{
	sa(s);
	sb(s);
}

void	pa(t_stacks *s)
{
	int	i;

	i = s->na - 1;
	if (s->nb >= 1)
	{
		while (i >= 0)
		{
			s->a[i + 1] = s->a[i];
			i--;
		}
		s->na++;
		s->a[0] = s->b[0];
		s->nb--;
		i = 0;
		while (i < s->nb)
		{
			s->b[i] = s->b[i + 1];
			i++;
		}
	}
	ft_printf("pa\n");
}

void	pb(t_stacks *s)
{
	int	i;

	i = s->nb - 1;
	if (s->na >= 1)
	{
		while (i >= 0)
		{
			s->b[i + 1] = s->b[i];
			i--;
		}
		s->nb++;
		s->b[0] = s->a[0];
		s->na--;
		i = 0;
		while (i < s->na)
		{
			s->a[i] = s->a[i + 1];
			i++;
		}
	}
	ft_printf("pb\n");
}
