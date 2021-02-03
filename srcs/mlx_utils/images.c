/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:13:57 by jules             #+#    #+#             */
/*   Updated: 2021/02/03 14:24:05 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	push_image(t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->img->img, 0, 0);
}

int		*get_pixel(t_img *img, int x, int y)
{
	return ((int *)img->addr + (y * img->line_l + x * (img->bpp / 8)));
}

void	set_pixel(t_win *win, int x, int y, int color)
{
	*get_pixel(win->img, x, y) = color;
}
