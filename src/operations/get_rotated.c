/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotated.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:22:38 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/23 18:31:52 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *s)
{
	int	temp;
	int	i;

	i = 0;
	temp = s->a[0];
	while (i < s->na)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[s->na - 1] = temp;
	ft_printf("ra\n");
}

void	rb(t_stacks *s)
{
	int	temp;
	int	i;

	i = 0;
	temp = s->b[0];
	while (i < s->nb)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[s->nb - 1] = temp;
	ft_printf("rb\n");
}

void	rr(t_stacks *s)
{
	ra(s);
	rb(s);
}

void	rra(t_stacks *s)
{
	int	temp;
	int	i;

	i = s->na - 2;
	temp = s->a[s->na - 1];
	while (i >= 0)
	{
		s->a[i + 1] = s->a[i];
		i--;
	}
	s->a[0] = temp;
	ft_printf("rra\n");
}

void	rrb(t_stacks *s)
{
	int	temp;
	int	i;

	i = s->nb - 2;
	temp = s->b[s->nb - 1];
	while (i >= 0)
	{
		s->b[i + 1] = s->b[i];
		i--;
	}
	s->b[0] = temp;
	ft_printf("rrb\n");
}
