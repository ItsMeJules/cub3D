/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:42:14 by jules             #+#    #+#             */
/*   Updated: 2021/03/09 17:01:12 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	init_decelerate(int keycode, t_all *all)
{
	if (all->keys.fwrd <= 0 && all->keys.bwrd <= 0 && all->keys.left <= 0
			&& all->keys.right <= 0 && (keycode == W_KEY || keycode == S_KEY
				|| keycode == A_KEY || keycode == D_KEY))
		all->pos.decelerate = 1;
	if (all->keys.cam_left <= 0 && all->keys.cam_right <= 0
			&& all->keys.cam_up <= 0 && all->keys.cam_down <= 0
			&& (keycode == ARROW_LEFT_KEY || keycode == ARROW_RIGHT_KEY
				|| keycode == ARROW_UP_KEY || keycode == ARROW_DOWN_KEY))
		all->pos.cam_decelerate = 1;
}

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
		all->pos.pitch += (all->pos.cam_decelerate ? 50 : 300)
			* PLAYER_ROT_SPEED;
		if (all->pos.pitch > all->win->len)
			all->pos.pitch = all->win->len;
	}
	else
	{
		if (camera_deceler(&all->keys.cam_down, all) || all->pos.pitch <= -1000)
			return ;
		all->pos.pitch -= (all->pos.cam_decelerate ? 50 : 300)
			* PLAYER_ROT_SPEED;
		if (all->pos.pitch < -all->win->len)
			all->pos.pitch = -all->win->len;
	}
	all->skybox.ldiff = (all->win->len - all->pos.pitch) * all->skybox.ydiff;
}
