/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 01:02:58 by yihssan           #+#    #+#             */
/*   Updated: 2020/10/16 23:30:53 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*a;

	a = malloc(size * count);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, (size * count));
	return (a);
}
