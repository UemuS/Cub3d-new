# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 17:57:14 by yihssan           #+#    #+#              #
#    Updated: 2020/12/13 00:05:52 by yihssan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	m.c cub3d.c drawall.c screenshot.c \
					ft_bzero.c ft_calloc.c ft_split.c \
					ft_strncmp.c ft_strtrim.c \
					get_next_line.c get_next_line_utils.c intersections.c \
					itoa_base.c lil.c managefile.c managefile2.c \
					mapstuff.c sprite.c startdrawing.c \
					utils.c utils2.c utils3.c \

SRCB = bonus/m_bonus.c bonus/cub3d_bonus.c bonus/drawall_bonus.c bonus/screenshot_bonus.c \
					bonus/ft_bzero_bonus.c bonus/ft_calloc_bonus.c bonus/ft_split_bonus.c \
					bonus/ft_strncmp_bonus.c bonus/ft_strtrim_bonus.c \
					bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/intersections_bonus.c \
					bonus/itoa_base_bonus.c bonus/lil_bonus.c bonus/managefile_bonus.c bonus/managefile2_bonus.c \
					bonus/mapstuff_bonus.c bonus/sprite_bonus.c bonus/startdrawing_bonus.c \
					bonus/utils_bonus.c bonus/utils2_bonus.c bonus/utils3_bonus.c \

NAME = lib.a

all:			$(NAME)

$(NAME)	:
		gcc -Wextra -Wall -Werror -c $(SRC)
		ar -rc lib.a *.o
		ranlib lib.a
		gcc lib.a -lmlx -g -framework OpenGL -framework appkit -o cub3D

bonus: fclean
	gcc -Wextra -Wall -Werror -c $(SRCB)
	ar -rc lib.a *.o
	ranlib lib.a
	gcc lib.a -lmlx -g -framework OpenGL -framework appkit -o cub3D
		
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re