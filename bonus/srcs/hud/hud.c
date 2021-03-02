/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:42:42 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/02 17:30:40 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	init_hud(t_all *all)
{
	all->hud.hbar_startx = all->win->wid - HBAR_X_OFFSET - HBAR_WID;
	all->hud.hbar_endx = all->win->wid - HBAR_X_OFFSET;
	all->hud.hbar_starty = (int)(all->win->len / 4 * 1.5);
	all->hud.hbar_endy = (int)(all->win->len / 4 * 2.5);
	all->hud.hstep = (int)(all->hud.hbar_endy - all->hud.hbar_starty
			/ all->player.health);
}

int		get_cfrom_health(t_player player)
{
	if (player.health)
}

void	draw_health_bar(t_all *all)
{
	t_line line;
	
	line.x0 = all->hud.hbar_startx;
	line.y0 = all->hud.hbar_starty;
	line.x1 = all->hud.hbar_endx;
	line.y1 = all->hud.hbar_endy;
	draw_rect(line, all->win, 0x000000);
	line.x0++;
	line.y0++;
	fill_px(line, all->win, 0x32CD32);

}

void	draw_hud(t_all *all)
{
	init_hud(all);
	draw_health_bar(all);	
}
