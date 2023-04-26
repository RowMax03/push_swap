/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:53:30 by mreidenb          #+#    #+#             */
/*   Updated: 2023/04/26 17:05:09 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

static int	quick_select(int arr[], int low, int high, int k)
{
	int	index;

	if (k > 0 && k <= high - low + 1)
	{
		index = partition(arr, low, high);
		if (index - low == k - 1)
			return (arr[index]);
		if (index - low > k - 1)
			return (quick_select(arr, low, index - 1, k));
		return (quick_select(arr, index + 1, high, k - index + low - 1));
	}
	return (-1);
}

int	find_median(int arr[], int n)
{
	return (quick_select(arr, 0, n - 1, n / 2));
}

