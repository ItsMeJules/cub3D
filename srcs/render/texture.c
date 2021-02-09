/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:11:07 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/09 14:43:11 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	draw_ce_gr(t_all *all, t_ray *ray, int x)
{
	int y;

	y = -1;
	while (++y < ray->draw_start)
		set_pixel(all->win, x, y, all->map->ce);
	y = ray->draw_end - 1;
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
		set_pixel(all->win, x, y, *(int*)get_pixel(txtr->img,
					ray->text_x, ray->text_y));
	}
	draw_ce_gr(all, ray, x);
}
