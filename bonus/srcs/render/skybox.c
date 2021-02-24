/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:31:17 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/24 08:53:44 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_skybox(t_all *all, int y, t_texture txtr)
{
	int		tex_y;
	int		tex_x;
	int		x;
	double	texp;

	tex_y = 2 * y / (double)all->win->len * (txtr.hei - 1);
	x = -1;
	while (++x < all->win->wid)
	{
		texp = (all->pos.face_left + all->pos.fdiff * x) * (txtr.wid - 1);
		tex_x = (int)texp;
		if (all->ray->x_drawstart[x] < y)
			continue ;
		set_pixel(all->win, x, y,
				*get_pixel(txtr.img, (int)tex_x, (int)tex_y));
	}
}
