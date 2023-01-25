/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotated.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:22:38 by mreidenb          #+#    #+#             */
/*   Updated: 2023/01/25 14:31:17 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ra(int *a, int n)
{
	int	temp;
	int	i;

	i = 1;
	temp = a[0];
	while (i < n)
	{
		a[i - 1] = a[i];
		i++;
	}
	a[n - 1] = temp;
}

void	rb(int *b, int n)
{
	int	temp;
	int	i;

	i = 1;
	temp = b[0];
	while (i < n)
	{
		b[i - 1] = b[i];
		i++;
	}
	b[n - 1] = temp;
}

void	rr(int *a, int *b, int na, int nb)
{
	ra(a, na);
	rb(b, nb);
}

void	rra(int *a, int n)
{
	int	temp;
	int	i;

	i = n - 2;
	temp = a[n - 1];
	while (i >= 0)
	{
		a[i + 1] = a[i];
		i--;
	}
	a[0] = temp;
}

void	rrb(int *b, int n)
{
	int	temp;
	int	i;

	i = n - 2;
	temp = b[n - 1];
	while (i >= 0)
	{
		b[i + 1] = b[i];
		i--;
	}
	b[0] = temp;
}

void	rrr(int *a, int *b, int na, int nb)
{
	rra(a, na);
	rrb(b, nb);
}