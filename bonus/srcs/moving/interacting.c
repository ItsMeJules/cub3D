/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interacting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:35:38 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/09 16:52:30 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	interact(t_all *all)
{
	int		nextx;
	int		nexty;
	char	c;

	c = elem_at(all->pos.pos_x, all->pos.pos_y, all->map);
	if (c == 'D' || c == 'd')
		return ;
	nextx = (int)(all->pos.pos_x + all->pos.dir_x);
	nexty = (int)(all->pos.pos_y + all->pos.dir_y);
	c = elem_at(nextx, nexty, all->map);
	if (c == 'D' || c == 'd')
	{
		if (c == 'D')
			all->map->line[all->map->wid * nexty + nextx] = 'd';
		else
			all->map->line[all->map->wid * nexty + nextx] = 'D';
	}
}

void	attack_sprite(t_all *all)
{
	char	c;
	int		nextx;
	int		nexty;

	nextx = (int)(all->pos.pos_x + all->pos.dir_x * PLAYER_DAMAGE_DEAL_DIST);
	nexty = (int)(all->pos.pos_y + all->pos.dir_y * PLAYER_DAMAGE_DEAL_DIST);
	c = elem_at(nextx, nexty, all->map);
	if (c > '1' && c <= '9')
	{
		all->map->line[all->map->wid * nexty + nextx] = '0';
		get_sprite(nextx, nexty, all->sprites)->show = 0;
	}
}

int		handle_life_lose(t_all *all)
{
	char	c;
	float	distx;
	float	disty;

	distx = -PLAYER_DAMAGE_TAKE_DIST;
	while (distx <= PLAYER_DAMAGE_TAKE_DIST)
	{
		disty = -PLAYER_DAMAGE_TAKE_DIST;
		while (disty <= PLAYER_DAMAGE_TAKE_DIST)
		{
			c = elem_at(all->pos.pos_x + distx, all->pos.pos_y + disty,
						all->map);
			if (c > '1' && c <= '9')
				return (1);
			disty += 0.1;
		}
		distx += 0.1;
	}
	return (0);
}
