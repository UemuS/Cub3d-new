/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:34:59 by yihssan           #+#    #+#             */
/*   Updated: 2020/11/07 00:05:13 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_drawmap(t_mpdt *map)
{
	g_loli = 0;
	g_mlx_ptr = mlx_init();
	g_mlx_win = mlx_new_window(g_mlx_ptr, WH, HT, "");
	mlx_hook(g_mlx_win, 2, 0, deal_key, map);
	mlx_hook(g_mlx_win, 3, 0, release_key, map);
	mlx_loop_hook(g_mlx_ptr, draw, map);
	mlx_loop(g_mlx_ptr);
}

void	initwallxy(t_mpdt *map)
{
	WALLX = 0;
	WALLY = 0;
	WALLVX = 0;
	WALLVY = 0;
	WALLHX = 0;
	WALLHY = 0;
	g_hith = 0;
	g_hitv = 0;
}

int		main(int argc, char **argv)
{
	int fd;

	g_mylist = ft_lstnew(0);
	g_checksave = 0;
	if (argc == 2 && !ft_strncmp(argv[1], "map.cub", 8))
	{
		fd = open(argv[1], O_RDONLY);
		ft_intro(fd);
	}
	if (argc == 3 && !ft_strncmp(argv[1], "map.cub", 8)
		&& !ft_strncmp(argv[2], "--save", 7))
	{
		g_checksave = 1;
		fd = open(argv[1], O_RDONLY);
		ft_intro(fd);
	}
	else
		ft_error("wrong number of arguments or arguments names");
	ft_lstclear(&g_mylist);
}
