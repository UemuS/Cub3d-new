/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startdrawing_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:33:35 by yihssan           #+#    #+#             */
/*   Updated: 2020/11/30 20:22:48 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <math.h>

void	ft_drawall(t_mpdt *map)
{
	int x;
	int y;

	y = -1;
	while (MAP2D[++y])
	{
		x = -1;
		while (MAP2D[y][++x])
			if (MAP2D[y][x] != '0' && MAP2D[y][x] != '1')
				ft_check_stuff(y, x, map);
	}
}

int		draw(t_mpdt *map)
{
	int	bpp;
	int	size_line;
	int	endian;
	int us;
	int ad;
	static int ac = 0;

	if (ac == 0)
	{
	g_img_ptr = mlx_new_image(g_mlx_ptr, WH, HT);
	g_img_data = (int *)mlx_get_data_addr(g_img_ptr, &bpp, &size_line, &endian);
	XPM_NO = mlx_xpm_file_to_image(g_mlx_ptr, NO, &TXT_WH_NO, &TXT_HT_NO);
	XPM_SO = mlx_xpm_file_to_image(g_mlx_ptr, SO, &TXT_WH_SO, &TXT_HT_SO);
	XPM_EA = mlx_xpm_file_to_image(g_mlx_ptr, EA, &TXT_WH_EA, &TXT_HT_EA);
	XPM_WE = mlx_xpm_file_to_image(g_mlx_ptr, WE, &TXT_WH_WE, &TXT_HT_WE);
	XPM_VIS = mlx_xpm_file_to_image(g_mlx_ptr, "texture/weap.xpm", &us, &us);
	XPM_FL = mlx_xpm_file_to_image(g_mlx_ptr, "texture/vis.xpm", &ad, &ad);
	TXT_BUF_NO = (int *)mlx_get_data_addr(XPM_NO, &bpp, &size_line, &endian);
	TXT_BUF_SO = (int *)mlx_get_data_addr(XPM_SO, &bpp, &size_line, &endian);
	TXT_BUF_EA = (int *)mlx_get_data_addr(XPM_EA, &bpp, &size_line, &endian);
	TXT_BUF_WE = (int *)mlx_get_data_addr(XPM_WE, &bpp, &size_line, &endian);
	TXT_BUF_VIS = (int *)mlx_get_data_addr(XPM_VIS, &bpp, &size_line, &endian);
	TXT_BUF_FL = (int *)mlx_get_data_addr(XPM_FL, &bpp, &size_line, &endian);
	init_spt(map);
	RAYDIST = malloc(sizeof(int *) * WH);
	ft_lstadd_front(&g_mylist, ft_lstnew(RAYDIST));
	ac = 1;
	}
	ft_helpdrawasquare(map);
	mlx_put_image_to_window(g_mlx_ptr, g_mlx_win, g_img_ptr, 0, 0);
	mlx_put_image_to_window(g_mlx_ptr, g_mlx_win, XPM_VIS, WH / 2, HT - 200);
	mlx_put_image_to_window(g_mlx_ptr, g_mlx_win, XPM_FL, WH / 2 - 50, HT / 2);
	return (0);
}

void	ft_draw_player(t_mpdt *map)
{
	int x;
	int y;
	int x1;
	int y1;

	y = MAP2D[(int)(PY + (WD * sin(RT) * 8)) / (TL_SZE)][(int)PX / (TL_SZE)];
	y1 = MAP2D[(int)(PY + (SD * sin(RT + 90 * M_PI / 180) * 8))
	/ (TL_SZE)][(int)PX / (TL_SZE)];
	x = MAP2D[(int)PY / (TL_SZE)][(int)(PX + (WD * cos(RT) * 8)) / (TL_SZE)];
	x1 = MAP2D[(int)PY / (TL_SZE)][(int)(PX + (SD
	* cos(RT + 90 * M_PI / 180) * 8)) / (TL_SZE)];
	RT = fmod(RT, 2 * M_PI);
	if (RT < 0)
		RT += 2 * M_PI;
	RT = RT + (TD * 0.05);
	if (y != '1' && y != '2')
		if (y1 != '1' && y1 != '2')
			PY = PY + (WD * sin(RT) * 4) + (SD * sin(RT + 90 * M_PI / 180) * 2);
	if (x != '1' && x != '2')
		if (x1 != '1' && x1 != '2')
			PX = PX + (WD * cos(RT) * 4) + (SD * cos(RT + 90 * M_PI / 180) * 2);
	ft_jmp(map);
	castrays(map);
}

void	ft_check_stuff(int y, int x, t_mpdt *map)
{
	if ((MAP2D[y][x] == 'N' || MAP2D[y][x] == 'E' || MAP2D[y][x] == 'S' ||
				MAP2D[y][x] == 'W') && g_loli == 0)
	{
		PX = x * (TL_SZE) + 32;
		PY = y * (TL_SZE) + 32;
		g_loli = 1;
		if (MAP2D[y][x] == 'N')
			RT = (270 * (M_PI / 180));
		if (MAP2D[y][x] == 'S')
			RT = (90 * (M_PI / 180));
		if (MAP2D[y][x] == 'E')
			RT = (0);
		if (MAP2D[y][x] == 'W')
			RT = (180 * (M_PI / 180));
	}
}

int		ft_before_map(t_mpdt *map, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		ft_north(map, line);
	else if (line[0] == 'R' && line[1] == ' ' && (MCHECK++ || 1))
		ft_fetch(line, &HT, &WH, map);
	else if (line[0] == 'S' && line[1] == 'O')
		ft_south(map, line);
	else if (line[0] == 'W' && line[1] == 'E')
		ft_west(map, line);
	else if (line[0] == 'E' && line[1] == 'A')
		ft_east(map, line);
	else if (line[0] == 'S' && line[1] == ' ')
		ft_sprite(map, line);
	else if (line[0] == 'F' && line[1] == ' ')
		ft_floor(map, line);
	else if (line[0] == 'C' && line[1] == ' ')
		ft_ceeling(map, line);
	else if (line[0] != '\0')
	{
		free(line);
		ft_error("unwanted element");
	}
	free(line);
	return (0);
}
