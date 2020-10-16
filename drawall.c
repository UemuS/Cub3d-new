/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:10:22 by yihssan           #+#    #+#             */
/*   Updated: 2020/10/16 04:12:21 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void    ft_drawsquare(int y, int x, int color, t_mapdata *map)
{
    int i;
    int j;

    i = 0;
    j = 0;

	while (j < (HT/g_rows))
	{
		i = 0;
		while (i < (WH/g_case))
		{
			g_img_data[(y * (HT/g_rows) + j) * WH + (x * (WH/g_case) + i)] = color;
			i++;
		}
		j++;
	}
}

void 	fline(double rayangle, double raylength, t_mapdata *map)
{
	int i;
	
	i = 0;
	while(i <= raylength)
	{
		//printf("%f %f %d %f %f\n", PX, PY, WH, rayangle, raylength);
		g_img_data[(int)(PY + sin(rayangle) * i) * WH + (int)(PX + cos(rayangle) * i)] = 0xaff469;
		i++;
	} 
}


void	cast2drays(t_mapdata *map)
{
	int	col;
	double rayangle;

	rayangle = RT - (M_PI / 6);
	col = 0;
	while (col < WH)
	{
		drawray(map, rayangle);
		rayangle += (M_PI / 3) / WH;
		col++;
	}
}

void	drawray(t_mapdata *map, double angle)
{
	double raylength;
	
	
	raylength = colmdist(map, angle);
	/*raylength = 60;
	line(PX, PY, PX + (cos(angle) * raylength), PY + (sin(angle) * raylength), map);
	printf("%lf %lf\n", PX, PY);
	line(PX, PY, g_wallx, g_wally, map);*/
	fline(angle, raylength, map); /*best result in 2D*/
}