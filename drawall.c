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

double	wallheight(double rayangle, t_mapdata *map, int col)
{
	double prjplane;
	double wallh;
	double dist;

	g_hit_side = (g_hith) ? 1 : 0;
	dist = colmdist(map, rayangle) * cos(rayangle - RT);
	RAYDIST[col] = dist;
	prjplane = (WH / 2) / tan(M_PI / 6);
	wallh = (T_SIZE / dist) * prjplane;
	return (wallh);
}

int		colmcolor(int textx, int i, int wall, t_mapdata *map)
{
	int		texty;
	int		disttop;

	disttop = i + (wall / 2) - (HT / 2);
	texty = (disttop - JPINCR - JMPINCR) *
		((float)check_vision_ht(map) / wall);
	if (g_rayup && g_hith)
		return (TXT_BUF_NO[textx + (texty * TXT_WH_NO)]);
	if (g_rayleft && g_hitv)
		return (TXT_BUF_EA[textx + (texty * TXT_WH_EA)]);
	if (g_raydown && g_hith)
		return (TXT_BUF_SO[textx + (texty * TXT_WH_SO)]);
	if (g_rayright && g_hitv)
		return (TXT_BUF_WE[textx + (texty * TXT_WH_WE)]);
	return (0);
}

void	drawcolm(int col, double wallh, t_mapdata *map)
{
	int i;
	int	j;
	int k;
	int wall;
	int	textx;

	k = -1;
	wall = (int)wallh;
	i = ((HT / 2) - (wall / 2)) + JPINCR + JMPINCR;
	j = ((HT / 2) + (wall / 2)) + JPINCR + JMPINCR;
	if (g_hith == 1)
		textx = (ft_fmod(WALLX, T_SIZE) * (check_vision_wh(map) / T_SIZE));
	else
		textx = (ft_fmod(WALLY, T_SIZE) * (check_vision_wh(map) / T_SIZE));
	while (k++ < i)
		g_img_data[k * WH + col] = g_CL;
	while (i <= j && i < HT)
	{
		if (i >= 0 && i < HT && col >= 0 && col < WH)
			g_img_data[i * WH + col] = colmcolor(textx, i, wall, map);
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
		wallh = wallheight(rayangle, map, col);
		drawcolm(col, wallh, map);
		rayangle += (M_PI / 3) / WH;
		col++;
	}
	if (g_checksave == 0)
	{
		g_checksave = 1;
		save_bmp(map);
	}
	init_spt(map);
	to_sprite(map, -1);
}
