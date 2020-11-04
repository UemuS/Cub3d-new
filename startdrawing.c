/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:33:35 by yihssan           #+#    #+#             */
/*   Updated: 2020/11/04 18:47:11 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <math.h>

int    deal_key(int key, t_mapdata *map)
{
	if (key == 123)
		TD = -1;
	if (key == 124)
		TD = 1;
	if (key == 13)
		WD = 1;
	if (key == 0)
		SD = -1;
	if (key == 2)
		SD = 1;
	if (key == 1)
		WD = -1;
	if (key == 53)
		g_exit = 1;
	if (key == 126)
		JP = 1;
	if (key == 125)
		JP = -1;
	if (key == 49)
		JMP = 1;
	if (key == 5)
		DOOR = 1;
	return(0);
}
int    release_key(int key, t_mapdata *map)
{
	if (key == 123)
		TD = 0;
	if (key == 124)
		TD = 0;
	if (key == 13)
		WD = 0;
	if (key == 0)
		SD = 0;
	if (key == 2)
		SD = 0;
	if (key == 1)
		WD = 0;
	if (key == 126)
		JP = 0;
	if (key == 125)
		JP = 0;
	if (key == 49)
		JMP = 0;
	if (key == 5)
		DOOR = 0;
	return(0);
}

void	ft_drawall(t_mapdata *map)
{
	int x;
	int y;

	y = -1;

	while (MAP2D[++y])
	{
		x = -1;
		while (MAP2D[y][++x])
		{
			/*if (MAP2D[y][x] == '1')
			  ft_drawsquare(y, x, 0xffd015, map);
			  else
			  ft_drawsquare(y, x, 0x000000, map);*/
			if (MAP2D[y][x] != '0' && MAP2D[y][x] != '1')
				ft_check_stuff(y, x, map);
		}
	}
}

int     draw(t_mapdata *map)
{
	int	bpp;
	int	size_line;
	int	endian;
	int us;
	int ad;

	g_img_ptr = mlx_new_image(g_mlx_ptr, WH, HT);
	g_img_data = (int *)mlx_get_data_addr(g_img_ptr, &bpp, &size_line, &endian);
	XPM_NO = mlx_xpm_file_to_image(g_mlx_ptr, NO, &TXT_WH_NO, &TXT_HT_NO);
	XPM_SO = mlx_xpm_file_to_image(g_mlx_ptr, SO, &TXT_WH_SO, &TXT_HT_SO);
	XPM_EA = mlx_xpm_file_to_image(g_mlx_ptr, EA, &TXT_WH_EA, &TXT_HT_EA);
	XPM_WE = mlx_xpm_file_to_image(g_mlx_ptr, WE, &TXT_WH_WE, &TXT_HT_WE);
	XPM_VIS = mlx_xpm_file_to_image(g_mlx_ptr,  "texture/weapon.xpm", &us , &us);
	XPM_FL = mlx_xpm_file_to_image(g_mlx_ptr,  "texture/vis.xpm", &ad , &ad);
	TXT_BUF_NO = (int *)mlx_get_data_addr(XPM_NO, &bpp, &size_line, &endian);
	TXT_BUF_SO = (int *)mlx_get_data_addr(XPM_SO, &bpp, &size_line, &endian);
	TXT_BUF_EA = (int *)mlx_get_data_addr(XPM_EA, &bpp, &size_line, &endian);
	TXT_BUF_WE = (int *)mlx_get_data_addr(XPM_WE, &bpp, &size_line, &endian);
	TXT_BUF_VIS = (int *)mlx_get_data_addr(XPM_VIS, &bpp, &size_line, &endian);
	TXT_BUF_FL = (int *)mlx_get_data_addr(XPM_FL, &bpp, &size_line, &endian);
	ft_helpdrawasquare(map);
	mlx_put_image_to_window(g_mlx_ptr, g_mlx_win, g_img_ptr, 0, 0);
	mlx_put_image_to_window(g_mlx_ptr, g_mlx_win, XPM_VIS, WH/2, HT - 200);
	mlx_put_image_to_window(g_mlx_ptr, g_mlx_win, XPM_FL, WH/2 - 50, HT/2);
	mlx_destroy_image(g_mlx_ptr, g_img_ptr);
	if (g_exit == 1)
	{
		ft_error("");
		mlx_destroy_window (g_mlx_ptr, g_mlx_win);
	}

	return (0);
}

void	ft_draw_player(t_mapdata *map)
{
	RT = fmod(RT, 2*M_PI);
	if (RT < 0)
		RT += 2*M_PI;
	RT = RT + (TD * 0.05);
	if (MAP2D[(int)(PY + (WD * sin(RT) * 8) )/ (T_SIZE)][(int)PX / (T_SIZE)] != '1')
		if (MAP2D[(int)(PY + (SD * sin(RT + 90*M_PI/180) * 8))/ (T_SIZE)][(int)PX / (T_SIZE)] != '1')
		{
			PY = PY + (WD * sin(RT) * 4) + (SD * sin(RT + 90*M_PI/180) * 2);
		}
	if (MAP2D[(int)PY / (T_SIZE)][(int)(PX + (WD * cos(RT) * 8)) / (T_SIZE)] != '1')
		if (MAP2D[(int)PY / (T_SIZE)][(int)(PX + (SD * cos(RT + 90*M_PI/180) * 8)) / (T_SIZE)] != '1')
		{
			PX = PX + (WD * cos(RT) * 4) + (SD * cos(RT + 90*M_PI/180) * 2);
		}
	if (JP == 1)
	{
		if (JPINCR < 200)
			JPINCR += 10;
	}
	else if (JP == -1)
	{
		if ( JPINCR > -200)
			JPINCR -= 10;
	}
	if (JMP == 1 && CHCJMP == 0)
	{
		if (JMPINCR < 100)
			JMPINCR += 20;
		if (JMPINCR == 100)
			CHCJMP = 1;
	}
	if (JMP == 0 || CHCJMP == 1)
	{
		if (JMPINCR > 0)
			JMPINCR -= 20;
		if (JMPINCR <= 0)
			CHCJMP = 0;
	}
	if (DOOR == 1)
	{
		g_dec += 5;
	}
	castrays(map);
	// lifebar(map);
}

void ft_check_stuff(int y, int x, t_mapdata *map)
{
	if ((MAP2D[y][x] == 'N' || MAP2D[y][x] == 'E' || MAP2D[y][x] == 'S' || 
				MAP2D[y][x] == 'W') && g_loli == 0)
	{
		PX = x * (T_SIZE) + 16;
		PY = y * (T_SIZE) + 16;
		g_loli = 1;
		if (MAP2D[y][x] == 'N')
			RT = (270*M_PI/180);
		if (MAP2D[y][x] == 'S')
			RT = (90*M_PI/180);
		if (MAP2D[y][x] == 'E')
			RT = (0*M_PI/180);
		if (MAP2D[y][x] == 'W')
			RT = (180*M_PI/180);
	}
}

void		ft_drawmap(t_mapdata *map)
{

	g_loli = 0;
	g_mlx_ptr = mlx_init();
	g_mlx_win = mlx_new_window(g_mlx_ptr, WH, HT, "");
	mlx_hook(g_mlx_win, 2, 0, deal_key, map);
	mlx_hook(g_mlx_win, 3, 0, release_key, map);
	mlx_loop_hook(g_mlx_ptr, draw, map);
	mlx_loop(g_mlx_ptr);
}
