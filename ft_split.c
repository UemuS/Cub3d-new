/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:33:46 by yihssan           #+#    #+#             */
/*   Updated: 2020/11/30 12:31:17 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int			count_words(const char *str, char c)
{
	int i;
	int count;
	int words;

	i = 0;
	count = 0;
	words = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			words = 0;
		else if (words == 0)
		{
			words = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	**ft_frees(char **w, int j)
{
	while (--j)
		free(w[j]);
	free(w);
	return (0);
}

int			ft_useless(char const *s, int c, int i)
{
	while (s[i] == c)
		i++;
	return (i);
}

char		**ft_split(char const *s, char c, t_mpdt *map)
{
	char	**w;
	int		i;
	int		k;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (!(w = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (0);
	while (s[i] != '\0' && j < count_words(s, c))
	{
		k = 0;
		i = ft_useless(s, c, i);
		if (!(w[j] = (char*)malloc(sizeof(char) * ft_longest_array(map))))
			return (ft_frees(w, j));
		while (s[i] != '\0' && s[i] != c)
			w[j][k++] = s[i++];
		while (k < g_case)
			w[j][k++] = '1';
		w[j++][k] = '\0';
	}
	w[j] = 0;
	return (w);
}

int			ft_longest_array(t_mpdt *map)
{
	int	i;
	int	j;
	int length;

	i = -1;
	length = 0;
	while (MAP0[++i] != 0)
	{
		j = 0;
		while (MAP0[i + j] != '\n')
			j++;
		if (length < j)
			length = j;
	}
	return (length);
}
