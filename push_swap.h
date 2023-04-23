/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:48:36 by mreidenb          #+#    #+#             */
/*   Updated: 2023/04/23 16:28:01 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct t_stacks {
	int	*a;
	int	*b;
	int	na;
	int	nb;
}t_stacks;

void		sa(t_stacks *s);
void		sb(t_stacks *s);
void		ss(t_stacks *s);
void		pa(t_stacks *s);
void		pb(t_stacks *s);
void		ra(t_stacks *s);
void		rb(t_stacks *s);
void		rr(t_stacks *s);
void		rra(t_stacks *s);
void		rrb(t_stacks *s);
void		rrr(t_stacks *s);
void		push_swap(t_stacks *s);
int			ft_is_sorted(t_stacks *s);
int			ft_smallest(t_stacks *s);
int			ft_biggest(t_stacks *s);
int			find_median(int arr[], int n);
t_stacks	init_stacks(int *a, int *b, int na, int nb);

#endif
