/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 09:36:58 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/27 14:44:56 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	draw_player(t_pos pos, t_win *win, int dir_len)
{
	int		i;
	int		j;
	int		x_px;
	int		y_px;
	t_line	line;

	x_px = MAP_X_PX_OFFSET + MAP_ELEM_PX_SIZE * MAP_VIEW_DIST;
	y_px = win->len - MAP_Y_PX_OFFSET - MAP_ELEM_PX_SIZE * MAP_VIEW_DIST;
	i = x_px - 1;
	while (++i < win->wid && i < x_px + MAP_PLAYER_PX_SIZE - 1)
	{
		j = y_px - 1;
		while (++j < win->len && j < y_px + MAP_PLAYER_PX_SIZE - 1)
			set_pixel(win, i, j, MAP_PLAYER_COLOR);
	}
	line.x0 = x_px + MAP_PLAYER_PX_SIZE / 2 + (MAP_PLAYER_PX_SIZE + dir_len)
		* pos.dir_x;
	line.y0 = y_px + MAP_PLAYER_PX_SIZE / 2 + (MAP_PLAYER_PX_SIZE + dir_len)
		* pos.dir_y;
	line.x1 = x_px + MAP_PLAYER_PX_SIZE / 2;
	line.y1 = y_px + MAP_PLAYER_PX_SIZE / 2;
	line.dx = abs(line.x1 - line.x0);
	line.dy = abs(line.y1 - line.y0);
	draw_line(line, win, 2, 0xFF0000);
}

void	draw_piece(t_all *all, int xiter, int yiter)
{
	int	i;
	int	j;
	int	x_px;
	int	y_px;

	x_px = all->minimap.x_drawstart + (xiter - get_decimals(all->pos.pos_x))
		* MAP_ELEM_PX_SIZE;
	y_px = all->minimap.y_drawstart + ((yiter - get_decimals(all->pos.pos_y))
			* MAP_ELEM_PX_SIZE);
	i = x_px + 1;
	while (--i > x_px - MAP_ELEM_PX_SIZE)
	{
		if (i < all->minimap.minx_draw || i > all->minimap.maxx_draw)
			continue ;
		j = y_px + 1;
		while (--j > y_px - MAP_ELEM_PX_SIZE)
		{
			if (j > all->minimap.miny_draw || j < all->minimap.maxy_draw)
				continue ;
			set_pixel(all->win, i, j, MAP_WALL_COLOR);
		}
	}
}

void	init_minimap(t_all *all)
{
	all->minimap.y_drawstart = all->win->len - MAP_Y_PX_OFFSET -
		MAP_ELEM_PX_SIZE * MAP_VIEW_DIST * 2 + MAP_ELEM_PX_SIZE;
	all->minimap.x_drawstart = MAP_X_PX_OFFSET + MAP_ELEM_PX_SIZE;
	all->minimap.minx_draw = MAP_X_PX_OFFSET + MAP_ELEM_PX_SIZE;
	all->minimap.miny_draw = all->win->len - MAP_X_PX_OFFSET - MAP_ELEM_PX_SIZE;
	all->minimap.maxx_draw = MAP_X_PX_OFFSET
		+ (MAP_ELEM_PX_SIZE * MAP_VIEW_DIST * 2) - MAP_ELEM_PX_SIZE;
	all->minimap.maxy_draw = all->win->len - MAP_X_PX_OFFSET
		- (MAP_ELEM_PX_SIZE * MAP_VIEW_DIST * 2) + MAP_ELEM_PX_SIZE;
}

void	draw_map(t_all *all)
{
	int		x;
	int		y;
	int		xiter;
	int		yiter;
	char	c;

	if (all->win->wid < MAP_X_PX_OFFSET + MAP_ELEM_PX_SIZE * MAP_VIEW_DIST * 2
		|| all->win->len < MAP_Y_PX_OFFSET +
			MAP_ELEM_PX_SIZE * MAP_VIEW_DIST * 2)
		return ;
	x = (int)all->pos.pos_x - MAP_VIEW_DIST - 1;
	while (++x < (int)all->pos.pos_x + MAP_VIEW_DIST)
	{
		if (x < 0 || x > all->map->wid)
			continue ;
		y = (int)all->pos.pos_y - MAP_VIEW_DIST - 1;
		while (++y < (int)all->pos.pos_y + MAP_VIEW_DIST)
		{
			if (y < 0 || y > all->map->len)
				continue ;
			xiter = x - (int)all->pos.pos_x + MAP_VIEW_DIST;
			yiter = y - (int)all->pos.pos_y + MAP_VIEW_DIST;
			 if ((c = elem_at(x, y, all->map)) == '1')
				draw_piece(all, xiter, yiter);
		}
	}
	draw_player(all->pos, all->win, 5);
}
