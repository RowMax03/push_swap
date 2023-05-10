/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:40:31 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/10 19:26:47 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "stdio.h"

static int	check_numbers(char **argv);
static int	check_if_int(char **argv);
static int	check_blanks(char **argv);

int	input_check(char **argv)
{
	if (!argv)
		return (-1);
	if (check_blanks(argv))
		return (-1);
	if (check_numbers(argv))
		return (-1);
	if (check_if_int(argv))
		return (-1);
	return (0);
}

static int	check_blanks(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (-1);
		i++;
	}
	return (0);
}

static int	check_numbers(char **argv)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (argv[i])
	{
		y = 0;
		while (argv[i] && argv[i][y])
		{
			if (!ft_isdigit(argv[i][y]) && (argv[i][y] != '-'
			|| argv[i][y] != '+') && !ft_isdigit(argv[i][y + 1]))
				return (-1);
			y++;
		}
		i++;
	}
	return (0);
}

static int	check_if_int(char **argv)
{
	int		i;
	long	max_int;
	long	min_int;

	i = 0;
	max_int = 2147483647;
	min_int = -2147483648;
	while (argv[i])
	{	
		if (ft_strlen(argv[i]) > 11)
			return (-1);
		if (ft_atoi_l(argv[i]) > max_int || ft_atoi_l(argv[i]) < min_int)
			return (-1);
		i++;
	}
	return (0);
}

int	check_duplicates(int *s, int n)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (x < n)
	{
		i = 0;
		while (i < n)
		{
			if (i != x && s[x]
				== s[i])
				return (-1);
			i++;
		}
		x++;
	}
	return (0);
}