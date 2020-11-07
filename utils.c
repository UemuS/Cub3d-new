/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:38:28 by yihssan           #+#    #+#             */
/*   Updated: 2020/11/07 01:31:51 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		check_vision_ht(t_mpdt *map)
{
	if (g_rayup && g_hith)
		return (TXT_HT_NO);
	if (g_rayleft && g_hitv)
		return (TXT_HT_EA);
	if (g_raydown && g_hith)
		return (TXT_HT_SO);
	if (g_rayright && g_hitv)
		return (TXT_HT_WE);
	return (0);
}

int		check_vision_wh(t_mpdt *map)
{
	if (g_rayup && g_hith)
		return (TXT_WH_NO);
	if (g_rayleft && g_hitv)
		return (TXT_WH_EA);
	if (g_raydown && g_hith)
		return (TXT_WH_SO);
	if (g_rayright && g_hitv)
		return (TXT_WH_WE);
	return (0);
}

double	ft_fmod(double a, double b)
{
	return (a - (floor(a / b) * b));
}

double	normalangle(double *rayangle)
{
	*rayangle = fmod(*rayangle, (2 * M_PI));
	if (*rayangle < 0)
		*rayangle = (2 * M_PI) + *rayangle;
	return (*rayangle);
}

void	rayfacing(double rayangle)
{
	g_raydown = ((rayangle > 0) && (rayangle < M_PI));
	g_rayup = !g_raydown;
	g_rayright = ((rayangle < M_PI_2) || (rayangle > (1.5 * M_PI)));
	g_rayleft = !g_rayright;
}
