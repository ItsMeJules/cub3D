/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:11:07 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/02 15:37:34 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vert(t_all *all, t_texture txtr, int x, int y)
{
	int			pixel;
	t_floor		*floor;

	floor = all->floor;
	pixel = *get_pixel(txtr.img, floor->tx, floor->ty);
	set_pixel(all->win, x, y, depth_shade(pixel, floor->row_dst));
}

void	draw_sprite(t_sprite *s, t_ray *r, t_win *win, t_texture txtr)
{
	int	stripe;
	int	text_x;
	int	y;
	int	d;
	int	color;

	stripe = s->draw_startx - 1;
	while (++stripe < s->draw_endx)
	{
		text_x = (int)(256 * (stripe - (-s->wid / 2 + s->screen_x))
					* txtr.wid / s->wid) / 256;
		if (s->transform_y > 0 && stripe > 0 && stripe < win->wid
				&& s->transform_y < r->z_buffer[stripe])
		{
			y = s->draw_starty - 1;
			while (++y < s->draw_endy)
			{
				d = (y - s->jc_offset) * 256 - win->len * 128 + s->hei * 128;
				if ((color = *get_pixel(txtr.img, text_x,
								((d * txtr.hei) / s->hei) / 256)) != 0)
					set_pixel(win, stripe, y, depth_shade(color, s->transform_y));
			}
		}
	}
}

void	draw_txtr(t_all *all, t_ray *ray, t_texture *txtr, int x)
{
	int		y;
	double	text_pos;
	double	step;

	y = ray->draw_start - 1;
	step = 1.0 * txtr->hei / ray->line_h;
	text_pos = (ray->draw_start - ray->jc_offset - all->win->len / 2 + ray->line_h / 2) * step;
	while (++y < ray->draw_end)
	{
		ray->text_y = (int)(text_pos) & (txtr->hei - 1);
		text_pos += step;
		set_pixel(all->win, x, y, depth_shade(*get_pixel(txtr->img,
					ray->text_x, ray->text_y), ray->perp_wall_dist));
	}
}
