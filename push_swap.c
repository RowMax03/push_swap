/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:42:21 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/23 18:59:33 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

#define MAX_SIZE 100

static void	algo_select(t_stacks *s)
{
	if (s->na <= 3)
		sort_3(s);
	else if (s->na <= 5)
		sort_5(s);
	else
		make_ranges(s);
}

int	main(int argc, char **argv)
{
	int			*a;
	int			*b;
	int			na;
	int			nb;
	t_stacks	*s;

	argv++;
	argv = rm_space(argv, 0, 0);
	if (input_check(argv))
		return (ft_putstr_fd("Error\n", 2), free_str_array(argv), -1);
	a = malloc(sizeof(int) * (arg_count(argv) + 1));
	b = malloc(sizeof(int) * (arg_count(argv) + 1));
	if (!a || !b)
		return (ft_putstr_fd("Error\n", 2), free(a), free(b), -1);
	na = -1;
	nb = argc - argc;
	while ((++na) < arg_count(argv))
		a[na] = ft_atoi_l(argv[na]);
	free_str_array(argv);
	if (check_duplicates(a, na))
		return (ft_putstr_fd("Error\n", 2), free(a), free(b), -1);
	s = init_stacks(a, b, na, nb);
	change_to_index(s);
	algo_select(s);
	return (free(a), free(b), free(s), 0);
}
