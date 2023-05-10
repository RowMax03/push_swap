/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_wap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:28:43 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/10 18:01:50 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_count(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	*alloc_a(char **argv)
{
	int	*a;

	a = malloc(sizeof(int) * (arg_count(argv) + 1));
	return (a);
}

int	*alloc_b(char **argv)
{
	int	*b;

	b = malloc(sizeof(int) * (arg_count(argv) + 1));
	return (b);
}

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
