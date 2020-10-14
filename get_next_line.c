/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:34:00 by yihssan           #+#    #+#             */
/*   Updated: 2020/02/24 09:34:06 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>
#include <string.h>

int		get_next_line(int fd, char **line)
{
	static char	*last[1024];
	char		*tmp;
	int			len;
	char		*pmt;

	len = 0;
	if (!last[fd])
		last[fd] = ft_strdup("");
	if (ft_conds(fd, line))
		return (-1);
	if (ft_fill(&last[fd], fd) < 0)
		return (-1);
	if ((ft_strchr(last[fd], '\n')))
	{
		tmp = last[fd];
		len = ft_strchr(last[fd], '\n') - last[fd];
		*line = ft_substr(last[fd], 0, len);
		last[fd] = ft_strdup(last[fd] + len + 1);
		return (ft_free(tmp, 1));
	}
	else
		*line = ft_strdup(last[fd]);
	pmt = last[fd];
	last[fd] = NULL;
	return (ft_free(pmt, 0));
}

int		ft_free(char *fr, int k)
{
	free(fr);
	return (k);
}

int		ft_fill(char **last, int fd)
{
	int		ret;
	char	*buf;
	char	**tmp;

	while (!ft_strchr(last[0], '\n'))
	{
		if (!(buf = malloc(1000 + 1)) ||
			(ret = read(fd, buf, 1000)) < 0)
			return (-1);
		buf[ret] = '\0';
		last[0] = ft_strjoin(last[0], buf);
		if (ret == 0)
		{
			tmp = last;
			last = 0;
			return (0);
		}
	}
	return (1);
}

int		ft_conds(int fd, char **l)
{
	if (!l || fd < 0)
		return (1);
	return (0);
}
