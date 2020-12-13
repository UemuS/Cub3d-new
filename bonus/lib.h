/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:34:33 by yihssan           #+#    #+#             */
/*   Updated: 2020/12/13 00:15:41 by yihssan          ###   ########.fr       */
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

typedef struct		s_prite
{
	float			x;
	float			x_off;
	float			y;
	float			y_off;
	float			dist;
	float			size;
	int				width;
	int				height;
	int				*sdata;
	int				ditch;
	int				ditch1;
	void			*simg;
}					t_sprite;

typedef	struct		s_list
{
	int				width;
	int				height;
	int				floor[3];
	int				ceeling[3];
	int				mapcheck;
	double			playerx;
	double			playery;
	int				td;
	int				wd;
	int				sd;
	int				jp;
	int				jpincr;
	int				jmp;
	int				jmpincr;
	int				checkjmp;
	double			ix;
	double			jy;
	double			rt;
	char			*maponestr;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			**map2d;
	char			*fl;
	char			*cl;
	int				choice;
	double			wallhx;
	double			wallhy;
	double			wallvx;
	double			wallvy;
	double			wallx;
	double			wally;
	void			*xpm_no;
	void			*xpm_so;
	void			*xpm_ea;
	void			*xpm_we;
	void			*xpm_hud;
	void			*xpm_fl;
	void			*xpm_vis;
	int				*texture_buffer_no;
	int				*texture_buffer_so;
	int				*texture_buffer_ea;
	int				*texture_buffer_we;
	int				*texture_buffer_hud;
	int				*texture_buffer_fl;
	int				*texture_buffer_vis;
	int				color_buffer_texture;
	int				txt_wh_no;
	int				txt_ht_no;
	int				txt_wh_so;
	int				txt_ht_so;
	int				txt_wh_ea;
	int				txt_ht_ea;
	int				txt_wh_we;
	int				txt_ht_we;
	int				txt_wh_hud;
	int				txt_ht_hud;
	int				txt_flw;
	int				txt_flh;
	int				door;
	int				*raydist;
	char			*sprite;
	t_sprite		*sprites;
}					t_mpdt;

typedef struct		s_lst
{
	void			*content;
	struct s_lst	*next;
}					t_list;

typedef struct		s_bmp_file
{
	char			byte_type[2];
	unsigned int	byte_size;
	unsigned int	byte_reserved;
	unsigned int	byte_offset;
	unsigned		header_size;
	int				image_width;
	int				image_height;
	unsigned short	color_planes;
	unsigned short	bits_per_pixel;
	unsigned int	compression;
	unsigned int	image_size;
	int				bits_xpels_per_meter;
	int				bits_ypels_per_meter;
	unsigned int	total_colors;
	unsigned int	important_colors;
}					t_bmp_file;

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
# define F map->floor
# define C map->ceeling
# define S map->sprite
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
# define JP map->jp
# define JPINCR map->jpincr
# define JMP map->jmp
# define JMPINCR map->jmpincr
# define CHCJMP map->checkjmp
# define TL_SZE 64
# define MIN_WIDTH 500
# define MAX_WIDTH 2560
# define MAX_HEIGHT 1440
# define WALLHX	map->wallhx
# define WALLHY map->wallhy
# define WALLVX map->wallvx
# define WALLVY map->wallvy
# define WALLX map->wallx
# define WALLY map->wally
# define XPM_NO map->xpm_no
# define XPM_SO map->xpm_so
# define XPM_EA map->xpm_ea
# define XPM_WE map->xpm_we
# define XPM_SP map->xpm_SP
# define XPM_FL map->xpm_fl
# define XPM_HUD map->xpm_hud
# define XPM_VIS map->xpm_vis
# define TXT_BUF_NO map->texture_buffer_no
# define TXT_BUF_SO map->texture_buffer_so
# define TXT_BUF_EA map->texture_buffer_ea
# define TXT_BUF_WE map->texture_buffer_we
# define TXT_BUF_SP map->texture_buffer_sp
# define TXT_BUF_FL map->texture_buffer_fl
# define TXT_BUF_HUD map->texture_buffer_hud
# define TXT_BUF_VIS map->texture_buffer_vis
# define COLOR_BUF_TXT map->color_buffer_texture
# define TXT_WH_NO map->txt_wh_no
# define TXT_HT_NO map->txt_ht_no
# define TXT_WH_SO map->txt_wh_so
# define TXT_HT_SO map->txt_ht_so
# define TXT_WH_EA map->txt_wh_ea
# define TXT_HT_EA map->txt_ht_ea
# define TXT_WH_WE map->txt_wh_we
# define TXT_HT_WE map->txt_ht_we
# define TXT_WH_HUD map->txt_wh_hud
# define TXT_HT_HUD map->txt_ht_hud
# define TXT_FLW map->txt_flw
# define TXT_FLH map->txt_flw
# define DOOR map->door
# define SPRITES map->sprites
# define SH map->sprites[k].height
# define SW map->sprites[k].width
# define DT map->sprites[k].ditch
# define DT1 map->sprites[k].ditch1
# define RAYDIST map->raydist
# define RAD(x) (x * (M_PI / 180))
# define DEG(x) ((180 / M_PI) * x)

void				ft_init(t_mpdt *map);
int					ft_error(char *s);
void				ft_intro(int fd);
void				ft_readno(int fd, t_mpdt *map);
void				ft_north(t_mpdt *map, char *line);
void				ft_south(t_mpdt *map, char *line);
void				ft_west(t_mpdt *map, char *line);
void				ft_east(t_mpdt *map, char *line);
void				ft_sprite(t_mpdt *map, char *line);
void				ft_floor(t_mpdt *map, char *line);
void				ft_drawmap(t_mpdt *map);
void				ft_ceeling(t_mpdt *map, char *line);
void				ft_fetch(char *line, int *height, int *width, t_mpdt *map);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst);
void				ft_matrix(t_mpdt *map, char *line);
void				ft_joindouble(t_mpdt *map);
void				treatthatmap(t_mpdt *map);
void				ft_read(int fd, t_mpdt *map);
int					ft_fill(char **last, int fd);
int					get_next_line(int fd, char **line);
int					ft_intlen(int i);
int					ft_isdigit(int c);
int					ft_conds(int fd, char **l);
int					ft_free(char *fr, int k);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
char				*itoa_base(long long n, char *base);
int					helpread(char *line, t_mpdt *map, int r);
int					count_words(const char *str, char c);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_substr(char *dst, unsigned int start, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char *s1, char *s2);
char				**ft_split(char const *s, char c, t_mpdt *map);
int					ft_check_fc(int i, int j, int k);
void				ft_fill_fc(t_mpdt *map);
void				ft_drawmap(t_mpdt *map);
void				ft_check_stuff(int y, int x, t_mpdt *map);
void				ft_draw_player(t_mpdt *map);
t_list				*ft_lstnew(void *content);
void				ft_drawall(t_mpdt *map);
void				ft_drawsquare(int y, int x, int color, t_mpdt *map);
int					deal_key(int key, t_mpdt *map);
int					release_key(int key, t_mpdt *map);
int					draw(t_mpdt *map);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strtrim(char *s1, const char *set);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *s, size_t n);
int					ft_cw(char i);
double				colmdist(t_mpdt *map, double rayangle);
void				castrays(t_mpdt *map);
void				drawray(t_mpdt *map, double angle);
int					ft_longest_array(t_mpdt *map);
int					hex_to_dec(char *hex);
void				save_bmp(t_mpdt *map);
double				colmdistsprite(t_mpdt *map, double rayangle);
void				castrayssp(t_mpdt *map);
int					lifebar(t_mpdt *map);
double				ft_fmod(double a, double b);
void				init_spt(t_mpdt *map);
void				ft_helpdrawasquare(t_mpdt *map);
void				to_sprite(t_mpdt *map, int m);
int					check_vision_ht(t_mpdt *map);
int					check_vision_wh(t_mpdt *map);
void				rayfacing(double rayangle);
double				normalangle(double *rayangle);
void				initwallxy(t_mpdt *map);
void				ft_mmwindow(t_mpdt *map, int *height, int *width);
int					helptreatingthatmap(char c);
int					ft_cw(char i);
void				ft_cw_er(t_mpdt *map, int i, int j);
void				ft_jmp(t_mpdt *map);
int					ft_before_map(t_mpdt *map, char *line);
void				ft_ayaya(t_mpdt *map);
int					ft_quit(void);
t_list				*g_mylist;
void				*g_img_ptr;
int					*g_img_data;
int					g_playerx;
int					g_playery;
int					g_loli;
int					g_hith;
int					g_hitv;
int					g_hit_side;
int					g_distancefromtop;
int					g_checksave;
int					g_tiles;
int					g_rows;
int					g_case;
int					g_rayright;
int					g_rayleft;
int					g_rayup;
int					g_exit;
int					g_raydown;
int					g_fl;
int					g_cl;
void				*g_mlx_win;
void				*g_mlx_ptr;
int					g_checkdoor;
int					g_chkh;
int					g_chkv;
int					g_dec;
int					g_count;
int					g_cac;
#endif
