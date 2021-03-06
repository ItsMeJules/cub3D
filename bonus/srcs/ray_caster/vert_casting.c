/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:34:11 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/06 13:37:02 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

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

void	calc_line_ray(t_all *all, t_floor *floor, int pos)
{
	float	cam_z;

	cam_z = floor->is_floor ? (0.5 * all->win->len + all->pos.pos_z)
				: (0.5 * all->win->len - all->pos.pos_z);
	floor->row_dst = cam_z / pos;
	floor->f_stepx = floor->row_dst * floor->diff_x / all->win->wid;
	floor->f_stepy = floor->row_dst * floor->diff_y / all->win->wid;
	floor->floor_x = all->pos.pos_x + floor->row_dst * floor->ray_dir_x0;
	floor->floor_y = all->pos.pos_y + floor->row_dst * floor->ray_dir_y0;
}

double	get_face(double dirx, double diry)
{
	return (fabs(atan2(dirx, diry) * 180 / M_PI - 180) / 360);
}

void	init_floorcei(t_all *all)
{
	double	facing2;

	all->floor->ray_dir_x0 = all->pos.dir_x - all->pos.plane_x;
	all->floor->ray_dir_y0 = all->pos.dir_y - all->pos.plane_y;
	all->floor->ray_dir_x1 = all->pos.dir_x + all->pos.plane_x;
	all->floor->ray_dir_y1 = all->pos.dir_y + all->pos.plane_y;
	all->floor->diff_x = all->floor->ray_dir_x1 - all->floor->ray_dir_x0;
	all->floor->diff_y = all->floor->ray_dir_y1 - all->floor->ray_dir_y0;
	all->skybox.face_left = get_face(all->floor->ray_dir_x0, all->floor->ray_dir_y0);
	if (all->skybox.on && all->skybox.xdiff)
		return ;
	facing2 = get_face(all->floor->ray_dir_x1, all->floor->ray_dir_y1);
	all->skybox.xdiff = fabs((facing2 - all->skybox.face_left)) / all->win->wid;
	all->skybox.ydiff = (float)1 / (all->win->len * 1.5);
	all->skybox.ldiff = (all->win->len - all->pos.pitch) * all->skybox.ydiff;
}

void	vert_cast(t_all *all)
{
	int		y;
	int		pos;

	y = -1;
	init_floorcei(all);
	while (++y < all->win->len)
	{
		all->floor->is_floor = y > all->win->len / 2 + all->pos.pitch;
		pos = all->floor->is_floor ? (y - all->win->len / 2 - all->pos.pitch)
					: (all->win->len / 2 - y + all->pos.pitch);
		calc_line_ray(all, all->floor, pos); 
		if (all->floor->is_floor)
			init_txtr(all, y, all->txtrs[F_TXTR]);
		else
		{
			if (all->skybox.on)
			{
				draw_skybox(all, y, all->txtrs[C_TXTR]);
				continue ;
			}
			init_txtr(all, y, all->txtrs[C_TXTR]);
		}
	}
}
