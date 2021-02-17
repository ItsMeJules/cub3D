/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:34:11 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/17 17:01:02 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_txtr(t_all *all, int y, t_texture txtr)
{
	int			x;
	int			cx;
	int			cy;
	t_floor		*floor;

	x = -1;
	floor = all->floor;
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
		draw_vert(all, txtr, x, y);
	}
}

void	calc_line_ray(t_all *all, t_floor *floor, int y, float pos_z)
{
	int		pos;

	pos = y - all->win->len / 2;
	floor->row_dst = pos_z / pos;
	floor->f_stepx = floor->row_dst * floor->diff_x / all->win->wid;
	floor->f_stepy = floor->row_dst * floor->diff_y / all->win->wid;
	floor->floor_x = all->pos.pos_x + floor->row_dst * floor->ray_dir_x0;
	floor->floor_y = all->pos.pos_y + floor->row_dst * floor->ray_dir_y0;
}

void	vert_cast(t_all *all)
{
	int		y;
	float	pos_z;

	pos_z = all->win->len * 0.5;
	y = all->win->len / 2;
	all->floor->ray_dir_x0 = all->pos.dir_x - all->pos.plane_x;
	all->floor->ray_dir_y0 = all->pos.dir_y - all->pos.plane_y;
	all->floor->ray_dir_x1 = all->pos.dir_x + all->pos.plane_x;
	all->floor->ray_dir_y1 = all->pos.dir_y + all->pos.plane_y;
	all->floor->diff_x = all->floor->ray_dir_x1 - all->floor->ray_dir_x0;
	all->floor->diff_y = all->floor->ray_dir_y1 - all->floor->ray_dir_y0;
	while (++y < all->win->len)
	{
		calc_line_ray(all, all->floor, y, pos_z + all->pos.jump_crouch);
		init_txtr(all, y, all->txtrs[F_TXTR]);
		if (all->skybox)
		{
			//draw_skybox(all, y, );
			continue ;
		}
		calc_line_ray(all, all->floor, y, pos_z - all->pos.jump_crouch);
		init_txtr(all, all->win->len - y - 1, all->txtrs[C_TXTR]);
	}
}
