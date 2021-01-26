/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:09:22 by jules             #+#    #+#             */
/*   Updated: 2021/01/26 16:19:57 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <mlx.h>

# define CHARS "RSFC"
# define DOUBLE_CHARS "NOSOWEEA"

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
# define MAX_FILE_ERROR 10

typedef struct	s_win {
	void	*mlx;
	void	*win;
	int		length;
	int		width;
}				t_win;

typedef struct	s_pos {
	unsigned int	pos_x;
	unsigned int	pos_y;
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
	unsigned int	len;
	unsigned int	wid;
	unsigned int	ce;
	unsigned int	gr;
	t_texture		so_txtr;
	t_texture		no_txtr;
	t_texture		we_txtr;
	t_texture		ea_txtr;
	t_texture		s_txtr;
	t_pos			p_pos;
}				t_map;

/* images.c */
t_img	*new_image(t_win *win);
void	set_pixel(t_img *img, int x, int y, int color);
void	draw_square(t_img *img, int x, int y, int size, int color);

/* struct_assigner.c */
t_map	*new_map();

/* errors_manager.c */
int		error(int type, char *print, int ex);

/* window_manager.c */
void	handle_destroy_win(t_win *win);

/* map_manager.c */
char	elem_at(int x, int y, t_map map);

/* map_attributes_reader.c */
int		check_line(t_map *map, char *line);

/* map_reader.c */
int		is_dir(char *dir);
void	read_map(t_map *map, char *file);

#endif
