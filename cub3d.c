/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:33:26 by yihssan           #+#    #+#             */
/*   Updated: 2020/10/16 03:45:08 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_atoi(const char *str)
{
	int result;
	int signe;

	result = 0;
	signe = 1;
	while (((*str >= 9 && *str <= 13) || *str == 32) && *str)
		str++;
	if (*str == '-')
	{
		signe = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		if (result < 0 && signe < 0)
			return (0);
		if (result < 0 && signe > 0)
			return (-1);
		result = result * 10 + *str - '0';
		str++;
	}
	return (signe * result);
}

void	ft_init(t_mapdata *map)
{
	map->width = 0;
	map->height = 0;
	map->north = 0;
	map->south = 0;
	map->east = 0;
	map->maponestr = 0;
	map->sprite = 0;
	map->west = 0;
	map->mapcheck = 0;
	map->fl = 0;
	map->cl = 0;
	map->td = 0;
	map->wd = 0;
	map->rt = M_PI / 2;
	map->sd = 0;
	map->jp = 0;
	map->jmp = 0;
	map->jmpincr = 0;
	map->jpincr = 0;
	map->checkjmp = 0;
	g_dec = 20;
	g_checkdoor = 0;
	g_count = 0;
}

void	ft_read(int fd, t_mapdata *map)
{
	char		*line;
	int			ret;

	while (1)
	{
		ret = get_next_line(fd, &line);
		if (line[0] == 'R' && line[1] == ' ' && (MCHECK++ || 1))
			ft_fetch(line, &HT, &WH, map);
		if (MCHECK < 8 && ft_strtrim(line, " ")[0] == '1')
			ft_error("an element is missing or map isn't last in the file");
		if (MCHECK == 8)
			if (helpread(line, map, ret))
				continue;
		(line[0] == 'N' && line[1] == 'O') ? ft_north(map, line) : 0;
		(line[0] == 'S' && line[1] == 'O') ? ft_south(map, line) : 0;
		(line[0] == 'W' && line[1] == 'E') ? ft_west(map, line) : 0;
		(line[0] == 'E' && line[1] == 'A') ? ft_east(map, line) : 0;
		(line[0] == 'S' && line[1] == ' ') ? ft_sprite(map, line) : 0;
		(line[0] == 'F' && line[1] == ' ') ? ft_floor(map, line) : 0;
		(line[0] == 'C' && line[1] == ' ') ? ft_ceeling(map, line) : 0;
		free(line);
		if (ret == 0)
			break ;
	}
}

void	ft_fill_fc(t_mapdata *map)
{
	FL = ft_strjoin(FL, itoa_base(F[0], "0123456789abcdef"));
	FL = ft_strjoin(FL, itoa_base(F[1], "0123456789abcdef"));
	FL = ft_strjoin(FL, itoa_base(F[2], "0123456789abcdef"));
	CL = ft_strjoin(CL, itoa_base(C[0], "0123456789abcdef"));
	CL = ft_strjoin(CL, itoa_base(C[1], "0123456789abcdef"));
	CL = ft_strjoin(CL, itoa_base(C[2], "0123456789abcdef"));
	g_FL = hex_to_dec(FL);
	g_CL = hex_to_dec(CL);
	printf("%d %d\n", g_FL, g_CL);
}

void	ft_matrix(t_mapdata *map, char *line)
{
	int		i;

	i = 0;
	if (!MAP0)
		MAP0 = ft_strdup("");
	MAP0 = ft_strjoin(MAP0, line);
	MAP0 = ft_strjoin(MAP0, ft_strdup("\n"));
}
