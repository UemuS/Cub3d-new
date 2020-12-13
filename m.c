/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:34:59 by yihssan           #+#    #+#             */
/*   Updated: 2020/12/12 23:59:05 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_strlast(char *s1, char *s2)
{
	int i;

	i = 0;
	while (++i < 4)
		if (s1[ft_strlen(s1) - i] != s2[4 - i])
			return (1);
	return (0);
}

void	ft_drawmap(t_mpdt *map)
{
	g_loli = 0;
	g_mlx_ptr = mlx_init();
	g_mlx_win = mlx_new_window(g_mlx_ptr, WH, HT, "");
	mlx_hook(g_mlx_win, 2, 0, deal_key, map);
	mlx_hook(g_mlx_win, 3, 0, release_key, map);
	mlx_hook(g_mlx_win, 17, 0, ft_quit, map);
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

	g_cac = 0;
	g_mylist = ft_lstnew(0);
	g_checksave = 0;
	if (argc == 2 && !ft_strlast(argv[1], ".cub"))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
			ft_intro(fd);
	}
	if (argc == 3 && !ft_strlast(argv[1], ".cub")
		&& !ft_strncmp(argv[2], "--save", 7))
	{
		g_checksave = 1;
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
			ft_intro(fd);
	}
	ft_error("wrong number of arguments or arguments names");
	ft_lstclear(&g_mylist);
}
