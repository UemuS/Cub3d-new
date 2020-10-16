/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 02:49:29 by hmahjour          #+#    #+#             */
/*   Updated: 2020/10/16 17:51:22 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

double	ft_fmod(double a, double b)
{
	return (a - (floor(a/b) * b));
}

double ft_fabs(double a)
{
	return	((a >= 0) ? a : -a);
}

double	normalangle(double *rayangle)
{
	*rayangle = fmod(*rayangle, (2 * M_PI));
	if (*rayangle < 0)
		*rayangle = (2 * M_PI) + *rayangle;
	return (*rayangle);
}

int		iswall(double x, double y, t_mapdata *map)
{
	int mapy = floor(y / (double)32);
	int mapx = floor(x / (double)32);
	if (mapx >= 0 && mapx < g_case && mapy >=0 && mapy < g_rows)
		return ((MAP2D[mapy][mapx] == '1') || (MAP2D[mapy][mapx] == 'S'));
	return (0);
}

void	rayfacing(double rayangle)
{
	
	g_raydown = ((rayangle > 0) && (rayangle < M_PI));
	g_rayup = !g_raydown;
	g_rayright = ((rayangle < M_PI_2) || (rayangle > (1.5 * M_PI)));
	g_rayleft = !g_rayright;
}

int		inwin(double x, double y, t_mapdata *map)
{
	return (((x >= 0) && (x <= WH)) || ((y >= 0) && (y <= HT)));
}

double	hinter(t_mapdata *map, double rayangle)
{
	double ax;
	double ay;
	double xstep;
	double ystep;
	int h = 0;
	
	ay = floor(PY / 32) * 32 + (32 * g_raydown);
	ax = PX + ((ay - PY) / tan(rayangle));
	ystep = 32 * (g_rayup ? -1 : 1);
	xstep = 32 / tan(rayangle);
	xstep *= (g_rayleft && (xstep > 0)) ? -1 : 1;
	xstep *= (g_rayright && (xstep < 0)) ? -1 : 1;
	if (g_rayup)
		h++;
	while (inwin(ax, ay - h, map) && !iswall(ax, ay - h, map))
	{
		ax += xstep;
		ay += ystep;
	}
	g_wallhx = ax;
	g_wallhy = ay;
	return (sqrtf((ay - PY) * (ay - PY) + (ax - PX) * (ax - PX)));
}

double	vinter(t_mapdata *map, double rayangle)
{
	double ax;
	double ay;
	double xstep;
	double ystep;
	int hu = 0;

	ax = floor(PX / 32) * 32 + (32 * g_rayright);
	ay = PY + ((ax - PX) * tan(rayangle));
	xstep = 32 * (g_rayleft ? -1 : 1);
	ystep = 32 * tan(rayangle);
	ystep *= (g_rayup && (ystep > 0)) ? -1 : 1;
	ystep *= (g_raydown && (ystep < 0)) ? -1 : 1;
	if (g_rayleft)
		hu++;
	while (inwin(ax - hu, ay, map) && !iswall(ax - hu, ay, map))
	{
		ax += xstep;
		ay += ystep;
	}
	g_wallvx = ax;
	g_wallvy = ay;
	return (sqrtf((ay - PY) * (ay - PY) + (ax - PX) * (ax - PX)));
}

void	initwallxy()
{
	g_wallx = 0;
	g_wally = 0;
	g_wallvx = 0;
	g_wallvy = 0;
	g_wallhx = 0;
	g_wallhy = 0;
	g_hith = 0;
	g_hitv = 0;
}

double	colmdist(t_mapdata *map, double rayangle)
{
	double dist;
	double hdist = 0;
	double vdist = 0;
	
	initwallxy();
	normalangle(&rayangle);
	rayfacing(rayangle);
	hdist = hinter(map, rayangle);
	vdist = vinter(map, rayangle);
	if (hdist < vdist)
	{
		g_wallx = g_wallhx;
		g_wally = g_wallhy;
		dist = hdist;
		g_hith = 1;
	}
	else
	{
		g_wallx = g_wallvx;
		g_wally = g_wallvy;
		dist = vdist;
		g_hitv = 1; 
	}
	return (dist);
}