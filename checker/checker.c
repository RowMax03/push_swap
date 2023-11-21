/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:56:06 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/21 17:28:19 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	do_operations(t_stacks *s, char *operation)
{
	if (!operation)
		return (0);
	if (!ft_strncmp(operation, "sa", 2))
		b_sa(s);
	else if (!ft_strncmp(operation, "sb", 2))
		b_sb(s);
	else if (!ft_strncmp(operation, "ss", 2))
		b_ss(s);
	else if (!ft_strncmp(operation, "pa", 2))
		b_pa(s);
	else if (!ft_strncmp(operation, "pb", 2))
		b_pb(s);
	else if (!ft_strncmp(operation, "ra", 2))
		b_ra(s);
	else if (!ft_strncmp(operation, "rb", 2))
		b_rb(s);
	else if (!ft_strncmp(operation, "rrr", 3))
		b_rrr(s);
	else if (!ft_strncmp(operation, "rra", 3))
		b_rra(s);
	else if (!ft_strncmp(operation, "rrb", 3))
		b_rrb(s);
	else if (!ft_strncmp(operation, "rr", 2))
		b_rr(s);
	return (free(operation), 1);
}

static int	checker(t_stacks *s)
{
	int		i;

	while (do_operations(s, get_next_line(0)))
		;
	i = 0;
	while (i < s->na - 1)
	{
		if (s->a[i] > s->a[i + 1])
		{
			ft_printf("KO\n");
			exit(0);
		}
		i++;
	}
	ft_printf("OK\n");
	exit(0);
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
	if (input_check(argv) || argc < 2)
		return (ft_putstr_fd("Error\n", 2), -1);
	a = malloc(sizeof(int) * (arg_count(argv) + 1));
	b = malloc(sizeof(int) * (arg_count(argv) + 1));
	if (!a || !b)
		return (ft_putstr_fd("Error\n", 2), free(a), free(b), -1);
	na = -1;
	nb = 0;
	while ((++na) < arg_count(argv))
		a[na] = ft_atoi_l(argv[na]);
	if (check_duplicates(a, na) || arg_count(argv) < 2)
		return (ft_putstr_fd("Error\n", 2), free(a), free(b), -1);
	s = init_stacks(a, b, na, nb);
	change_to_index(s);
	checker(s);
	return (free(a), free(b), free(s), 0);
}

void	b_rrr(t_stacks *s)
{
	b_rra(s);
	b_rrb(s);
}
