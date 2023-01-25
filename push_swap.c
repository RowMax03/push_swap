/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:28:43 by mreidenb          #+#    #+#             */
/*   Updated: 2023/01/25 16:29:59 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	init_stacks(int *a, int *b, int na, int nb)
{
	t_stacks	s;

	s.a = a;
	s.b = b;
	s.na = na;
	s.nb = nb;
	return (s);
}
