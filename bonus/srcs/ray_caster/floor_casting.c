/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:34:11 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/16 17:22:51 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	init_txtr(t_all *all, t_floor *floor, t_texture txtr, int y)
{
	int	x;
	int	cx;
	int	cy;

	x = -1;
	while (++x < all->win->wid)
	{
		floor->floor_x += floor->f_stepx;
		floor->floor_y += floor->f_stepy;
		if (all->ray->x_drawstart[x] < y && all->ray->x_drawend[x] > y)
			continue ;
		cx = (int)floor->floor_x;
		cy = (int)floor->floor_y;
		floor->tx = (int)(txtr.wid * (floor->floor_x - cx)) & (txtr.wid - 1);
		floor->ty = (int)(txtr.hei * (floor->floor_y - cy)) & (txtr.hei - 1);
		draw_floor(all, floor, x, y);
		draw_ceiling(all, floor, x, all->win->len - y - 1);
	}
}

void	calc_ray(t_all *all, t_floor *floor, int y, float pos_z)
{
	int		pos;

	pos = y - all->win->len / 2;
	floor->ray_dir_x0 = all->pos.dir_x - all->pos.plane_x;
	floor->ray_dir_y0 = all->pos.dir_y - all->pos.plane_y;
	floor->ray_dir_x1 = all->pos.dir_x + all->pos.plane_x;
	floor->ray_dir_y1 = all->pos.dir_y + all->pos.plane_y;
	floor->row_dst = pos_z / pos;
	floor->f_stepx = floor->row_dst * (floor->ray_dir_x1 - floor->ray_dir_x0) / all->win->wid;
	floor->f_stepy = floor->row_dst * (floor->ray_dir_y1 - floor->ray_dir_y0) / all->win->wid;
	floor->floor_x = all->pos.pos_x + floor->row_dst * floor->ray_dir_x0;
	floor->floor_y = all->pos.pos_y + floor->row_dst * floor->ray_dir_y0;
}

void	floor_cast(t_all *all)
{
	int		y;
	float	pos_z;

	pos_z = all->win->len * 0.5;
	y = pos_z - 1;
	while (++y < all->win->len)
	{
		calc_ray(all, all->floor, y, pos_z);
		init_txtr(all, all->floor, all->txtrs[F_TXTR], y);
	}
}
