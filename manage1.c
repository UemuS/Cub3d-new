/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:35:27 by yihssan           #+#    #+#             */
/*   Updated: 2020/10/16 05:54:28 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_east(t_mapdata *map, char *line)
{
	static int i = -1;

	while (line[++i])
	{
		if (line[i] == 'E' && line[i + 1] == 'A' &&
			line[i + 2] != ' ')
			ft_error("Something is wrong with the path EA");
		if (line[i] == '.')
		{
			EA = ft_substr(line, i, ft_strlen(line + i));
			ft_lstadd_front(&g_mylist, ft_lstnew(EA));
			MCHECK++;
			break ;
		}
	}
}

void	ft_sprite(t_mapdata *map, char *line)
{
	static int i = -1;

	while (line[++i])
	{
		if (line[i] == 'S' && line[i + 1] != ' ')
			ft_error("Something is wrong with the path S");
		if (line[i] == '.')
		{
			S = ft_substr(line, i, ft_strlen(line + i));
			ft_lstadd_front(&g_mylist, ft_lstnew(S));
			MCHECK++;
			break ;
		}
	}
}

void	ft_floor(t_mapdata *map, char *line)
{
	static int	i = 0;
	static int	j = 0;

	MCHECK++;
	while (line[i++])
	{
		if (line[i] == 'F' && line[i + 1] != ' ')
			ft_error("Something is wrong with the path F");
		if (ft_isdigit(line[i]) || line[i] == '-' || line[i] == '+')
		{
			F[j] = ft_atoi(line + i);
			i += ft_intlen(F[j] + 1);
			j++;
		}
	}
	if (j != 3)
		ft_error("not a valid color");
}

void	ft_ceeling(t_mapdata *map, char *line)
{
	static int	i = 0;
	static int	j = 0;

	MCHECK++;
	while (line[i++])
	{
		if (line[i] == 'C' && line[i + 1] != ' ')
			ft_error("Something is wrong with the path C");
		if (ft_isdigit(line[i]) || line[i] == '-' || line[i] == '+')
		{
			C[j] = ft_atoi(line + i);
			i += ft_intlen(C[j] + 1);
			j++;
		}
	}
	if (j != 3)
		ft_error("not a valid color");
}

void	ft_intro(int fd)
{
	t_mapdata	*map;

	g_rows = 0;
	if (!(map = malloc(sizeof(t_mapdata))))
		ft_error("can't be allocated");
	ft_lstadd_front(&g_mylist, ft_lstnew(map));
	ft_init(map);
	ft_read(fd, map);
	if (MCHECK != 8)
		ft_error("something is miss stated");
	MAP2D = ft_split(MAP0, '\n');
	g_rows = count_words(MAP0, '\n');
	ft_lstadd_front(&g_mylist, ft_lstnew(MAP0));
	treatthatmap(map);
	ft_lstadd_front(&g_mylist, ft_lstnew((MAP2D)));
	if (ft_check_fc(F[0], F[1], F[2]))
		ft_error("problem in the floor");
	if (ft_check_fc(C[0], C[1], C[2]))
		ft_error("problem in the ceiling");
	ft_fill_fc(map);
	int i = 0;
	while (MAP2D[i])
	{
		printf("%s\n", MAP2D[i]);
		i++;
	}
	ft_drawmap(map);
}
