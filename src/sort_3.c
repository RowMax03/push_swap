/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 09:28:41 by mreidenb          #+#    #+#             */
/*   Updated: 2023/04/23 16:33:49 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//sorting for a stack of 3 2op max
void	sort_3(t_stacks *s)
{
	if (s->a[0] > s->a[2] && s->a[2] > s->a[1])
		return (ra(s));
	if (s->a[0] > s->a[2] && s->a[2] < s->a[1])
		return (rra(s));
	if (s->a[0] < s->a[2] && s->a[2] > s->a[1])
		return (sa(s));
	sa(s);
	sort_3(s);
}

void	sort_5(t_stacks *s)
{
	pb(s);
	pb(s);
	sort_3(s);
	if (s->a[0] > s->b[0] && s->b[0] > s->b[1])
		return (pa(s), pb(s));
	else if (s->a[0] > s->b[0] && s->b[0] < s->b[1])
		return (sb(s), pa(s), pb(s));
}
