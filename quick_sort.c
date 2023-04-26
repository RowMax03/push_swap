/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:28:19 by mreidenb          #+#    #+#             */
/*   Updated: 2023/04/26 20:10:00 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	quickSort(t_stacks *s, int low, int high)
// {
// 	int	pivotIndex;
// 	int	pivot;
// 	int	i;
// 	int	j;

// 	if (low < high)
// 	{
// 		// choose pivot
// 		pivotIndex = (low + high) / 2;
// 		pivot = s->a[pivotIndex];
// 		// move pivot to end of stack A
// 		while (pivotIndex < high)
// 		{
// 			pb(s);
// 			ra(s);
// 			pivotIndex++;
// 		}
// 		// partition stack A
// 		i = low;
// 		j = low;
// 		while (j++ < high)
// 		{
// 			if (s->a[j] < pivot)
// 			{
// 				// move element to stack B
// 				pb(s);
// 				i++;
// 			}
// 			else
// 			{
// 				// move element to end of stack A
// 				pb(s);
// 				ra(s);
// 			}
// 		}
// 		// move pivot from stack B to stack A
// 		while (s->b[0] != pivot)
// 		{
// 			pa(s);
// 		}
// 		pa(s);
// 		// move all elements from stack B to stack A
// 		while (s->nb > 0)
// 		{
// 			pa(s);
// 		}
// 		// recursive call on left and right partitions
// 		quickSort(s, low, i - 1);
// 		quickSort(s, i + 1, high);
// 	}
// }

void quickSort(t_stacks *s, int low, int high) {
  if (low >= high) return;
  
  int pivotIndex = partition(s, low, high);
  quickSort(s, low, pivotIndex - 1);
  quickSort(s, pivotIndex + 1, high);
}

int partition(t_stacks *s, int low, int high) {
  int pivotIndex = (low + high) / 2;
  int pivot = s->a[pivotIndex];
  printf("partition: pivotIndex Beginning= %d\n", pivotIndex);
  // Move pivot to top of stack A
  while (pivotIndex > 0) {
    if (pivotIndex <= (low + high) / 2) {
      ra(s);
    } else {
      rra(s);
    }
    pivotIndex--;
  }

  // Partition stack A
  int i = low - 1;
  for (int j = low; j <= high; j++) {
    if (s->a[j] <= pivot) {
      i++;
      if (i != j) {
        swap(s, i, j);
        if (j == pivotIndex) pivotIndex = i;
        else if (i == pivotIndex) pivotIndex = j;
      }
    }
  }

  // Move pivot to correct position
  while (pivotIndex < high) {
    if (pivotIndex <= (low + high) / 2) {
      ra(s);
    } else {
      rra(s);
    }
    pivotIndex++;
  }
  	i = 0;
	while (i < s->na)
		{printf("Stack A at the End of Partition: Index: %d Number: %d\n",i ,s->a[i]); i++;}
  	i = 0;
	while (i < s->nb)
		{printf("Stack B at the End of Partition: Index: %d Number: %d\n",i ,s->b[i]); i++;}
  printf("partition: returning pivotIndex=%d\n", pivotIndex);
  return pivotIndex;
}

void swap(t_stacks *s, int i, int j) {
  if (j - i == 1) {
    sa(s);
  } else {
    while (i > 0) {
      ra(s);
      i--;
      j--;
    }
    pb(s);
    while (j > 0) {
      rb(s);
      j--;
    }
    pa(s);
    while (s->b[s->nb - 1] != s->a[i]) {
      ra(s);
    }
    if (s->a[i + 1] < s->a[i]) {
      sa(s);
    }
  }
}
