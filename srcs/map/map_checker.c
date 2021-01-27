/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:13:45 by jpeyron           #+#    #+#             */
/*   Updated: 2021/01/27 21:56:06 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * exemple de map
 * xxxxxxxxxxxxxxx
 * 012345678911111
 *           01234
 * ############### y 0
 * #1111111111111# y 1
 * #1000000000001# y 2
 * #1000000000001# y 3
 * #1111111111111# y 4
 * ############### y 5
 * 
 * il faut donc commencer a chercher en (1;1)
 */

void	free_map(t_all *all)
{
	free(all->map.line);
	free(all->so_txtr.path);
	free(all->no_txtr.path);
	free(all->we_txtr.path);
	free(all->ea_txtr.path);
	free(all->s_txtr.path);
}

int		look_for_walls(int x, int y, t_map map)
{
	(void)x;
	(void)y;
	(void)map;
	return (1);
}

void	check_map(t_all *all)
{
	int	x;
	int	y;
		
	x = 0;
	while (++x < all->map.wid)
	{
		y = 0;
		while (++y < all->map.len)
		{
			if (elem_at(x, y, all->map) == 0 && !look_for_walls(x, y, all->map))
			{
				free_map(all);
				error(MAP_NOT_CLOSED, "", 1);
			}
		}
	}
}
