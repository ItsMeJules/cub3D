/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:57:57 by jules             #+#    #+#             */
/*   Updated: 2021/03/11 21:07:41 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		game_loop(t_all *all)
{
	if (all->over)
	{
		close_w(all);
		ft_printf("You died!");
		return (1);
	}
	keys_manager(all);
	ray_cast(all);
	vert_cast(all);
	sprite_cast(all);
	draw_map(all);
	if (handle_life_lose(all) && all->player.health > 0)
		all->player.health--;
	if (all->player.health == 0)
		all->over = 1;
	draw_knife(all, all->keys.attack ? all->txtrs[K1_TXTR]
			: all->txtrs[K_TXTR]);
	draw_hud(all);
	if (all->frames % 10 == 0)
		all->keys.attack = 0;
	push_image(all->win);
	display_infos(all);
	if (all->frames++ > 1000)
		all->frames = 0;
	return (1);
}
