/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:34:33 by yihssan           #+#    #+#             */
/*   Updated: 2020/03/11 22:41:42 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H

# define LIB_H

# include <math.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx.h"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct	s_list
{
	int		width;
	int		height;
	int		floor[3];
	int		ceeling[3];
	int		mapcheck;
	double	playerx;
	double	playery;
	int		td;
	int		wd;
	int		sd;
	double	ix;
	double	jy;
	double	rt;
	char	*maponestr;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	char	**map2d;
	char	*fl;
	char	*cl;
	int		choice;
}				t_mapdata;

typedef struct	s_lst
{
	void			*content;
	struct s_lst	*next;
}				t_list;

# define FL map->fl
# define PY map->playery
# define PX map-> playerx
# define CL map->cl
# define WH map->width
# define HT map->height
# define NO map->north
# define SO map->south
# define WE map->west
# define EA map->east
# define S map->sprite
# define F map->floor
# define C map->ceeling
# define MAP0 map->maponestr
# define MAP2D map->map2d
# define MCHECK map->mapcheck
# define TD map->td
# define WD map->wd
# define RT map->rt
# define J_Y map->jy
# define I_X map->ix
# define SD map->sd
# define HH map->choice
int 			ft_interhor(t_mapdata *map, int i, int j);
int 			ft_interver(t_mapdata *map, int i, int j);
void			ft_init(t_mapdata *map);
void			ft_error(char *s);
void			ft_intro(int fd);
void			ft_readno(int fd, t_mapdata *map);
void			ft_north(t_mapdata *map, char *line);
void			ft_south(t_mapdata *map, char *line);
void			ft_west(t_mapdata *map, char *line);
void			ft_east(t_mapdata *map, char *line);
void			ft_sprite(t_mapdata *map, char *line);
void			ft_floor(t_mapdata *map, char *line);
void			ft_drawmap(t_mapdata *map);
void			ft_ceeling(t_mapdata *map, char *line);
void			ft_fetch(char *line, int *height, int *width, t_mapdata *map);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst);
void			ft_matrix(t_mapdata *map, char *line);
void			ft_joindouble(t_mapdata *map);
void			treatthatmap(t_mapdata *map);
void			ft_read(int fd, t_mapdata *map);
void			*g_mlx_win;
void			*g_mlx_ptr;
int				ft_fill(char **last, int fd);
int				get_next_line(int fd, char **line);
int				ft_intlen(int i);
int				ft_isdigit(int c);
int				ft_conds(int fd, char **l);
int				ft_free(char *fr, int k);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*itoa_base(long long n, char *base);
int				helpread(char *line, t_mapdata *map, int r);
int				count_words(const char *str, char c);
int				g_tiles;
int				g_rows;
int				g_case;
double			g_horx;
double			g_hory;
double			g_verx;
double			g_very;
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_substr(char *dst, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char const *s, char c);
int				ft_check_fc(int i, int j, int k);
void			ft_fill_fc(t_mapdata *map);
void			ft_drawmap(t_mapdata *map);
void 			ft_check_stuff(int y, int x, t_mapdata *map);
void			ft_draw_player(int color, t_mapdata *map);
t_list			*ft_lstnew(void *content);
void			ft_drawall(t_mapdata *map);
void    		ft_drawsquare(int y, int x, int color, t_mapdata *map);
int    			deal_key(int key, t_mapdata *map);
t_list			*g_mylist;
void    		*g_img_ptr;
int     		*g_img_data;
int				g_playerx;
int				g_playery;
int				g_loli;
int     		draw(t_mapdata *map);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strtrim(char *s1, const char *set);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
int				ft_cw(char i);

#endif
