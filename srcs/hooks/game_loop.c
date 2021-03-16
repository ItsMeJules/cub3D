/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:57:57 by jules             #+#    #+#             */
/*   Updated: 2021/03/16 11:13:22 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int		game_loop(t_all *all)
{
	keys_manager(all);
	raycast(all);
	sprite_cast(all);
	if (all->save)
	{
		save_bmp(all, "./screenshot.bmp");
		stop_mlx(all);
		exit(1);
	}
	push_image(all->win);
	return (1);
}
