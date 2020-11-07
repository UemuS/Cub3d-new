/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 02:49:29 by hmahjour          #+#    #+#             */
/*   Updated: 2020/11/07 01:49:38 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		iswall(double x, double y, t_mpdt *map)
{
	int		mapy;
	int		mapx;
	double	dis;

	mapy = floor(y / (double)TL_SZE);
	mapx = floor(x / (double)TL_SZE);
	dis = ((y - PY) * (y - PY) + (x - PX) * (x - PX));
	if (mapx >= 0 && mapx < g_case && mapy >= 0 && mapy < g_rows)
	{
		if (MAP2D[mapy][mapx] == '3' && dis < 64)
			MAP2D[mapy][mapx] = '0';
		if (MAP2D[mapy][mapx] == '1' || MAP2D[mapy][mapx] == '3')
			return (1);
	}
	return (0);
}

int		inwin(double x, double y)
{
	float h;
	float k;

	h = g_case * TL_SZE;
	k = g_rows * TL_SZE;
	return (((x >= 0) && (x <= h)) && ((y >= 0) && (y <= k)));
}

double	hinter(t_mpdt *map, double rayangle)
{
	double	ax;
	double	ay;
	double	xstep;
	double	ystep;

	ay = floor(PY / TL_SZE) * TL_SZE + (g_raydown ? TL_SZE : 0.001);
	ax = PX + ((ay - PY) / tan(rayangle));
	ystep = TL_SZE * (g_rayup ? -1 : 1);
	xstep = TL_SZE / tan(rayangle);
	xstep *= (g_rayleft && xstep > 0) || (g_rayright && xstep < 0) ? -1 : 1;
	while (inwin(ax, ay))
	{
		if (iswall(ax, ay - ((g_rayup) ? 1 : 0), map) == 1)
		{
			WALLHX = ax;
			WALLHY = ay;
			break ;
		}
		else
		{
			ax += xstep;
			ay += ystep;
		}
	}
	return (sqrtf((ay - PY) * (ay - PY) + (ax - PX) * (ax - PX)));
}

double	vinter(t_mpdt *map, double rayangle)
{
	double	ax;
	double	ay;
	double	xstep;
	double	ystep;

	ax = floor(PX / TL_SZE) * TL_SZE + (g_rayright ? TL_SZE : 0.001);
	ay = PY + ((ax - PX) * tan(rayangle));
	xstep = TL_SZE * (g_rayleft ? -1 : 1);
	ystep = TL_SZE * tan(rayangle);
	ystep *= (g_rayup && (ystep > 0)) || (g_raydown && (ystep < 0)) ? -1 : 1;
	while (inwin(ax, ay))
	{
		if (iswall(ax - (g_rayleft ? 1 : 0), ay, map) == 1)
		{
			WALLVX = ax;
			WALLVY = ay;
			break ;
		}
		else
		{
			ax += xstep;
			ay += ystep;
		}
	}
	return (sqrtf((ay - PY) * (ay - PY) + (ax - PX) * (ax - PX)));
}

double	colmdist(t_mpdt *map, double rayangle)
{
	double dist;
	double hdist;
	double vdist;

	initwallxy(map);
	normalangle(&rayangle);
	rayfacing(rayangle);
	hdist = hinter(map, rayangle);
	vdist = vinter(map, rayangle);
	if (hdist < vdist)
	{
		WALLX = WALLHX;
		WALLY = WALLHY;
		dist = hdist;
		g_hith = 1;
	}
	else
	{
		WALLX = WALLVX;
		WALLY = WALLVY;
		dist = vdist;
		g_hitv = 1;
	}
	return (dist);
}
