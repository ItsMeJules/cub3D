/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:23:25 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/09 13:00:35 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

void	write_health(t_all *all, t_hud hud)
{
	char	buffer[80];

	sprintf(buffer, "%3d", all->player.health);
	mlx_string_put(all->win->mlx, all->win->win, hud.hbar_startx,
			hud.hbar_endy + 15, 0xFFFFFF, buffer);
}

void	display_infos(t_all *all)
{
	char	buffer[80];

	sprintf(buffer, "Position : X %.2f Y %.2f", all->pos.pos_x, all->pos.pos_y);
	mlx_string_put(all->win->mlx, all->win->win, all->minimap.x_drawstart,
			all->minimap.y_drawstart - 2, 0xFFFFFF, buffer);
	write_health(all, all->hud);
}
