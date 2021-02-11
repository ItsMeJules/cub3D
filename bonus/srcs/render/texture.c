/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:11:07 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/11 17:23:58 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

//bug into feature: le LSD avec le getrgb de 42 docs
int		depth_shade(int color, double dist)
{
	int		r;
	int 	g;
	int 	b;
	double	shade;
	
	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	shade = dist / PLAYER_VIEW_DIST > 1 ? 1 : dist / PLAYER_VIEW_DIST;
	return (create_trgb(0, r - (int)(r * shade), g - (int)(g * shade), b - (int)(b * shade)));
}

void	draw_ce_gr(t_all *all, t_ray *ray, int x)
{
	int y;

	y = -1;
	while (++y < ray->draw_start)
		set_pixel(all->win, x, y, all->map->ce);
	y = ray->draw_end;
	while (++y < all->win->len)
		set_pixel(all->win, x, y, all->map->gr);
}

void	draw_txtr(t_all *all, t_ray *ray, t_texture *txtr, int x)
{
	int		y;
	double	text_pos;
	double	step;

	y = ray->draw_start - 1;
	step = 1.0 * txtr->hei / ray->line_h;
	text_pos = (ray->draw_start - all->win->len / 2 + ray->line_h / 2) * step;
	while (++y < ray->draw_end)
	{
		ray->text_y = (int)text_pos & (txtr->hei - 1);
		text_pos += step;
		set_pixel(all->win, x, y, depth_shade(*(int*)get_pixel(txtr->img,
					ray->text_x, ray->text_y), ray->perp_wall_dist));
	}
	draw_ce_gr(all, ray, x);
}
