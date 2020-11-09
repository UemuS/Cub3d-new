/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:23:27 by yihssan           #+#    #+#             */
/*   Updated: 2020/11/08 00:25:28 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_jmp(t_mpdt *map)
{
	if (JP == 1)
	{
		if (JPINCR < 200)
			JPINCR += 10;
	}
	else if (JP == -1)
		if (JPINCR > -200)
			JPINCR -= 10;
	if (JMP == 1 && CHCJMP == 0)
	{
		if (JMPINCR < 100)
			JMPINCR += 20;
		if (JMPINCR == 100)
			CHCJMP = 1;
	}
	if (JMP == 0 || CHCJMP == 1)
	{
		if (JMPINCR > 0)
			JMPINCR -= 20;
		if (JMPINCR <= 0)
			CHCJMP = 0;
	}
	if (DOOR == 1)
		g_dec += 5;
}

int		deal_key(int key, t_mpdt *map)
{
	if (key == 123)
		TD = -1;
	if (key == 124)
		TD = 1;
	if (key == 13)
		WD = 1;
	if (key == 0)
		SD = -1;
	if (key == 2)
		SD = 1;
	if (key == 1)
		WD = -1;
	if (key == 53)
	{
		mlx_destroy_window(g_mlx_ptr, g_mlx_win);
		ft_error("");
	}
	if (key == 126)
		JP = 1;
	if (key == 125)
		JP = -1;
	JMP = (key == 49) ? 1 : 0;
	return (0);
}

int		release_key(int key, t_mpdt *map)
{
	if (key == 123)
		TD = 0;
	if (key == 124)
		TD = 0;
	if (key == 13)
		WD = 0;
	if (key == 0)
		SD = 0;
	if (key == 2)
		SD = 0;
	if (key == 1)
		WD = 0;
	if (key == 126)
		JP = 0;
	if (key == 125)
		JP = 0;
	if (key == 49)
		JMP = 0;
	return (0);
}
