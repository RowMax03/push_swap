/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:12:41 by mreidenb          #+#    #+#             */
/*   Updated: 2023/01/25 15:46:44 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a, int n)
{
	int	temp;

	if (n >= 2)
	{
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
	}
}

void	sb(int *b, int n)
{
	int	temp;

	if (n >= 2)
	{
		temp = b[0];
		b[0] = b[1];
		b[1] = temp;
	}
}

void	ss(int *a, int *b, int na, int nb)
{
	sa(a, na);
	sb(b, nb);
}

void	pa(int *a, int *b, int *na, int *nb)
{
	int	i;

	i = 0;
	if (*nb >= 1)
	{
		a[*na] = b[0];
		(*na)++;
		(*nb)--;
		while (i < *nb)
		{
			b[i] = b[i + 1];
			i++;
		}
	}
}

void	pb(int *a, int *b, int *na, int *nb)
{
	int	i;

	i = 0;
	if (*na >= 1)
	{
		b[*nb] = a[0];
		(*nb)++;
		(*na)--;
		while (i < *na)
		{
			a[i] = a[i + 1];
			i++;
		}
	}
}
