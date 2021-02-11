/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 09:36:58 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/11 15:54:12 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdio.h>

/*
** Notes pour plus tard: si la map est trop grande afficher qu'une partie de
** celle-ci en mimimap.
*/

void	get_color(int *color, char c)
{
	*color = MAP_WALKABLE_COLOR;
	if (c == '1')
		*color = MAP_WALL_COLOR;
	else if (c == ' ')
		*color = MAP_VOID_COLOR;
}

void	draw_wall(int x, int y, t_win *win, char c)
{
	int	i;
	int j;
	int	x_px;
	int	y_px;
	int	color;

	x_px = x * MAP_ELEM_PX_SIZE;
	y_px = y * MAP_ELEM_PX_SIZE;
	i = x_px - 1;
	get_color(&color, c);
	while (++i < win->wid && i < x_px + MAP_ELEM_PX_SIZE)
	{
		j = y_px - 1;
		while (++j < win->len && j < y_px + MAP_ELEM_PX_SIZE)
		{
			if (i == x_px + MAP_ELEM_PX_SIZE - 1
					|| j == y_px + MAP_ELEM_PX_SIZE - 1)
				set_pixel(win, i, j, 0x000000);
			else
				set_pixel(win, i, j, color);
		}
	}
}

void	draw_player(t_pos pos, t_win *win, int dir_len)
{
	int		i;
	int		j;
	int		x_px;
	int		y_px;
	t_line	line;

	x_px = pos.pos_x * MAP_ELEM_PX_SIZE;
	y_px = pos.pos_y * MAP_ELEM_PX_SIZE;
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

void	draw_map(t_all *all)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (++x < all->map->wid - 1)
	{
		y = 0;
		while (++y < all->map->len - 1)
		{
			c = elem_at(x, y, all->map);
			draw_wall(x, y, all->win, c);
		}
	}
	draw_player(all->pos, all->win, 5);
}
