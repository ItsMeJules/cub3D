/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:11:07 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/03 14:24:01 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_txtr(t_all *all, t_ray *ray, t_texture *txtr)
{
	int	y;
	int	text_pos;
	int	step;

	y = ray->draw_start - 1;
	step = 1.0 * txtr->len / ray->line_h;
	text_pos = (ray->draw_start - all->win->len / 2 + ray->line_h / 2) * step;
	while (++y <= ray->draw_end)
	{
		ray->text_y = text_pos & (txtr->len - 1);
		text_pos += step;
		set_pixel(all->win, , y, *get_pixel(txtr->img,
					ray->text_x, ray->text_y));
		//ptet mettre des couleurs plus sombres sur les teks
	}
}
