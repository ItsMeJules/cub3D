/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:42:42 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/14 01:04:25 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	crosshair_part(t_win win, t_line *line, int side)
{
	if (side == 1 || side == 2)
	{
		line->x0 = win.wid / 2 + (side == 2 ? 2 : -2);
		line->y0 = win.len / 2 + (side == 2 ? 2 : -2);
		line->x1 = win.wid / 2 + (side == 2 ? 8 : -8);
		line->y1 = win.len / 2 + (side == 2 ? 8 : -8);
	}
	else
	{
		line->x0 = win.wid / 2 + (side == 3 ? 2 : -2);
		line->y0 = win.len / 2 + (side == 3 ? -2 : 2);
		line->x1 = win.wid / 2 + (side == 3 ? 8 : -8);
		line->y1 = win.len / 2 + (side == 3 ? -8 : 8);
	}
	line->dx = abs(line->x1 - line->x0);
	line->dy = abs(line->y1 - line->y0);
}

void	draw_crosshair(t_hud hud, t_win *win)
{
	if ((hud.tl_line.dx + 2) * 2 >= win->wid
			|| (hud.tl_line.dy + 2) * 2 >= win->len)
		return ;
	draw_line(hud.tl_line, win, 1, CROSSHAIR_COLOR);
	draw_line(hud.tr_line, win, 1, CROSSHAIR_COLOR);
	draw_line(hud.bl_line, win, 1, CROSSHAIR_COLOR);
	draw_line(hud.br_line, win, 1, CROSSHAIR_COLOR);
}

void	init_hud(t_all *all)
{
	if (all->hud.init)
		return ;
	all->hud.hbar_startx = all->win->wid - HBAR_X_OFFSET - HBAR_WID;
	all->hud.hbar_endx = all->win->wid - HBAR_X_OFFSET;
	all->hud.hbar_starty = (int)(all->win->len / 4 * 1.5);
	all->hud.hbar_endy = (int)(all->win->len / 4 * 2.5);
	all->hud.hstep = (int)(all->hud.hbar_endy - all->hud.hbar_starty
			/ all->player.health);
	crosshair_part(*all->win, &all->hud.tl_line, 1);
	crosshair_part(*all->win, &all->hud.br_line, 2);
	crosshair_part(*all->win, &all->hud.tr_line, 3);
	crosshair_part(*all->win, &all->hud.bl_line, 4);
	all->hud.init = 1;
}

void	draw_hud(t_all *all)
{
	init_hud(all);
	draw_health_bar(all);
	if (all->keys.crosshair)
		draw_crosshair(all->hud, all->win);
}
