/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:42:14 by jules             #+#    #+#             */
/*   Updated: 2021/03/02 15:18:19 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

int		camera_deceler(int *key, t_all *all)
{
	if (*key != -1)
	{
		if (all->pos.cam_decelerate != 0)
		{
			all->pos.rot_speed = PLAYER_ROT_SPEED;
			all->pos.cam_decelerate = 0;
		}
		return (0);
	}
	if (all->keys.cam_left == 1 || all->keys.cam_right == 1)
		*key = 0;
	if (all->pos.cam_decelerate == 1 && all->pos.rot_speed <= 0.001)
	{
		all->keys.cam_right = 0;
		all->keys.cam_left = 0;
		all->pos.rot_speed = PLAYER_ROT_SPEED;
		all->pos.cam_decelerate = 0;
		return (1);
	}
	return (0);
}

int		handle_deceler(int *key, t_all *all)
{
	if (*key != -1)
	{
		if (all->pos.decelerate != 0)
		{
			all->pos.move_speed = PLAYER_MOV_SPEED;
			all->pos.decelerate = 0;
		}
		return (0);
	}
	if (all->keys.left == 1 || all->keys.right == 1
			|| all->keys.bwrd == 1 || all->keys.fwrd == 1)
		*key = 0;
	if (all->pos.decelerate == 1 && all->pos.move_speed <= 0.001)
	{
		all->keys.left = 0;
		all->keys.right = 0;
		all->keys.bwrd = 0;
		all->keys.fwrd = 0;
		all->pos.move_speed = PLAYER_MOV_SPEED;
		all->pos.decelerate = 0;
		return (1);
	}
	return (0);
}

void	do_jump(t_all *all)
{
	static double	jratio = -M_PI_2;
	int				ratio;

	ratio = cos(jratio) * 200;
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
			all->pos.jump_crouch -= 40;
	}
	else if (pos.jump_crouch != 0)
		all->pos.jump_crouch += 40;
}
