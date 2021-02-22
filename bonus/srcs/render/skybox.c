/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:31:17 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/22 13:23:26 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

double	get_sbstep(int txtrw, int screenw)
{
	if (txtrw > screenw)
		return (txtrw / screenw / 2);
	else
		return (screenw / txtrw);
}

void	draw_skybox(t_all *all, int y, t_texture txtr, double facing)
{
	double	step;
	int		tex_y;
	int		tex_x;
	int		x;
	int		i = 500;
	int		j = 500;
	char	buffer[80];

	step = get_sbstep(txtr.wid, all->win->wid);
	tex_x = facing * (txtr.wid - 1);
	tex_y = 2 * y / (double)all->win->len * (txtr.hei - 1);
	sprintf(buffer, "Angle : %4.f", facing);
	mlx_string_put(all->win->mlx, all->win, i, j, 0xFFFFFF, "test");
	x = - 1;
	while (++x < all->win->wid)
	{
		if (all->ray->x_drawstart[x] >= y)
		{
			set_pixel(all->win, x, y,
					*get_pixel(txtr.img, (int)tex_x, (int)tex_y));
		}
		tex_x += step;
	}
}
