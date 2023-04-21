/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 09:28:41 by mreidenb          #+#    #+#             */
/*   Updated: 2023/04/21 14:31:32 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//sorting for a stack of 3 2op max
void	sort_3(t_stacks *s)
{
	if (s->a[0] > s->a[2] && s->a[2] > s->a[1])
		return (ra(s->a, s->na));
	if (s->a[0] > s->a[2] && s->a[2] < s->a[1])
		return (rra(s->a, s->na));
	if (s->a[0] < s->a[2] && s->a[2] > s->a[1])
		return (sa(s->a, s->na));
	sa(s->a, s->na);
	sort_3(s);
}

void	sort_5(t_stacks *s)
{
	pb(s->a, s->b, s->na, s->nb);
	pb(s->a, s->b, s->na, s->nb);
	sort_3(s);
	if(s->a[])
}
