/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:31:17 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/18 17:08:56 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int		get_sbstep(int txtrw, int screenw)
{
	if (txtrw > screenw)
		return (txtrw / screenw);
	else
		return (screenw / txtrw);
}

void	draw_skybox(t_all *all, int y)
{
	double	step;
	double	tex_y;
	double	tex_x;
	double	facing;
	int		x;

	step = get_sbstep(all->txtrs[C_TXTR].wid, all->win->wid);
	tex_y = 2 * y / (double)all->win->len * (all->txtrs[C_TXTR].hei - 1);
	facing = fabs(atan2(all->pos.dir_x, all->pos.dir_y) * 180 / M_PI - 180);
	tex_x = facing / 360 * (all->txtrs[C_TXTR].wid - 1);
	x = -1;
	while (++x < all->win->wid)
	{
		tex_x += step;
		if (all->ray->x_drawstart[x] < y)
			continue ;
		set_pixel(all->win, x, y, *get_pixel(all->txtrs[C_TXTR].img,
					(int)tex_x, (int)tex_y));
	}
}
