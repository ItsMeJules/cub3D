/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:57:57 by jules             #+#    #+#             */
/*   Updated: 2021/03/03 01:09:18 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int		game_loop(t_all *all)
{
	keys_manager(all);
	ray_cast(all);
	vert_cast(all);
	sprite_cast(all);
	draw_map(all);
	draw_hud(all);
	push_image(all->win);
	all->player.health--;
	if (all->player.health <= 0)
		all->player.health = PLAYER_MAX_HEALTH;
	return (1);
}
