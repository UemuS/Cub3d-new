NAME=cub3d.a
OUTPUT=*.o

SRC=	cub3d.c drawall.c drawmap.c ft_split.c get_next_line.c get_next_line_utils.c \
		itoa_base.c lil.c manage.c manage1.c mapstuff.c mathfunc.c m.c \

all: $(NAME)

$(NAME):
	gcc -Werror -Wextra -Wall -I /usr/local/include -Ofast -L /usr/local/lib/ -lmlx -framework OpenGL -framework appkit -c $(SRC)
	ar -rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
