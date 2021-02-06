/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:38:40 by jules             #+#    #+#             */
/*   Updated: 2021/02/06 22:11:51 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

void	get_delta_dist(t_ray *ray)
{
	if (ray->dir_y == 0)
		ray->delta_dist_x = 0;
	else if (ray->dir_x == 0)
		ray->delta_dist_x = 1;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_x == 0)
		ray->delta_dist_y = 0;
	else if (ray->dir_y == 0)
		ray->delta_dist_y = 1;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
}

void	get_step_n_side_dist(t_ray *ray, t_pos pos)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (pos.pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - pos.pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (pos.pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - pos.pos_y) * ray->delta_dist_y;
	}
}

void	get_perp_dist(t_ray *ray, t_pos pos, t_win *win)
{
	if (ray->side == 0 || ray->side == 1)
		ray->perp_wall_dist = (ray->map_x - pos.pos_x + (1 - ray->step_x) / 2)
			/ ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - pos.pos_y + (1 - ray->step_y) / 2)
			/ ray->dir_y;
	ray->line_h = (int)(win->len / ray->perp_wall_dist);
}

void	init_ray(t_ray *ray, t_pos pos, int x, int wid)
{
	ray->camera_x = 2 * x / (double)wid - 1;
	ray->dir_x = pos.dir_x + pos.plane_x * ray->camera_x;
	ray->dir_y = pos.dir_y + pos.plane_y * ray->camera_x;
	ray->map_x = (int)pos.pos_x;
	ray->map_y = (int)pos.pos_y;
	ray->hit = 0;
	get_delta_dist(ray);
	get_step_n_side_dist(ray, pos);
}

void	raycast(t_all *all)
{
	int	x;
	
	x = -1;
	while (++x < all->win->wid)
	{
		init_ray(all->ray, all->pos, x, all->win->wid);
		dda(all->ray, all->map);
		get_perp_dist(all->ray, all->pos, all->win);
		draw_col(all, x);
	}
	if (all->save)
	{
	//	save_bmp(all->);
		close_w(all);
	}
}
