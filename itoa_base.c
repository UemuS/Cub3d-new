/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:39:19 by yihssan           #+#    #+#             */
/*   Updated: 2020/02/24 09:34:25 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	nlen_base(long long n, int base)
{
	int i;

	i = 1;
	while ((n = n / base))
		i++;
	return (i);
}

static char	*ft_add_zero(char *s)
{
	char	*str;
	char	c;

	if (ft_strlen(s) < 2)
	{
		c = s[0];
		str = malloc(3);
		str[0] = '0';
		str[1] = c;
		str[2] = 0;
		return (str);
	}
	return (s);
}

char		*itoa_base(long long n, char *base)
{
	char		*s;
	int			len;
	long long	num;
	int			b;

	b = ft_strlen(base);
	len = nlen_base(n, b);
	num = n;
	if (n < 0)
		len++;
	if (!(s = malloc((sizeof(char) * len + 1))))
		return (NULL);
	s[len--] = '\0';
	while (len >= 0)
	{
		s[len] = ((n % b) < 0) ? base[-n % b] : base[n % b];
		n = n / b;
		len--;
	}
	if (num < 0)
		s[0] = '-';
	s = ft_add_zero(s);
	return (s);
}
