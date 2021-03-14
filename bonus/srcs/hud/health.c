/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:14:34 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/14 01:06:01 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_cfrom_health(double health_r)
{
	int		red;
	int		green;

	red = ft_min(2 - 2.0f * health_r, 1) * 255;
	green = ft_min(2.0f * health_r, 1) * 255;
	return (create_trgb(0, red, green, 0));
}

void	draw_health_bar(t_all *all)
{
	t_line	line;
	double	health_r;
	double	fill_r;

	if (all->hud.hbar_startx <= 0
			|| all->hud.hbar_endx >= all->win->wid
			|| all->hud.hbar_starty <= 0
			|| all->hud.hbar_endy >= all->win->len)
		return ;
	health_r = (double)all->player.health / (double)PLAYER_MAX_HEALTH;
	line.x0 = all->hud.hbar_startx;
	line.y0 = all->hud.hbar_starty;
	line.x1 = all->hud.hbar_endx;
	line.y1 = all->hud.hbar_endy;
	draw_rect(line, all->win, 0x000000);
	line.x0++;
	line.y0++;
	fill_r = (line.y1 - line.y0) / (double)PLAYER_MAX_HEALTH;
	line.y0 -= fill_r * (all->player.health - PLAYER_MAX_HEALTH);
	fill_px(line, all->win, get_cfrom_health(health_r));
}
