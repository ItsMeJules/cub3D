/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:13:57 by jules             #+#    #+#             */
/*   Updated: 2021/02/17 11:24:40 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	push_image(t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->img->img, 0, 0);
}

char	*get_pixel(t_img *img, int x, int y)
{
	return (img->addr + (y * img->line_l + x * 4));
}

void	set_pixel(t_win *win, int x, int y, int color)
{
	*(unsigned int *)get_pixel(win->img, x, y) = color;
}
