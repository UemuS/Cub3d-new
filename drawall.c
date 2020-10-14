/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:10:22 by yihssan           #+#    #+#             */
/*   Updated: 2020/10/14 17:07:07 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void    ft_drawsquare(int y, int x, int color, t_mapdata *map)
{
    int i;
    int j;

    i = 0;
    j = 0;

	while (j < (32))
	{
		i = 0;
		while (i < (32))
		{
			g_img_data[(y * (32) + j) * WH + (x * (32) + i)] = color;
			i++;
		}
		j++;
	}
}