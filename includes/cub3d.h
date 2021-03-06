/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:09:22 by jules             #+#    #+#             */
/*   Updated: 2021/03/12 20:46:48 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include "mlx.h"
# include "libft.h"

/*
** EVENTS
*/
# define KEY_PRESS_EVENT 2
# define KEY_RELEASE_EVENT 3
# define DESTROY_WIN_EVENT 33

/*
** TEXTURES INDEX
*/
# define NO_TXTR 0
# define SO_TXTR 1
# define WE_TXTR 2
# define EA_TXTR 3
# define S_TXTR 4

/*
** KEYS
*/
# ifdef LINUX
#  define ESC_KEY 65307
#  define W_KEY 119
#  define A_KEY 97
#  define S_KEY 115
#  define D_KEY 100
#  define ARROW_LEFT_KEY 65361
#  define ARROW_RIGHT_KEY 65363
# else
#  define ESC_KEY 53
#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define ARROW_LEFT_KEY 123
#  define ARROW_RIGHT_KEY 124
# endif

/*
** ERRORS
*/
# define MALLOC_FAILED 0
# define MIN_FILE_ERROR 1
# define OPEN_FILE_FAILED 1
# define GNL_FAILED 2
# define SMTH_INVALID 3
# define TOO_MANY_ARGS 4
# define FILE_WRONG_EXTENSION 5
# define TOO_FEW_ARGS 6
# define PLAYER_POS_ALREADY_SET 7
# define INVALID_CHAR_IN_MAP 8
# define CANT_OPEN_DIR 9
# define MAP_NOT_CLOSED 10
# define NEGATIVE_RESOLUTION 11
# define FILE_MISSING_ARGS 12
# define PLAYER_START_POS_NOT_FOUND 13
# define LINES_AFTER_MAP 14
# define ATTRIBUTE_ALREADY_SET 15
# define MAX_FILE_ERROR 15
# define NO_CUB_FILE_SPECIFIED 16
# define FAILED_TO_LOAD_TXTR 17
# define UNKNOWN_ARGUMENT 18
# define BITMAP_OPEN_ERROR 19
# define COMMAND_TOO_LONG 20

# define PLAYER_MOV_SPEED 0.1
# define PLAYER_ROT_SPEED 0.1

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}				t_img;

typedef struct	s_win {
	void	*mlx;
	void	*win;
	t_img	*img;
	int		len;
	int		wid;
}				t_win;

typedef struct	s_line
{
	int	x0;
	int y0;
	int x1;
	int y1;
	int dx;
	int dy;
}				t_line;

typedef struct	s_pos {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}				t_pos;

typedef struct	s_ray {
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_h;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		text_x;
	int		text_y;
	double	*z_buffer;
}				t_ray;

typedef struct	s_sprite {
	int		txtr;
	double	x;
	double	y;
	double	sx;
	double	sy;
	double	dist;
	double	invdet;
	double	transform_x;
	double	transform_y;
	int		screen_x;
	int		hei;
	int		wid;
	int		draw_startx;
	int		draw_endx;
	int		draw_starty;
	int		draw_endy;
}				t_sprite;

typedef struct	s_texture {
	char	*path;
	int		wid;
	int		hei;
	t_img	*img;
}				t_texture;

typedef struct	s_map {
	char	*line;
	char	start_dir;
	int		len;
	int		wid;
	int		ce;
	int		gr;
	t_pos	p_pos;
}				t_map;

typedef struct	s_keys {
	int	fwrd;
	int	bwrd;
	int	left;
	int	right;
	int	cam_left;
	int	cam_right;
}				t_keys;

typedef struct	s_all {
	int			all_set;
	int			save;
	t_win		*win;
	t_map		*map;
	t_pos		pos;
	t_ray		*ray;
	t_keys		keys;
	t_texture	*txtrs;
	t_list		*sprites;
}				t_all;

/*
** images.c
*/
void			push_image(t_win *win);
void			set_pixel(t_win *win, int x, int y, int color);
char			*get_pixel(t_img *img, int x, int y);

/*
** struct_assigner.c
*/
t_all			*new_all();
void			free_all(t_all *all, int txtrs);

/*
** struct_assignear2.c
*/
void			set_keys(t_all *all);
t_sprite		*new_sprite(int txtr, double x, double y);
void			free_txtrs(t_all *all, int mlx);

/*
** errors_manager.c
*/
int				error(int type, char *print, int ex);

/*
** mlx_manager.c
*/
int				close_w(t_all *all);
void			start_mlx(t_all *all, int save);
void			stop_mlx(t_all *all);

/*
** window_manager.c
*/
void			handle_destroy_win(t_win *win);

/*
** map_manager.c
*/
char			elem_at(int x, int y, t_map *map);

/*
** file_attributes_reader.c
*/
void			verify_nset_ids(t_all *all, char **split, int *err, char *line);

/*
** file_attributes_reader.c
*/
int				check_valid(char *str, int type);
int				arg_len(char **split, int *err, char *line, int type);
int				val_verifs(char **split, int *err, char *line, int type);
char			**count_comas(char *line, int *err);

/*
** file_reader.c
*/
int				gnl_read(t_all *all, int fd, int invalid, char *file);
void			free_after_verifs(int err, char **split);

/*
** map_parser.c
*/
int				valid_map_char(char c);
void			check_map_line(t_map *map, char *line, int *err);
void			make_map(t_all *all);

/*
** map_checker.c
*/
void			check_map(t_all *all);
int				iter_map(int x, int y, t_map *map, char axis);

/*
** keys_hook.c
*/
void			keys_manager(t_all *all);
int				key_press(int keycode, t_all *all);
int				key_rels(int keycode, t_all *all);

/*
** game_loop.c
*/
int				game_loop(t_all *all);

/*
** utils.c
*/
int				create_trgb(int t, int r, int g, int b);
char			*f_lter(char *string, char c);

/*
** raycasting.c
*/
void			raycast(t_all *all);

/*
** draw.c
*/
void			draw_col(t_all *all, int x);

/*
** dda.c
*/
void			dda(t_ray *ray, t_map *map);

/*
** texture.c
*/
void			draw_txtr(t_all *all, t_ray *ray, t_texture *txtr, int x);

/*
** minimap.c
*/
void			draw_map(t_all *all);

/*
** shaped_drawing.c
*/
void			draw_line(t_line line, t_win *win, int thickness, int color);

/*
** moving.c
*/
void			move_forward(t_all *all);
void			move_backward(t_all *all);
void			strafe_left(t_all *all);
void			strafe_right(t_all *all);
void			rotate_camera(int right, double old_dir, double old_plane_x,
				t_all *all);

/*
** bitmap.c
*/
int				save_bmp(t_all *all, char *name);

/*
** player_parser.c
*/
void			set_player_pos(t_all *all, int x, int y, char c);
int				check_player_pos(t_all *all);

/*
** sprite_casting.c
*/
void			sprite_cast(t_all *all);

#endif
