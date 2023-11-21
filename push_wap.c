/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_wap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:28:43 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/11 00:18:31 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	wordcount(const char *s, char c)
{
	int		i;
	int		wrd;

	wrd = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && wrd == 0)
		{
			wrd = 1;
			i++;
		}
		if (*s == c)
			wrd = 0;
		s++;
	}
	return (i);
}

char	**rm_space(char **argv, int i, int count)
{
	int		j;
	int		pos;
	char	**result;
	char	**temp;

	count = 0;
	i = 0;
	while (argv[i])
		count += wordcount(argv[i++], ' ');
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == NULL)
		return (NULL);
	result[count] = NULL;
	pos = 0;
	i = 0;
	while (argv[i])
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while (temp[j])
			result[pos++] = temp[j++];
		free(temp);
		i++;
	}
	return (result);
}





int	arg_count(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

t_stacks	*init_stacks(int *a, int *b, int na, int nb)
{
	t_stacks	*s;

	s = malloc(sizeof(t_stacks));
	s->a = a;
	s->b = b;
	s->na = na;
	s->nb = nb;
	return (s);
}
