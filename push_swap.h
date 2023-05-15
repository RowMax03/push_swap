/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:48:36 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/11 02:44:37 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./includes/libft/libft.h"

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
void		sort_3(t_stacks *s);
void		sort_5(t_stacks *s);
void		rotation_decide(t_stacks *s, int num);
void		rotation_decide_b(t_stacks *s, int num);
void		make_ranges(t_stacks *s);
void		insertion_sort(t_stacks *s, int *stacks, int num_stacks);
int			ft_is_sorted_a(t_stacks *s);
int			ft_smallest(int *s, int n);
int			ft_biggest(int *b, int n);
int			find_median(int arr[], int n);
t_stacks	*init_stacks(int *a, int *b, int na, int nb);
void		change_to_index(t_stacks *s);
int			partition(t_stacks *s, int low, int high);
int			get_index(int *arr, int size, int num);
void		swap(t_stacks *s, int i, int j);
int			num_getter_range(t_stacks *s, int low, int high);
int			closest_high(int *s, int n, int num);
int			input_check(char **argv);
int			check_duplicates(int *s, int n);
int			*alloc_a(char **argv);
int			*alloc_b(char **argv);
int			arg_count(char **argv);
char		**rm_space(char **argv, int i, int count);
void		free_str_array(char **array);

#endif
