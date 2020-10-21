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
	wallh = (TILE_SIZE / dist) * prjplane;
	return (wallh);
}

int		colmcolor(int textureOffsetX, int i, int wall, int height)
{
	int		textureOffsetY;
	int		distanceFromTop;

	distanceFromTop = i + (wall / 2) - (height / 2);
	textureOffsetY = distanceFromTop * ((float)TILE_SIZE / wall);
	if (g_rayup && g_hith)
		return (g_texture_buffer_NO[textureOffsetX + (textureOffsetY * TILE_SIZE)]);
	if (g_rayleft && g_hitv)
		return (g_texture_buffer_EA[textureOffsetX + (textureOffsetY * TILE_SIZE)]);
	if (g_raydown && g_hith)
		return (g_texture_buffer_SO[textureOffsetX + (textureOffsetY * TILE_SIZE)]);
	if (g_rayright && g_hitv)
		return (g_texture_buffer_WE[textureOffsetX + (textureOffsetY * TILE_SIZE)]);
	return (0);
}

void	drawcolm(int col, double wallh, t_mapdata *map)
{
	int i;
	int	j;
	int k;
	int wall;
	int	textX;

	k = -1;
	wall = (int)wallh;
	i = ((HT / 2) - (wall / 2)) < 0 ? 0 : ((HT / 2) - (wall / 2));
	j = ((HT / 2) + (wall / 2)) > HT ? HT : ((HT / 2) + (wall / 2));
	if (g_hith == 1)
		textX = (int)g_wallx % TILE_SIZE;
	else
		textX = (int)g_wally % TILE_SIZE;
	while (k++ < i)
			g_img_data[k * WH + col] = g_CL;
	while (i < j)
	{
		if (i >=0 && i < HT && col >= 0 && col < WH)
			g_img_data[i * WH + col] = colmcolor(textX, i, wall, HT);
		i++;
	}
	while (++j < HT)
			g_img_data[j * WH + col] = g_FL;
}

void	castrays(t_mapdata *map)
{
	int		col;
	double	rayangle;
	double	wallh;
	double	an;;
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
	if (g_checksave == 0)
	{
		g_checksave = 1;
		save_bmp(map);
	}
}