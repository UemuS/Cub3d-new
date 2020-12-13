/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:10:22 by yihssan           #+#    #+#             */
/*   Updated: 2020/12/13 04:14:43 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_helpdrawasquare(t_mpdt *map)
{
	ft_drawall(map);
	ft_draw_player(map);
}

double	wallheight(double rayangle, t_mpdt *map, int col)
{
	double prjplane;
	double wallh;
	double dist;

	g_hit_side = (g_hith) ? 1 : 0;
	dist = colmdist(map, rayangle) * cos(rayangle - RT);
	RAYDIST[col] = colmdist(map, rayangle);
	prjplane = (WH / 2) / tan(M_PI / 6);
	wallh = (TL_SZE / dist) * prjplane;
	return (wallh);
}

int		colmcolor(int textx, int i, int wall, t_mpdt *map)
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

void	drawcolm(int col, double wallh, t_mpdt *map)
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
		textx = (fmod(WALLX, TL_SZE) * (check_vision_wh(map) / TL_SZE));
	else
		textx = (fmod(WALLY, TL_SZE) * (check_vision_wh(map) / TL_SZE));
	while (k++ < i)
		g_img_data[k * WH + col] = g_cl;
	while (i <= j && i < HT)
	{
		if (i >= 0 && i < HT && col >= 0 && col < WH)
			g_img_data[i * WH + col] = colmcolor(textx, i, wall, map);
		i++;
	}
	while (++j < HT)
		g_img_data[j * WH + col] = g_fl;
}

void	castrays(t_mpdt *map)
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
	to_sprite(map, -1);
	if (g_checksave == 1)
	{
		save_bmp(map);
		ft_quit();
	}
}
