/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:10:22 by yihssan           #+#    #+#             */
/*   Updated: 2020/10/16 05:49:00 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

double	wallheight(double rayangle, t_mapdata *map)
{
	double prjplane;
	double wallh;
	double dist;

	g_hit_side = (g_hith) ? 1 : 0;
	dist = colmdist(map, rayangle) * cos(rayangle - RT);
	prjplane = (WH / 2) / tan(M_PI / 6);
	wallh = (32 / dist) * prjplane;
	return (wallh);
}

int		colmcolor()
{
	if (g_rayup && g_hith)
		return (0x484D6D);
	if (g_rayleft && g_hitv)
		return (0x2B193D);
	if (g_raydown && g_hith)
		return (0xF5F5F5);
	if (g_rayright && g_hitv)
		return (0xFF5A5F);
	return (0);
}

void	drawcolm(int col, double wallh, t_mapdata *map)
{
	int i;
	int wall;

	wall = (int)wallh;
	i = (HT / 2) - (wall / 2);
	while (i < (HT / 2) + (wall / 2))
	{
		if (i >=0 && i < HT && col >= 0 && col < WH)
			g_img_data[i * WH + col] = colmcolor();
		i++;
	}
}

void	castrays(t_mapdata *map)
{
	int	col;
	double rayangle;
	double wallh;
	double an;
	
	
	rayangle = RT - (M_PI / 6);
	an = rayangle;
	col = 0;
	while (col < WH)
	{
		wallh = wallheight(rayangle, map);
		drawcolm(col, wallh, map);
		rayangle += (M_PI / 3) / WH;
		col++;
	}
}