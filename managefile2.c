/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managefile2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:35:27 by yihssan           #+#    #+#             */
/*   Updated: 2020/12/13 04:12:56 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_east(t_mpdt *map, char *line)
{
	static int	i = -1;

	if (line[i] == 'E' && line[i + 1] == 'A' &&
			line[i + 2] != ' ')
		ft_error("Something is wrong with the path EA");
	i = 2;
	while (line[++i] == ' ')
		continue;
	EA = ft_substr(line, i, ft_strlen(line + i));
	ft_lstadd_front(&g_mylist, ft_lstnew(EA));
	if (open(SO, O_WRONLY | O_APPEND) == -1)
		ft_error("Invalid path to east");
	MCHECK++;
}

void	ft_sprite(t_mpdt *map, char *line)
{
	static int	i = -1;

	if (line[i] == 'S' && line[i + 1] == ' ')
		ft_error("Something is wrong with the path of sprite");
	i = 1;
	while (line[++i] == ' ')
		continue;
	S = ft_substr(line, i, ft_strlen(line + i));
	ft_lstadd_front(&g_mylist, ft_lstnew(S));
	if (open(S, O_WRONLY | O_APPEND) == -1)
		ft_error("Invalid path to sprite");
	MCHECK++;
}

void	ft_floor(t_mpdt *map, char *line)
{
	static int	i = 1;
	static int	j = 0;

	MCHECK++;
	while (line[i++])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != ',' && line[i])
			ft_error("unwanted element in floor");
		if (ft_isdigit(line[i]) || line[i] == '-' || line[i] == '+')
		{
			F[j] = ft_atoi(line + i);
			i += ft_intlen(F[j] + 1);
			j++;
			(j <= 2 && line[i] != ',' ? ft_error("unwanted element") : 0);
		}
		if (line[i] == ',')
			if (!ft_isdigit(line[i - 1]) || !ft_isdigit(line[i + 1]))
				ft_error("unwanted element in floor");
	}
	(j != 3) ? ft_error("not a valid color") : 0;
	(line[i - 2] && !ft_isdigit(line[i - 2])) ? ft_error("why u add dis") : 0;
}

void	ft_ceeling(t_mpdt *map, char *line)
{
	static int	i = 1;
	static int	j = 0;

	MCHECK++;
	while (line[i++])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != ',' && line[i])
			ft_error("unwanted element in ceiling");
		if (ft_isdigit(line[i]) || line[i] == '-' || line[i] == '+')
		{
			C[j] = ft_atoi(line + i);
			i += ft_intlen(C[j] + 1);
			j++;
		}
		if (line[i] == ',')
			if (!ft_isdigit(line[i - 1]) || !ft_isdigit(line[i + 1]))
				ft_error("unwanted element in ceiling");
	}
	(j != 3) ? ft_error("not a valid color") : 0;
	(line[i - 2] && !ft_isdigit(line[i - 2])) ? ft_error("why u add dis") : 0;
}

void	ft_intro(int fd)
{
	t_mpdt		*map;
	int			i;

	g_rows = 0;
	if (!(map = malloc(sizeof(t_mpdt))))
		ft_error("can't be allocated");
	ft_lstadd_front(&g_mylist, ft_lstnew(map));
	ft_init(map);
	ft_read(fd, map);
	if (MCHECK != 8)
		ft_error("something is miss stated");
	MAP2D = ft_split(MAP0, '\n', map);
	g_rows = count_words(MAP0, '\n');
	ft_lstadd_front(&g_mylist, ft_lstnew(MAP0));
	treatthatmap(map);
	ft_lstadd_front(&g_mylist, ft_lstnew((MAP2D)));
	ft_check_fc(F[0], F[1], F[2]);
	ft_check_fc(C[0], C[1], C[2]);
	ft_fill_fc(map);
	i = -1;
	free(MAP0);
	ft_drawmap(map);
}
