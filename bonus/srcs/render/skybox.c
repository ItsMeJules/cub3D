/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:31:17 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/06 01:15:54 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	draw_skybox(t_all *all, int y, t_texture txtr)
{
	int			tex_y;
	int			tex_x;
	int			x;
	double		texp;
	t_skybox	skybox;

	skybox = all->skybox;
	tex_y = all->skybox.ldiff * skybox.ydiff + y * skybox.ydiff * (txtr.hei - 1);
	printf("%f\n", ((float)all->win->len - all->pos.pitch) * skybox.ydiff + y * skybox.ydiff);
	x = -1;
	while (++x < all->win->wid)
	{
		texp = (skybox.face_left + skybox.xdiff * x) * (txtr.wid - 1);
		tex_x = (int)texp;
		if (all->ray->x_drawstart[x] < y)
			continue ;
		set_pixel(all->win, x, y,
				*get_pixel(txtr.img, (int)tex_x, (int)tex_y));
	}
}
