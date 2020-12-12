/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:38:24 by yihssan           #+#    #+#             */
/*   Updated: 2020/12/12 17:49:22 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_mmwindow(t_mpdt *map, int *height, int *width)
{
	HT = (*height > MAX_HEIGHT) ? MAX_HEIGHT : *height;
	WH = (*width > MAX_WIDTH) ? MAX_WIDTH : *width;
	HT = ((*height < MIN_WIDTH) ? MIN_WIDTH : *height);
	WH = (*width < MIN_WIDTH) ? MIN_WIDTH : *width;
}

int		ft_cw(char i)
{
	if (i != '0' && i != '1' && i != '2' && i != 'N' && i != 'W' &&
			i != 'S' && i != 'E' && i != '3')
		return (0);
	return (1);
}

int		helptreatingthatmap(char c)
{
	if (c != '1' && c != '2' && c != '0' && c != 'N'
			&& c != 'S' && c != 'E' && c != 'W' && c != ' ' && c != '3')
		return (0);
	return (1);
}

void	ft_cw_er(t_mpdt *map, int i, int j)
{
	ft_cw(MAP2D[i + 1][j]) == 0 ? ft_error("Not surrounded") : 0;
	ft_cw(MAP2D[i - 1][j]) == 0 ? ft_error("Not surrounded") : 0;
	ft_cw(MAP2D[i][j + 1]) == 0 ? ft_error("Not surrounded") : 0;
	ft_cw(MAP2D[i][j - 1]) == 0 ? ft_error("Not surrounded") : 0;
}

void	ft_ayaya(t_mpdt *map)
{
	int a;
	int us;
	int ad;

	g_img_ptr = mlx_new_image(g_mlx_ptr, WH, HT);
	g_img_data = (int *)mlx_get_data_addr(g_img_ptr, &a, &a, &a);
	XPM_NO = mlx_xpm_file_to_image(g_mlx_ptr, NO, &TXT_WH_NO, &TXT_HT_NO);
	XPM_SO = mlx_xpm_file_to_image(g_mlx_ptr, SO, &TXT_WH_SO, &TXT_HT_SO);
	XPM_EA = mlx_xpm_file_to_image(g_mlx_ptr, EA, &TXT_WH_EA, &TXT_HT_EA);
	XPM_WE = mlx_xpm_file_to_image(g_mlx_ptr, WE, &TXT_WH_WE, &TXT_HT_WE);
	XPM_VIS = mlx_xpm_file_to_image(g_mlx_ptr, "texture/weap.xpm", &us, &us);
	XPM_FL = mlx_xpm_file_to_image(g_mlx_ptr, "texture/vis.xpm", &ad, &ad);
	TXT_BUF_NO = (int *)mlx_get_data_addr(XPM_NO, &a, &a, &a);
	TXT_BUF_SO = (int *)mlx_get_data_addr(XPM_SO, &a, &a, &a);
	TXT_BUF_EA = (int *)mlx_get_data_addr(XPM_EA, &a, &a, &a);
	TXT_BUF_WE = (int *)mlx_get_data_addr(XPM_WE, &a, &a, &a);
	TXT_BUF_VIS = (int *)mlx_get_data_addr(XPM_VIS, &a, &a, &a);
	TXT_BUF_FL = (int *)mlx_get_data_addr(XPM_FL, &a, &a, &a);
	init_spt(map);
	RAYDIST = malloc(sizeof(int *) * WH);
	ft_lstadd_front(&g_mylist, ft_lstnew(RAYDIST));
}
