/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:09:22 by jules             #+#    #+#             */
/*   Updated: 2021/01/28 10:52:15 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <mlx.h>

/* EVENTS */
# define KEY_PRESS_EVENT 2
# define DESTROY_WIN_EVENT 33

/* MASKS */
# define KEY_PRESS_MASK 1L<<0

/* KEYS */
# define ESC_KEY 65307

/* ERRORS */
# define MALLOC_FAILED 0

/* FILE ERRORS */
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
# define MAX_FILE_ERROR 10

typedef struct	s_win {
	void	*mlx;
	void	*win;
	int		len;
	int		wid;
}				t_win;

typedef struct	s_pos {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_pos;

typedef struct	s_img {
		void	*img;
		char	*addr;
		int		bpp;
		int		line_l;
		int		endian;
}				t_img;

typedef struct	s_texture {
	char			*path;
	void			*img;
	unsigned int	x;
	unsigned int	y;
}				t_texture;

typedef struct	s_map {
	char			*line;
	char			start_dir;
	int				len;
	int				wid;
	int				ce;
	int				gr;
	t_pos			p_pos;
}				t_map;

typedef struct	s_all {
	int			all_set;
	t_win		win;
	t_map		map;
	t_texture	so_txtr;
	t_texture	no_txtr;
	t_texture	we_txtr;
	t_texture	ea_txtr;
	t_texture	s_txtr;
		
}				t_all;

/* images.c */
t_img	*new_image(t_win *win);
void	set_pixel(t_img *img, int x, int y, int color);
void	draw_square(t_img *img, int x, int y, int size, int color);

/* struct_assigner.c */
t_all	*new_all();

/* errors_manager.c */
int		error(int type, char *print, int ex);

/* window_manager.c */
void	handle_destroy_win(t_win *win);

/* map_manager.c */
void	print_map(t_map map);
char	elem_at(int x, int y, t_map map);

/* file_attributes_reader.c */
void	verify_nset_ids(t_all *all, char **split, int *err, char *line);

/* file_reader.c */
void	read_file(t_all *all, char *file);

/* map_parser.c */
void	check_map_line(t_map *map, char *line, int *err);
void	make_map(t_all *all);

/* map_checker.c */
void	free_map(t_all *all);
void	check_map(t_all *all);

/* utils.c */
int		create_trgb(int t, int r, int g, int b);

#endif
