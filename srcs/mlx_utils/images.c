/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:13:57 by jules             #+#    #+#             */
/*   Updated: 2021/02/02 13:53:51 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	push_image(t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->img->img, 0, 0);
}

void	set_pixel(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->img->addr + (y * win->img->line_l + x * (win->img->bpp / 8));
	*(unsigned int *)dst = color;
}
