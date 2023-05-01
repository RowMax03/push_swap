/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:48:36 by mreidenb          #+#    #+#             */
/*   Updated: 2023/04/29 18:54:03 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
//#include "./includes/libft/libft.h"

typedef struct t_stacks {
	int	*a;
	int	*b;
	int	na;
	int	nb;
}t_stacks;

int			main(int argc, char **argv);
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
void		sort_3(t_stacks *s);
void		sort_5(t_stacks *s);
void		rotation_decide(t_stacks *s, int num);
int			ft_is_sorted_a(t_stacks *s);
int			ft_smallest(int *s, int n);
int			ft_biggest(int *b, int n);
int			find_median(int arr[], int n);
t_stacks	*init_stacks(int *a, int *b, int na, int nb);
void		change_to_index(t_stacks *s);
void		quickSort(t_stacks *s);
int			partition(t_stacks *s, int low, int high);
int			get_index(int *arr, int size, int num);
void 		swap(t_stacks *s, int i, int j);


#endif
