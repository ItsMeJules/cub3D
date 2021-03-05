/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:31:17 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/05 17:19:50 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	draw_skybox(t_all *all, int y, t_texture txtr)
{
	int		tex_y;
	int		tex_x;
	int		x;
	double	texp;

	tex_y = ((y + all->win->len / 2 + all->pos.pitch) / ((double)all->win->len / 2 + all->pos.pitch) - 1) * (txtr.hei - 1);
	printf("%f / %f = %f\n", y + all->win->len / 2 + all->pos.pitch, ((double)all->win->len / 2 + all->pos.pitch), (y + all->win->len / 2 + all->pos.pitch) / ((double)all->win->len / 2 + all->pos.pitch) - 1);
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
