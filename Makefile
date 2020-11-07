# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 17:57:14 by yihssan           #+#    #+#              #
#    Updated: 2020/11/07 02:24:09 by yihssan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	m.c cub3d.c drawall.c screenshot.c \
					ft_bzero.c ft_calloc.c ft_split.c \
					ft_strncmp.c ft_strtrim.c \
					get_next_line.c get_next_line_utils.c intersections.c \
					itoa_base.c lil.c managefile.c managefile2.c \
					mapstuff.c sprite.c startdrawing.c \
					utils.c utils2.c utils3.c \

NAME = lib.a

all:			$(NAME)

$(NAME)	:
		gcc -Wextra -Wall -Werror -c $(SRC)
		ar -rc lib.a *.o
		ranlib lib.a
		gcc lib.a -lmlx -g -framework OpenGL -framework appkit -fsanitize=address -o cub3D

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

