/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:33:26 by yihssan           #+#    #+#             */
/*   Updated: 2020/12/13 05:16:05 by yihssan          ###   ########.fr       */
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

void	ft_init(t_mpdt *map)
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
	g_count = 0;
}

void	ft_read(int fd, t_mpdt *map)
{
	char		*line;
	int			ret;

	while (1)
	{
		ret = get_next_line(fd, &line);
		if (MCHECK < 8 && ft_strtrim(line, " ")[0] == '1')
		{
			free(line);
			ft_error("an element is missing or map isn't last in the file");
		}
		if (MCHECK == 8)
			if (helpread(line, map, ret))
				continue;
		if (MCHECK < 8)
			ft_before_map(map, line);
		if (MCHECK == 8 && ret == 0 && g_cac == 0)
		{
			free(line);
			ft_error("no map");
		}
		if (ret == 0)
			break ;
	}
}

void	ft_fill_fc(t_mpdt *map)
{
	FL = ft_strjoin(FL, itoa_base(F[0], "0123456789abcdef"));
	FL = ft_strjoin(FL, itoa_base(F[1], "0123456789abcdef"));
	FL = ft_strjoin(FL, itoa_base(F[2], "0123456789abcdef"));
	CL = ft_strjoin(CL, itoa_base(C[0], "0123456789abcdef"));
	CL = ft_strjoin(CL, itoa_base(C[1], "0123456789abcdef"));
	CL = ft_strjoin(CL, itoa_base(C[2], "0123456789abcdef"));
	g_fl = hex_to_dec(FL);
	g_cl = hex_to_dec(CL);
}

void	ft_matrix(t_mpdt *map, char *line)
{
	if (!MAP0)
		MAP0 = ft_strdup("");
	MAP0 = ft_strjoin(MAP0, line);
	MAP0 = ft_strjoin(MAP0, ft_strdup("\n"));
}
