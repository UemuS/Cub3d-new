/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:38:24 by yihssan           #+#    #+#             */
/*   Updated: 2020/11/05 18:24:58 by yihssan          ###   ########.fr       */
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
