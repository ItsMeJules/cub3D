/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:57:57 by jules             #+#    #+#             */
/*   Updated: 2021/02/22 13:27:43 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int		game_loop(t_all *all)
{
	keys_manager(all);
	ray_cast(all);
	vert_cast(all);
	sprite_cast(all);
	draw_map(all);
	push_image(all->win);
	return (1);
}
