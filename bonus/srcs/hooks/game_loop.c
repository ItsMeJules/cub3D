/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:57:57 by jules             #+#    #+#             */
/*   Updated: 2021/03/02 15:42:34 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int		game_loop(t_all *all)
{
	char	buffer[80];

	keys_manager(all);
	ray_cast(all);
	vert_cast(all);
	sprite_cast(all);
	draw_map(all);
	draw_hud(all);
	push_image(all->win);
	sprintf(buffer, "Position : %.2f %.2f", all->pos.pos_x, all->pos.pos_y);
	mlx_string_put(all->win->mlx, all->win->win, 100, 500, 0xFFFFFF, buffer);
	return (1);
}
