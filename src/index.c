/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:32:15 by mreidenb          #+#    #+#             */
/*   Updated: 2023/04/24 16:33:41 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_smaller(int value, int *temp, int size)
{
	int	i;
	int	amount;

	amount = 0;
	i = 0;
	while (i < size)
	{
		if (value > temp[i])
			amount++;
		i++;
	}
	return (amount);
}

void	change_to_index(t_stacks *s)
{
	int		*temp;
	int		i;

	temp = ft_calloc(s->na, sizeof(int));
	i = 0;
	while (i < s->na)
	{
		temp[i] = s->a[i];
		i++;
	}
	i = 0;
	while (i < s->na)
	{
		s->a[i] = count_smaller(s->a[i], temp, s->na);
		i++;
	}
	free(temp);
}
