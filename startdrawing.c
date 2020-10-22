/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:33:35 by yihssan           #+#    #+#             */
/*   Updated: 2020/10/16 23:50:33 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <math.h>

/*int ft_inter(t_mapdata *map)
{
    int rayside;
    int rayupd;
    int ver;
    int hor;
    
    rayupd = (RT > 0 && RT < M_PI) ? 1 : 0;
    rayside = ((RT > M_PI * 1.5) || RT < (0.5 * M_PI)) ? 1 : 0;
    ft_interhor(map, rayupd, rayside);
    ft_interver(map, rayupd, rayside);
    ver = sqrtf(pow((g_very - PY), 2) + pow((g_verx - PX), 2));
    hor = sqrtf(pow((g_hory - PY), 2) + pow((g_horx - PX), 2));
    g_very = (ver > hor) ? g_hory : g_very;
    g_verx = (ver > hor) ? g_horx : g_verx;
    int i = -1;
    int j = -1;
    //double  AY = floor(PY / (TILE_SIZE)) * (TILE_SIZE);
    //double  AX = PX + ((PY - AY)/tan(-RT));
    while (++i <= (g_verx) && ++j <= (g_very))
    {
        I_X = PX + (cos(RT) * i);
        J_Y = PY + (sin(RT) * j);
        g_img_data[((int)(J_Y) * WH + (int)(I_X))] = 0xff0000;
    }
    g_img_data[((int)g_very) * WH + ((int)g_verx)] = 0xFF0000;
    return(0);
}

int ft_interhor(t_mapdata *map, int i, int j)
{
    double  AY;
    double  AX;
    double  xstep;
    double  ystep;
    double  xa;
    double  ya;

    AY = floor(PY / TILE_SIZE) * TILE_SIZE;
    AY += (i == 1 ? TILE_SIZE : 0);
    AX = PX + (AY - PY) / tan(RT);
    ystep = TILE_SIZE * ((i) ? 1 : -1);
    xstep = TILE_SIZE / tan(RT);
    xstep *= ((!j && xstep > 0) ? -1 : 1);  
    xstep *= (j && xstep < 0) ? -1 : 1;
    xa = AX;
    ya = AY;
    ya -= (!i) ? 1 : -1;
    while (xa >= 0 && xa <= WH && ya >= 0 && ya <= HT)
    {
        if (MAP2D[(int)(ya / TILE_SIZE)][(int)(xa / TILE_SIZE)] == '1')
        {
            g_horx = xa;
            g_hory = ya;
            break;
        }
        else
        {
            xa += xstep;
            ya += ystep;
        }
    }
    return(0);
}

int ft_interver(t_mapdata *map, int i, int j)
{
    double  AY;
    double  AX;
    double  xstep;
    double  ystep;
    double  xa;
    double  ya;

    AX = floor(PX / TILE_SIZE) * TILE_SIZE;
    AX += (j == 1 ? TILE_SIZE : 0);
    AY = PY + (AX - PX) * tan(RT);
    xstep = TILE_SIZE;
    xstep *= (j) ? 1 : -1;
    ystep = TILE_SIZE * tan(RT);
    ystep *= ((!i && ystep > 0) ? -1 : 1);
    ystep *= (i && ystep < 0) ? -1 : 1;
    xa = AX;
    ya = AY;
    xa -= (!j) ? 1 : 0;
    while (xa >= 0 && xa <= g_rows && ya >= 0 && ya <= g_case)
    {
        if (MAP2D[((int)ya / TILE_SIZE)][((int)xa / TILE_SIZE)] == '1')
        {
            g_verx = xa;
            g_very = ya;
            break;
        }
        else
        {
            xa += xstep;
            ya += ystep;
        }
    }
    return(0);
}*/

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

    g_img_ptr = mlx_new_image(g_mlx_ptr, WH, HT);
	g_img_data = (int *)mlx_get_data_addr(g_img_ptr, &bpp, &size_line, &endian);
    g_xpm_NO = mlx_xpm_file_to_image(g_mlx_ptr, NO, &g_txt_wh, &g_txt_ht);
    g_xpm_SO = mlx_xpm_file_to_image(g_mlx_ptr, SO, &g_txt_wh, &g_txt_ht);
    g_xpm_EA = mlx_xpm_file_to_image(g_mlx_ptr, EA, &g_txt_wh, &g_txt_ht);
    g_xpm_WE = mlx_xpm_file_to_image(g_mlx_ptr, WE, &g_txt_wh, &g_txt_ht);
    g_xpm_SP = mlx_xpm_file_to_image(g_mlx_ptr, S, &g_txt_wh, &g_txt_ht);
    g_texture_buffer_NO = (int *)mlx_get_data_addr(g_xpm_NO, &bpp, &size_line, &endian);
    g_texture_buffer_SO = (int *)mlx_get_data_addr(g_xpm_SO, &bpp, &size_line, &endian);
    g_texture_buffer_EA = (int *)mlx_get_data_addr(g_xpm_EA, &bpp, &size_line, &endian);
    g_texture_buffer_WE = (int *)mlx_get_data_addr(g_xpm_WE, &bpp, &size_line, &endian);
    g_texture_buffer_SP = (int *)mlx_get_data_addr(g_xpm_SP, &bpp, &size_line, &endian);
    ft_drawall(map);
    ft_draw_player(map);
    mlx_put_image_to_window(g_mlx_ptr, g_mlx_win, g_img_ptr, 0, 0);
    //mlx_put_image_to_window(g_mlx_ptr, g_mlx_win, g_xpm_HUD, 0, (HT *1 / 100));
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
    RT = RT + (TD * 0.02);
    if (MAP2D[(int)(PY + (WD * sin(RT) * 8) )/ (TILE_SIZE)][(int)(PX + (WD * cos(RT) * 8)) / (TILE_SIZE)] != '1')
        if (MAP2D[(int)(PY + (SD * sin(RT + 90*M_PI/180) * 8))/ (TILE_SIZE)][(int)(PX + (SD * cos(RT + 90*M_PI/180) * 8)) / (TILE_SIZE)] != '1')
        {
            PX = PX + (WD * cos(RT) * 2) + (SD * cos(RT + 90*M_PI/180) * 1);
            PY = PY + (WD * sin(RT) * 2) + (SD * sin(RT + 90*M_PI/180) * 1);
        }
    castrays(map);
   // lifebar(map);
}

void ft_check_stuff(int y, int x, t_mapdata *map)
{
    if ((MAP2D[y][x] == 'N' || MAP2D[y][x] == 'E' || MAP2D[y][x] == 'S' || 
                MAP2D[y][x] == 'W') && g_loli == 0)
    {
        PX = x * (TILE_SIZE) + 16;
        PY = y * (TILE_SIZE) + 16;
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
    draw(map);
    mlx_hook(g_mlx_win, 2, 0, deal_key, map);
    mlx_hook(g_mlx_win, 3, 0, release_key, map);
    mlx_loop_hook(g_mlx_ptr, draw, map);
	mlx_loop(g_mlx_ptr);
}