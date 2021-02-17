/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:21:39 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/17 16:54:58 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	set_player_dir(t_all *all, char c)
{
	all->pos.dir_y = 0;
	all->pos.dir_x = 0;
	all->pos.plane_x = 0;
	all->pos.plane_y = 0;
	if (c == 'N')
	{
		all->pos.dir_y = -1;
		all->pos.plane_x = PLAYER_FOV;
	}
	else if (c == 'W')
	{
		all->pos.dir_x = -1;
		all->pos.plane_y = PLAYER_FOV;
	}
	else if (c == 'E')
	{
		all->pos.dir_x = 1;
		all->pos.plane_y = PLAYER_FOV;
	}
	else if (c == 'S')
	{
		all->pos.dir_y = 1;
		all->pos.plane_x = PLAYER_FOV;
	}
}

void	set_player_pos(t_all *all, int x, int y, char c)
{
	set_player_dir(all, c);
	all->pos.pos_x = (double)x + 0.5;
	all->pos.pos_y = (double)y + 0.5;
	all->pos.move_speed = PLAYER_MOV_SPEED;
	all->pos.rot_speed = PLAYER_ROT_SPEED;
	all->pos.decelerate = 0;
	all->pos.jump_crouch = 0;
	all->pos.in_air = 0;
	all->map->line[all->map->wid * y + x] = '0';
	if (!iter_map(x, y, all->map, 'x') || !iter_map(x, y, all->map, 'y'))
	{
		free_all(all, 1);
		error(MAP_NOT_CLOSED, "", 1);
	}
}

int		check_player_pos(t_all *all)
{
	if (!all->map->start_dir)
	{
		free_all(all, 1);
		error(PLAYER_START_POS_NOT_FOUND, "", 1);
		return (0);
	}
	return (1);
}
