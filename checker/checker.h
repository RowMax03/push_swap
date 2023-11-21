/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:06:29 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/21 00:58:33 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../includes/libft/libft.h"
# include "../includes/get_next_line/get_next_line.h"
# include "../push_swap.h"

void	b_pa(t_stacks *s);
void	b_pb(t_stacks *s);
void	b_ra(t_stacks *s);
void	b_rb(t_stacks *s);
void	b_rr(t_stacks *s);
void	b_rra(t_stacks *s);
void	b_rrb(t_stacks *s);
void	b_rrr(t_stacks *s);
void	b_sa(t_stacks *s);
void	b_sb(t_stacks *s);
void	b_ss(t_stacks *s);

#endif