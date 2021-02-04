/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 09:36:58 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/04 17:17:15 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdio.h> 

/*
 ** Notes pour plus tard: si la map est trop grande afficher qu'une partie de
 ** celle-ci en mimimap.
 */

void	draw_wall(int x, int y, t_win *win, char c)
{
	int	i;
	int j;
	int	color;

	i = x * MAP_ELEM_PX_SIZE - 1;
	color = c == '1' ? MAP_WALL_COLOR : MAP_WALKABLE_COLOR; 
	while (++i < win->wid && i < x * MAP_ELEM_PX_SIZE + MAP_ELEM_PX_SIZE - 1)
	{
		j = y * MAP_ELEM_PX_SIZE - 1;
		while (++j < win->len && j < y * MAP_ELEM_PX_SIZE + MAP_ELEM_PX_SIZE - 1)
			set_pixel(win, i, j, color);
	}
}

void	draw_map(t_all *all)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (++x < all->map->wid)
	{
		y = 0;
		while (++y < all->map->len)
		{
			c = elem_at(x, y, all->map);
			draw_wall(x, y, all->win, c);
		}
	}
	draw_player(all->pos, all->win);
}
