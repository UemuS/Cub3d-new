/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapstuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:35:38 by yihssan           #+#    #+#             */
/*   Updated: 2020/12/12 20:41:25 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	continuetreatingthatmap(t_mpdt *map)
{
	static int		i = -1;
	static int		j;

	while (MAP2D[++i])
	{
		j = -1;
		ft_lstadd_front(&g_mylist, ft_lstnew((MAP2D[i])));
		if (i == 0 || i == g_rows - 1)
			while (MAP2D[i][++j])
				if (MAP2D[i][j] != '1' && MAP2D[i][j] != ' ')
					ft_error("map extreems aren't closed");
		if (i > 0 && i < g_rows - 1)
			while (MAP2D[i][++j])
			{
				g_count += (MAP2D[i][j] == '2') ? 1 : 0;
				if (MAP2D[i][j] == '0' || MAP2D[i][j] == '2')
					ft_cw_er(map, i, j);
				if (MAP2D[i][j] == 'N' || MAP2D[i][j] == 'S'
				|| MAP2D[i][j] == 'E' || MAP2D[i][j] == 'W')
					ft_cw_er(map, i, j);
			}
	}
}

int		helpread(char *line, t_mpdt *map, int r)
{
	if (line[0] == '\0' && g_cac == 0)
	{
		free(line);
		return (1);
	}
	if (line[0] == '\0' && g_cac == 1 && r != 0)
	{
		free(line);
		ft_error("empty line");
	}
	else if (ft_strtrim(line, " ")[0] == '1')
	{
		g_cac = 1;
		ft_matrix(map, line);
	}
	else if (ft_strtrim(line, " ")[0] != '1' && line[0] != '\0')
	{
		free(line);
		ft_error("line doesn't start with wall");
	}
	return (0);
}

void	treatthatmap(t_mpdt *map)
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
		g_case = ft_longest_array(map);
	}
	if (p == 0)
		ft_error("there's no player cookie");
}

int		ft_check_fc(int i, int j, int k)
{
	if (i > 255 || i < 0 || j > 255 || j < 0 || k > 255 || k < 0)
		ft_error("problem in the ceiling");
	return (1);
}
