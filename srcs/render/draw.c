/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:19:22 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/03 12:27:35 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h> 
#include "cub3d.h"

void	init_wall_txtr(t_all *all, t_ray *ray)
{
	t_texture	*txtr;

	if (ray->side == 0)	
		txtr = all->ea_txtr;
	else if (ray->side == 1)
		txtr = all->we_txtr;
	else if (ray->side == 2)
		txtr = all->so_txtr;
	else
		txtr = all->no_txtr;
	ray->text_x = (int)(ray->wall_x * (double)txtr->wid);
	if ((ray->side == 0 || ray->side == 1) && ray->dir_x > 0)
		ray->text_x = txtr->wid - ray->text_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->dir_y < 0)
		ray->text_x = txtr->wid - ray->text_x - 1;
	draw_txtr(all, ray, txtr);
}

void	calc_hit(t_all *all, t_win *win, t_ray *ray, t_pos pos)
{
	ray->draw_start = -ray->line_h / 2 + win->len / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_h / 2 + win->len / 2;
	if (ray->draw_end >= win->len)
		ray->draw_end = win->len - 1;
	if (ray->side == 0 || ray->side == 1)
		ray->ray->wall_x = pos.pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = pos.pos_x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	init_wall_txtr(all, ray);
}

void	draw_wall(t_all *all)
{
	calc_hit(all, all->win, all->ray, all->pos);
}

