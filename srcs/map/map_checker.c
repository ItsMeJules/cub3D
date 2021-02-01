/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:13:45 by jpeyron           #+#    #+#             */
/*   Updated: 2021/01/29 18:29:13 by jules            ###   ########.fr       */
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

void	set_player_pos(t_all *all, int x, int y)
{
	all->pos.pos_x = (double)x;	
	all->pos.pos_y = (double)y;	
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
				set_player_pos(all, x, y);
		}
	}
}
