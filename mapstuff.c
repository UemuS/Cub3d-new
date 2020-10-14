/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapstuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:35:38 by yihssan           #+#    #+#             */
/*   Updated: 2020/03/11 22:41:06 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	continuetreatingthatmap(t_mapdata *map)
{
	static int		i = -1;
	static int		j;

	while (MAP2D[++i])
	{
		j = -1;
		ft_lstadd_front(&g_mylist, ft_lstnew((MAP2D[i])));
		if (i == 0 || i == g_rows - 1)
		{
			while (MAP2D[i][++j])
				if (MAP2D[i][j] != '1' && MAP2D[i][j] != ' ')
					ft_error("map extreems aren't closed");
		}
		else if (i > 0 && i < g_rows - 1)
		{
			while (MAP2D[i][++j])
			if (MAP2D[i][j] == '0')
			{
				ft_cw(MAP2D[i + 1][j]) == 0 ? ft_error("Not surrounded") : 0;
				ft_cw(MAP2D[i - 1][j]) == 0 ? ft_error("Not surrounded") : 0;
				ft_cw(MAP2D[i][j + 1]) == 0 ? ft_error("Not surrounded") : 0;
				ft_cw(MAP2D[i][j - 1]) == 0 ? ft_error("Not surrounded") : 0;
			}
		}
	}
}

int		ft_cw(char i)
{
	if (i != '0' && i != '1' && i != '2' && i != 'N' && i != 'W' && 
	i != 'S' && i != 'E')
		return (0);
	return (1);
}

int		helptreatingthatmap(char c)
{
	if (c != '1' && c != '2' && c != '0' && c != 'N'
		&& c != 'S' && c != 'E' && c != 'W' && c != ' ')
		return (0);
	return (1);
}

int		helpread(char *line, t_mapdata *map, int r)
{
	static int	loli = 0;
	
	if (line[0] == '\0' && loli == 0)
	{
		free(line);
		return (1);
	}
	if (line[0] == '\0' && loli == 1 && r != 0)
	{
		free(line);
		ft_error("empty line");
	}
	else if (ft_strtrim(line, " ")[0] == '1')
	{
		loli = 1;
		ft_matrix(map, line);
	}
	else if (ft_strtrim(line, " ")[0] == '0')
	{
		free(line);
		ft_error("line starts with zero");
	}
	return (0);
}

void	treatthatmap(t_mapdata *map)
{
	static int i = -1;
	static int j = -1;
	static int p = 0;

	continuetreatingthatmap(map);
	while (MAP2D[++i])
	{
		j = -1;
		while (MAP2D[i][++j])
		{
			if ((MAP2D[i][j] == 'N' || MAP2D[i][j] == 'W'
				|| MAP2D[i][j] == 'E' || MAP2D[i][j] == 'S') && p == 0)
				p = 1;
			else if ((MAP2D[i][j] == 'N' || MAP2D[i][j] == 'W'
				|| MAP2D[i][j] == 'E' || MAP2D[i][j] == 'S') && p == 1)
				ft_error("multiplayer game");
			if (helptreatingthatmap(MAP2D[i][j]) == 0)
				ft_error("something that shouldn't be in the map");
		}
		g_case = j;
	}
	if (p == 0)
		ft_error("there's no player cookie");
}

int		ft_check_fc(int i, int j, int k)
{
	if (i > 255 || i < 0 || j > 255 || j < 0 || k > 255 || k < 0)
		return (1);
	return (0);
}
