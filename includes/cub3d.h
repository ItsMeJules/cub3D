/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:09:22 by jules             #+#    #+#             */
/*   Updated: 2021/01/24 17:36:29 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <mlx.h>

# define ESC 65307
# define DESTROY_WIN 33

typedef struct	s_mlx {
	void	*mlx;
	void	*win;
	int		length;
	int		width;
}				t_mlx;

typedef struct	s_img {
		void	*img;
		char	*addr;
		int		bpp;
		int		line_l;
		int		endian;
}				t_img;

t_img	*new_image(t_mlx *vars);
void	set_pixel(t_img *img, int x, int y, int color);

void	*error(int type);

#endif
