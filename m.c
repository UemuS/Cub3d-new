/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:34:59 by yihssan           #+#    #+#             */
/*   Updated: 2020/03/11 22:26:23 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	main(int argc, char **argv)
{
	int fd;

	g_mylist = ft_lstnew(0);
	if (argc == 2 && !ft_strncmp(argv[1], "map.cub", 8))
	{
		fd = open(argv[1], O_RDONLY);
		ft_intro(fd);
	}
	else
		ft_error("not epic");
	ft_lstclear(&g_mylist);
}
