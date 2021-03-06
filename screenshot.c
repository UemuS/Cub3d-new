/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:44:00 by yihssan           #+#    #+#             */
/*   Updated: 2020/12/12 23:49:49 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static	int		create_file(char *file_name)
{
	int	fd;

	if (!((fd = open(file_name, O_WRONLY | O_CREAT |
	O_TRUNC, S_IRUSR | S_IWUSR)) > 0))
	{
		ft_error("Screenshot problem");
	}
	return (fd);
}

static void		head_make(t_bmp_file *info_bmp_file, t_mpdt *map)
{
	info_bmp_file->byte_type[0] = 0x42;
	info_bmp_file->byte_type[1] = 0x4D;
	info_bmp_file->byte_size = (WH * HT * 4) + 54;
	info_bmp_file->byte_reserved = 0x00000000;
	info_bmp_file->byte_offset = 0x36;
	info_bmp_file->header_size = 40;
	info_bmp_file->image_width = WH;
	info_bmp_file->image_height = -HT;
	info_bmp_file->color_planes = 1;
	info_bmp_file->bits_per_pixel = 32;
	info_bmp_file->compression = 0;
	info_bmp_file->image_size = (WH * HT * 4);
	info_bmp_file->bits_xpels_per_meter = 2835;
	info_bmp_file->bits_xpels_per_meter = 2835;
	info_bmp_file->total_colors = 0;
	info_bmp_file->important_colors = 0;
}

static void		head_write(int fd, t_bmp_file info_bmp_file)
{
	int			r;

	r = 0;
	r = write(fd, &info_bmp_file.byte_type, 2);
	r = write(fd, &info_bmp_file.byte_size, 4);
	r = write(fd, &info_bmp_file.byte_reserved, 4);
	r = write(fd, &info_bmp_file.byte_offset, 4);
	r = write(fd, &info_bmp_file.header_size, 4);
	r = write(fd, &info_bmp_file.image_width, 4);
	r = write(fd, &info_bmp_file.image_height, 4);
	r = write(fd, &info_bmp_file.color_planes, 2);
	r = write(fd, &info_bmp_file.bits_per_pixel, 2);
	r = write(fd, &info_bmp_file.compression, 4);
	r = write(fd, &info_bmp_file.image_size, 4);
	r = write(fd, &info_bmp_file.bits_xpels_per_meter, 4);
	r = write(fd, &info_bmp_file.bits_ypels_per_meter, 4);
	r = write(fd, &info_bmp_file.total_colors, 4);
	r = write(fd, &info_bmp_file.important_colors, 4);
	(void)r;
}

static void		file_write(int fd, int imagesize)
{
	char		*pixel_array;
	int			i;
	int			j;

	if (!(pixel_array = malloc(sizeof(char) * imagesize)))
		ft_error("Error screenshot");
	i = 0;
	j = 0;
	imagesize /= 4;
	while (i < imagesize)
	{
		pixel_array[j++] = g_img_data[i] & 255;
		pixel_array[j++] = (g_img_data[i] & 255 << 8) >> 8;
		pixel_array[j++] = (g_img_data[i] & 255 << 16) >> 16;
		pixel_array[j++] = 0;
		i++;
	}
	j = write(fd, pixel_array, imagesize *= 4);
	free(pixel_array);
}

void			save_bmp(t_mpdt *map)
{
	t_bmp_file	info_bmp_file;
	int			fd;

	ft_bzero(&info_bmp_file, sizeof(t_bmp_file));
	fd = create_file("screenshot.bmp");
	head_make(&info_bmp_file, map);
	head_write(fd, info_bmp_file);
	file_write(fd, info_bmp_file.image_size);
	close(fd);
	(void)info_bmp_file;
}
