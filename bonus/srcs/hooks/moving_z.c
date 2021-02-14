/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:42:14 by jules             #+#    #+#             */
/*   Updated: 2021/02/14 20:58:53 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int		handle_deceler(int *key, t_all *all)
{
	if (*key != -1)
		return (0);
	if (all->pos.decelerate == 1 && all->pos.move_speed <= 0.001)
	{
		*key = 0;
		all->pos.move_speed = PLAYER_MOV_SPEED;
		all->pos.decelerate = 0;
		return (1);
	}
	else if (all->pos.decelerate == 2 && all->pos.rot_speed <= 0.001)
	{
		*key = 0;
		all->pos.rot_speed = PLAYER_ROT_SPEED;
		all->pos.decelerate = 0;
		return (1);
	}
	return (0);
}

void	do_jump(t_all *all)
{
	static double	jratio = -M_PI_2;
	int				ratio;

	ratio = cos(jratio) * 400;
	if (jratio <= M_PI_2)
		jratio += 0.1;
	else
	{
		all->pos.in_air = 0;
		jratio = -M_PI_2;
		ratio = 0;
	}
	all->pos.jump_crouch = ratio;
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
