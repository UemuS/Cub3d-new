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
    //double  AY = floor(PY / (32)) * (32);
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

    AY = floor(PY / 32) * 32;
    AY += (i == 1 ? 32 : 0);
    AX = PX + (AY - PY) / tan(RT);
    ystep = 32 * ((i) ? 1 : -1);
    xstep = 32 / tan(RT);
    xstep *= ((!j && xstep > 0) ? -1 : 1);  
    xstep *= (j && xstep < 0) ? -1 : 1;
    xa = AX;
    ya = AY;
    ya -= (!i) ? 1 : -1;
    while (xa >= 0 && xa <= WH && ya >= 0 && ya <= HT)
    {
        if (MAP2D[(int)(ya / 32)][(int)(xa / 32)] == '1')
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

    AX = floor(PX / 32) * 32;
    AX += (j == 1 ? 32 : 0);
    AY = PY + (AX - PX) * tan(RT);
    xstep = 32;
    xstep *= (j) ? 1 : -1;
    ystep = 32 * tan(RT);
    ystep *= ((!i && ystep > 0) ? -1 : 1);
    ystep *= (i && ystep < 0) ? -1 : 1;
    xa = AX;
    ya = AY;
    xa -= (!j) ? 1 : 0;
    while (xa >= 0 && xa <= g_rows && ya >= 0 && ya <= g_case)
    {
        if (MAP2D[((int)ya / 32)][((int)xa / 32)] == '1')
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
void	drawground(t_mapdata *map)
{
	int i = 0;
	int	j;
    
    while (i < HT/2)
	{
		j = 0;
		while (j < WH)
		{
			g_img_data[i * WH + j] = 0x7bd3f7;
			j++;
		}		
		i++;
	}
	while (i < HT)
	{
		j = 0;
		while (j < WH)
		{
			g_img_data[i * WH + j] = 0x986152;
			j++;
		}		
		i++;
	}
}

int     draw(t_mapdata *map)
{
    int	bpp;
	int	size_line;
	int	endian;
    
    g_img_ptr = mlx_new_image(g_mlx_ptr, WH, HT);
	g_img_data = (int *)mlx_get_data_addr(g_img_ptr, &bpp, &size_line, &endian);
    drawground(map);
    ft_drawall(map);
    ft_draw_player(map);
    mlx_put_image_to_window(g_mlx_ptr, g_mlx_win, g_img_ptr, 0, 0);
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
    if (MAP2D[(int)(PY + (WD * sin(RT) * 20) )/ (32)][(int)(PX + (WD * cos(RT) * 20)) / (32)] != '1')
        if (MAP2D[(int)(PY + (SD * sin(RT + 90*M_PI/180) * 20))/ (32)][(int)(PX + (SD * cos(RT + 90*M_PI/180) * 20)) / (32)] != '1')
        {
            PX = PX + (WD * cos(RT) * 2) + (SD * cos(RT + 90*M_PI/180) * 2);
            PY = PY + (WD * sin(RT) * 2) + (SD * sin(RT + 90*M_PI/180) * 2);
        }
    castrays(map);
}

void ft_check_stuff(int y, int x, t_mapdata *map)
{
    if ((MAP2D[y][x] == 'N' || MAP2D[y][x] == 'E' || MAP2D[y][x] == 'S' || 
                MAP2D[y][x] == 'W') && g_loli == 0)
    {
        PX = x * (32);
        PY = y * (32);
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