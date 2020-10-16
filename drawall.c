/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:10:22 by yihssan           #+#    #+#             */
/*   Updated: 2020/10/16 17:57:09 by yihssan          ###   ########.fr       */
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
		return (0x555555);
	if (g_rayleft && g_hitv)
		return (0x222222);
	if (g_raydown && g_hith)
		return (0xcccccc);
	if (g_rayright && g_hitv)
		return (0x999999);
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