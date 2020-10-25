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

int		check_vision_ht(t_mapdata *map)
{
	if (g_rayup && g_hith)
		return (TXT_HT_NO);
	if (g_rayleft && g_hitv)
		return (TXT_HT_EA);
	if (g_raydown && g_hith)
		return (TXT_HT_SO);
	if (g_rayright && g_hitv)
		return (TXT_HT_WE);
	return (0);
}

int		colmcolor(int textX, int i, int wall, int jpi, int jmpi, t_mapdata *map)
{
	int		textureOffsetY;
	int		distanceFromTop;

	distanceFromTop = i + (wall / 2) - (HT / 2);
	textureOffsetY = (distanceFromTop - jpi - jmpi) * ((float)check_vision_ht(map) / wall);
	if (g_rayup && g_hith)
		return (TXT_BUF_NO[textX + (textureOffsetY * TXT_WH_NO)]);
	if (g_rayleft && g_hitv)
		return (TXT_BUF_EA[textX + (textureOffsetY * TXT_WH_EA)]);
	if (g_raydown && g_hith)
		return (TXT_BUF_SO[textX + (textureOffsetY * TXT_WH_SO)]);
	if (g_rayright && g_hitv)
		return (TXT_BUF_WE[textX + (textureOffsetY * TXT_WH_WE)]);
	return (0);
}

int		check_vision_wh(t_mapdata *map)
{
	if (g_rayup && g_hith)
		return (TXT_WH_NO);
	if (g_rayleft && g_hitv)
		return (TXT_WH_EA);
	if (g_raydown && g_hith)
		return (TXT_WH_SO);
	if (g_rayright && g_hitv)
		return (TXT_WH_WE);
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
	i = ((HT / 2) - (wall / 2)) + JPINCR + JMPINCR;
	j = ((HT / 2) + (wall / 2)) + JPINCR + JMPINCR;
	if (g_hith == 1)
		textX = (ft_fmod(WALLX, TILE_SIZE) * (check_vision_wh(map) / TILE_SIZE));
	else
		textX = (ft_fmod(WALLY, TILE_SIZE) * (check_vision_wh(map) / TILE_SIZE));
	while (k++ < i)
			g_img_data[k * WH + col] = g_CL;
	while (i <= j && i < HT)
	{
		if (i >=0 && i < HT && col >= 0 && col < WH)
			g_img_data[i * WH + col] = colmcolor(textX, i, wall, JPINCR, JMPINCR, map);
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
	rayangle = RT - (M_PI / 6);
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