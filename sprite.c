/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:44:07 by yihssan           #+#    #+#             */
/*   Updated: 2020/11/30 20:21:18 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_just_do(t_mpdt *map, int id, int i)
{
	if ((SPRITES[id].x_off + i < 0 || SPRITES[id].x_off + i > WH)
		|| RAYDIST[(int)(SPRITES[id].x_off + i)] <= SPRITES[id].dist)
		return (1);
	return (0);
}

void	draw_sprite(t_mpdt *map, int id)
{
	int		i;
	int		j;
	int		c;
	float	size;

	i = -1;
	size = SPRITES[id].size;
	while (++i < size)
	{
		if (ft_just_do(map, id, i))
			continue ;
		j = -1;
		while (++j < size)
		{
			if (SPRITES[id].y_off + j < 0 || SPRITES[id].y_off + j > HT)
				continue ;
			c = SPRITES->sdata[(int)((TL_SZE) *
					(TL_SZE * j / (int)size) + (TL_SZE * i / (int)size))];
			if (c != SPRITES->sdata[0] && j + 1 <= size && i + 1 <= size)
				if ((int)((j + SPRITES[id].y_off)
					* WH + (i + SPRITES[id].x_off)) < WH * HT)
					g_img_data[(int)((j + SPRITES[id].y_off) *
					WH + (i + SPRITES[id].x_off))] = c;
		}
	}
}

void	to_sort(t_mpdt *map)
{
	int			i;
	int			j;
	float		tmp_dist;
	float		tmp_x;
	float		tmp_y;

	i = -1;
	while (++i < g_count)
	{
		j = -1;
		while (++j < g_count - i)
			if (SPRITES[j].dist < SPRITES[j + 1].dist)
			{
				tmp_dist = SPRITES[j].dist;
				tmp_x = SPRITES[j].x;
				tmp_y = SPRITES[j].y;
				SPRITES[j].dist = SPRITES[j + 1].dist;
				SPRITES[j].x = SPRITES[j + 1].x;
				SPRITES[j].y = SPRITES[j + 1].y;
				SPRITES[j + 1].dist = tmp_dist;
				SPRITES[j + 1].x = tmp_x;
				SPRITES[j + 1].y = tmp_y;
			}
	}
}

void	to_sprite(t_mpdt *map, int m)
{
	float	angle;
	int		k;

	m = -1;
	k = -1;
	to_sort(map);
	while (++k < g_count)
	{
		SPRITES[k].dist = sqrtf(((SPRITES[k].x) - PX) * ((SPRITES[k].x) - PX)
				+ ((SPRITES[k].y) - PY) * ((SPRITES[k].y) - PY));
		angle = atan2f(SPRITES[k].y - PY, SPRITES[k].x - PX);
		while (angle - RT > M_PI)
			angle -= 2 * M_PI;
		while (angle - RT < -M_PI)
			angle += 2 * M_PI;
		if (HT > WH)
			SPRITES[k].size = (HT / SPRITES[k].dist) * TL_SZE;
		else
			SPRITES[k].size = (WH / SPRITES[k].dist) * TL_SZE;
		SPRITES[k].y_off = HT / 2 - (int)SPRITES[k].size / 2;
		SPRITES[k].x_off = ((DEG(angle) - DEG(RT)) * WH)
			/ (float)TL_SZE + ((WH / 2) - (int)SPRITES[k].size / 2);
		draw_sprite(map, k);
	}
}

void	init_spt(t_mpdt *map)
{
	int			i;
	int			j;
	int			k;

	i = -1;
	k = 0;
	if (!(SPRITES = malloc(sizeof(t_sprite) * (g_count + 1))))
		ft_error("");
	ft_lstadd_front(&g_mylist, ft_lstnew(SPRITES));
	SPRITES->simg = mlx_xpm_file_to_image(g_mlx_ptr, S, &SH, &SW);
	SPRITES->sdata = (int *)mlx_get_data_addr(SPRITES->simg, &DT, &DT1, &DT1);
	while (MAP2D[++i] != 0 && (j = -1) && (k < g_count))
	{
		while (MAP2D[i][++j] != 0 && (k < g_count))
		{
			if (MAP2D[i][j] == '2')
			{
				SPRITES[k].x = (j + 0.5f) * TL_SZE;
				SPRITES[k].y = (i + 0.5f) * TL_SZE;
				SPRITES[k].dist = sqrtf(((SPRITES[k].x) - PX) * ((SPRITES[k].x)
					- PX) + ((SPRITES[k].y) - PY) * ((SPRITES[k].y) - PY));
				k++;
			}
		}
	}
}
