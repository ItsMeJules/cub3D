/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:13:45 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/05 15:05:21 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

/*
** exemple de map
** xxxxxxxxxxxxxxx
** 012345678911111
**           01234
** ############### y 0
** #1111111111111# y 1
** #1000000000001# y 2
** #1000000000001# y 3
** #1000000000001# y 4
** #1000000000001# y 5
** #1000000000001# y 6
** #1000000000001# y 7
** #1111111111111# y 8
** ############### y 9
**
** il faut donc commencer a chercher en (1;1)
*/

int		iter_map(int x, int y, t_map *map, char axis)
{
	int		i;
	char	c;
	char	d;

	i = 0;
	c = 0;
	d = 0;
	while (++i)
	{
		if (c != '#' && c != '1')
			c = elem_at(axis == 'x' ? x + i : x, axis == 'y' ? y + i : y, map);
		if (d != '#' && d != '1')
			d = elem_at(axis == 'x' ? x - i : x, axis == 'y' ? y - i : y, map);
		if (c == '1' && d == '1')
			break ;
		else if (c == '#' || d == '#' || c == ' ' || d == ' ')
			return (0);
	}
	return (1);
}

void	set_player_dir(t_all *all, char c)
{
	all->pos.dir_y = 0;
	all->pos.dir_x = 0;
	all->pos.plane_x = 0;
	all->pos.plane_y = 0;
	if (c == 'N')	
	{
		all->pos.dir_y = -1;
		all->pos.plane_x = 0.66;
	}
	else if (c == 'W')
	{
		all->pos.dir_x = -1;
		all->pos.plane_y = 0.66;
	}
	else if (c == 'E')
	{
		all->pos.dir_x = 1;
		all->pos.plane_y = -0.66;
	}
	else if (c == 'S')
	{
		all->pos.dir_y = 1;
		all->pos.plane_x = -0.66;
	}
}

void	set_player_pos(t_all *all, int x, int y, char c)
{
	set_player_dir(all, c);
	all->pos.pos_x = (double)x;	
	all->pos.pos_y = (double)y;	
	all->pos.move_speed = 0.08;
	all->pos.rot_speed = 0.1;
	all->map->line[all->map->wid * y + x] = '0';
	if (!iter_map(x, y, all->map, 'x') || !iter_map(x, y, all->map, 'y'))
	{
		free_all(all);
		error(MAP_NOT_CLOSED, "", 1);
	}
}

int		check_player_pos(t_all *all)
{
	if (!all->map->start_dir)
	{
		free_all(all);
		error(PLAYER_START_POS_NOT_FOUND, "", 1);
		return (0);
	}
	return (1);
}

void	check_map(t_all *all)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	if (!check_player_pos(all))
		return ;
	while (++x < all->map->wid)
	{
		y = 0;
		while (++y < all->map->len)
		{
			if ((c = elem_at(x, y, all->map)) == '0'
					&& (!iter_map(x, y, all->map, 'x')
						|| !iter_map(x, y, all->map, 'y')))
			{
				free_all(all);
				error(MAP_NOT_CLOSED, "", 1);
			}
			else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
				set_player_pos(all, x, y, c);
		}
	}
}
