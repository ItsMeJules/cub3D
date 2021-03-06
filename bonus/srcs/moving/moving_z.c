/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:42:14 by jules             #+#    #+#             */
/*   Updated: 2021/03/06 13:23:07 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

void	do_jump(t_all *all)
{
	static double	jratio = -M_PI_2;
	int				ratio;

	ratio = cos(jratio) * JUMP_HEIGHT_PX;
	if (jratio <= M_PI_2)
		jratio += 0.1;
	else
	{
		all->pos.in_air = 0;
		jratio = -M_PI_2;
		ratio = 0;
	}
	all->pos.pos_z = ratio;
}

void	do_crouch(t_all *all, t_pos pos)
{
	if (all->keys.crouch)
	{
		if (pos.pos_z > CROUCH_HEIGHT_PX)
			all->pos.pos_z -= 50;
		else
			all->pos.pos_z = CROUCH_HEIGHT_PX;
	}
	else if (pos.pos_z != 0)
	{
		if (all->pos.pos_z + 50 > 0)
			all->pos.pos_z = 0;
		else
			all->pos.pos_z += 50;
	}
}

void	handle_pitch(t_all *all, int up)
{
	if (up)	
	{
		if (camera_deceler(&all->keys.cam_up, all) || all->pos.pitch >= 1000)
			return ;
		all->pos.pitch += (all->pos.cam_decelerate ? 50 : 300) * PLAYER_ROT_SPEED;
		if (all->pos.pitch > all->win->len)
			all->pos.pitch = all->win->len;
	}
	else
	{
		if (camera_deceler(&all->keys.cam_down, all) || all->pos.pitch <= -1000)
			return ;
		all->pos.pitch -= (all->pos.cam_decelerate ? 50 : 300) * PLAYER_ROT_SPEED;
		if (all->pos.pitch < -all->win->len)
			all->pos.pitch = -all->win->len;
	}
	all->skybox.ldiff = (all->win->len - all->pos.pitch) * all->skybox.ydiff;
}
