/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:28:19 by mreidenb          #+#    #+#             */
/*   Updated: 2023/01/25 16:36:42 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quickSort(t_stacks s, int low, int high)
{
	int	pivotIndex;
	int	pivot;
	int	i;

	if (low < high)
	{
		// choose pivot
		pivotIndex = (low + high) / 2;
		pivot = s.a[pivotIndex];
		// move pivot to end of stack A
		while (pivotIndex < high)
		{
			pb(s.a, s.b, &(s.na), &(s.nb));
			ra(s.a, s.na);
			pivotIndex++;
		}
		// partition stack A
		i = low;
		for (int j = low; j < high; j++)
		{
			if (s.a[j] < pivot)
			{
				// move element to stack B
				pa(s.a, s.b, &(s.na), &(s.nb));
				i++;
			}
			else
			{
				// move element to end of stack A
				pb(s.a, s.b, &(s.na), &(s.nb));
				ra(s.a, s.na);
			}
		}
		// move pivot from stack B to stack A
		while (s.b[0] != pivot)
		{
			pb(s.a, s.b, &(s.na), &(s.nb));
		}
		pa(s.a, s.b, &(s.na), &(s.nb));
		// move all elements from stack B to stack A
		while (s.nb > 0)
		{
			pb(s.a, s.b, &(s.na), &(s.nb));
		}
		// recursive call on left and right partitions
		quickSort(s, low, i - 1);
		quickSort(s, i + 1, high);
	}
}
