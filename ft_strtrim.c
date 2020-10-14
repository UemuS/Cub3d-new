/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:10:55 by yihssan           #+#    #+#             */
/*   Updated: 2020/03/11 22:25:40 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	ft_check(const char c, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i++])
			return (1);
	}
	return (0);
}

char		*ft_strtrim(char *s1, const char *set)
{
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (ft_check(s1[i], set))
		i += 1;
	if (!s1[i])
		return (ft_calloc(1, 1));
	j = ft_strlen(s1) - 1;
	while (ft_check(s1[j], set))
		j -= 1;
	return (ft_substr(s1, i, j - i + 1));
}
