/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_wap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:28:43 by mreidenb          #+#    #+#             */
/*   Updated: 2023/04/26 17:02:47 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*init_stacks(int *a, int *b, int na, int nb)
{
	t_stacks	*s;

	s = malloc(sizeof(t_stacks));
	s->a = a;
	s->b = b;
	s->na = na;
	s->nb = nb;
	return (s);
}
