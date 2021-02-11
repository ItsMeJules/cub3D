/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:42:14 by jules             #+#    #+#             */
/*   Updated: 2021/02/11 22:15:59 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	do_jump(t_all *all, t_pos pos)
{
	if (pos.jump_crouch <= JUMP_HEIGHT_PX && pos.in_air && !pos.falling)
		all->pos.jump_crouch += 10;
	else if (pos.jump_crouch >= JUMP_HEIGHT_PX && !pos.falling)
		all->pos.falling = 1;
	else if (pos.falling)
	{
		if (pos.jump_crouch == 0)
		{
			all->pos.falling = 0;
			all->pos.in_air = 0;
			return ;
		}
		all->pos.jump_crouch -= 10;
	}
}

void	do_crouch(t_all *all, t_pos pos)
{
	if (all->keys.crouch)
	{
		if (pos.jump_crouch > CROUCH_HEIGHT_PX)
			all->pos.jump_crouch -= 10;
	}
	else if (pos.jump_crouch != 0)
		all->pos.jump_crouch += 10;
}
