/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:48:36 by mreidenb          #+#    #+#             */
/*   Updated: 2023/01/25 16:27:31 by mreidenb         ###   ########.fr       */
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

void	sa(int *a, int n);
void	sb(int *b, int n);
void	ss(int *a, int *b, int na, int nb);
void	pa(int *a, int *b, int *na, int *nb);
void	pb(int *a, int *b, int *na, int *nb);
void	ra(int *a, int n);
void	rb(int *b, int n);
void	rr(int *a, int *b, int na, int nb);
void	rra(int *a, int n);
void	rrb(int *b, int n);
void	rrr(int *a, int *b, int na, int nb);
void	push_swap(int *a, int *b, int na, int nb);
int		ft_is_sorted(int *a, int n);
int		ft_smallest(int *a, int n);
int		ft_biggest(int *b, int n);
int		find_median(int arr[], int n);

#endif
