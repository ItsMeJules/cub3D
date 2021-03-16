/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:57:57 by jules             #+#    #+#             */
/*   Updated: 2021/03/16 11:10:45 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp(t_all *all)
{
	if (all->save)
	{
		save_bmp(all, "./screenshot.bmp");
		stop_mlx(all);
		exit(1);
	}
}

void	handle_death(t_all *all)
{
	if (all->over)
	{
		ft_printf("You died!");
		close_w(all);
		stop_mlx(all);
		exit(1);
	}
}

int		game_loop(t_all *all)
{
	handle_death(all);
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
	bmp(all);
	push_image(all->win);
	display_infos(all);
	if (all->frames++ > 1000)
		all->frames = 0;
	return (1);
}
