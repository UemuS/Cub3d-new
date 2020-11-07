/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managefile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:35:13 by yihssan           #+#    #+#             */
/*   Updated: 2020/11/05 18:28:10 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_fetch(char *line, int *height, int *width, t_mpdt *map)
{
	static int	i = 0;
	static int	cond1 = 1;
	static int	cond2 = 1;
	static int	check = 0;

	while (line[i++] != '\0')
	{
		if (((line[i] == '0' && line[i + 1] == ' ') || line[i] == '-'))
			ft_error("impossible resolution");
		if (ft_isdigit(line[i]) && cond1 && (check += 1))
		{
			(*width = ft_atoi(line + i)) && (cond1 -= cond1);
			i += ft_intlen(*width);
		}
		if (ft_isdigit(line[i]) && !cond1 && cond2 && (check += 1))
		{
			*height = ft_atoi(line + i);
			i += ft_intlen(*height);
		}
		(ft_isdigit(line[i]) && !cond1 && !cond2) ? check++ : 0;
	}
	(!(line[1] == ' ')) ? ft_error("no space after R") : 0;
	(check != 2) ? ft_error("wrong number of params") : 0;
	ft_mmwindow(map, height, width);
}

int		ft_intlen(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		i++;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void	ft_north(t_mpdt *map, char *line)
{
	static int	i = -1;

	if (line[i] == 'N' && line[i + 1] == 'O' &&
			line[i + 2] != ' ')
		ft_error("Something is wrong with the path NO");
	i = 2;
	while (line[++i] == ' ')
		continue;
	NO = ft_substr(line, i, ft_strlen(line + i));
	ft_lstadd_front(&g_mylist, ft_lstnew(NO));
	if (open(NO, O_WRONLY | O_APPEND) == -1)
		ft_error("Invalid path to north");
	MCHECK++;
}

void	ft_south(t_mpdt *map, char *line)
{
	static int	i = -1;

	if (line[i] == 'S' && line[i + 1] == 'O' &&
			line[i + 2] != ' ')
		ft_error("Something is wrong with the path SO");
	i = 2;
	while (line[++i] == ' ')
		continue;
	SO = ft_substr(line, i, ft_strlen(line + i));
	ft_lstadd_front(&g_mylist, ft_lstnew(SO));
	if (open(SO, O_WRONLY | O_APPEND) == -1)
		ft_error("Invalid path to south");
	MCHECK++;
}

void	ft_west(t_mpdt *map, char *line)
{
	static int	i = -1;

	if (line[i] == 'W' && line[i + 1] == 'E' &&
			line[i + 2] != ' ')
		ft_error("Something is wrong with the path WE");
	i = 2;
	while (line[++i] == ' ')
		continue;
	WE = ft_substr(line, i, ft_strlen(line + i));
	ft_lstadd_front(&g_mylist, ft_lstnew(WE));
	if (open(WE, O_WRONLY | O_APPEND) == -1)
		ft_error("Invalid path to west");
	MCHECK++;
}
