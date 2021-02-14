/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:02:44 by jules             #+#    #+#             */
/*   Updated: 2021/02/14 15:18:28 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

int		key_press(int keycode, t_all *all)
{
	if (keycode == ESC_KEY)
		return (close_w(all));
	else if (keycode == W_KEY)
		all->keys.fwrd = 1;
	else if (keycode == S_KEY)
		all->keys.bwrd = 1;
	else if (keycode == A_KEY)
		all->keys.left = 1;
	else if (keycode == D_KEY)
		all->keys.right = 1;
	else if (keycode == ARROW_LEFT_KEY)
		all->keys.cam_left = 1;
	else if (keycode == ARROW_RIGHT_KEY)
		all->keys.cam_right = 1;
	else if (keycode == SPACE_KEY && !all->pos.in_air)
		all->pos.in_air = 1;
	else if (keycode == SHIFT_KEY && !all->pos.in_air && !all->keys.sprint)
	{
		all->keys.crouch = 1;
		all->pos.move_speed *= PLAYER_CROUCH_MULT;
	}
	else if (keycode == CTRL_KEY && !all->keys.crouch)
	{
		all->keys.sprint = 1;
		all->pos.move_speed *= PLAYER_SPRINT_MULT;
	}
	return (1);
}

int		key_rels(int keycode, t_all *all)
{
	if (keycode == W_KEY)
		all->keys.fwrd = -1;
	else if (keycode == S_KEY)
		all->keys.bwrd = -1;
	else if (keycode == A_KEY)
		all->keys.left = -1;
	else if (keycode == D_KEY)
		all->keys.right = -1;
	else if (keycode == ARROW_LEFT_KEY)
		all->keys.cam_left = -1;
	else if (keycode == ARROW_RIGHT_KEY)
		all->keys.cam_right = -1;
	else if (keycode == SHIFT_KEY)
	{
		all->keys.crouch = 0;
		all->pos.move_speed = PLAYER_MOV_SPEED;
	}
	else if (keycode == CTRL_KEY)
	{
		all->keys.sprint = 0;
		all->pos.move_speed = PLAYER_MOV_SPEED;
	}
	if (all->keys.fwrd <= 0 && all->keys.bwrd <= 0
			&& all->keys.left <= 0 && all->keys.right <= 0
			&& (keycode == W_KEY || keycode == S_KEY || keycode == A_KEY
				|| keycode == D_KEY))
	{
		printf("in %d\n", all->keys.fwrd);
		all->pos.decelerate = 1;
	}
	return (1);
}

void	keys_manager(t_all *all)
{
	printf("lol %d\n", all->pos.decelerate);
	if (all->pos.decelerate == 1)
		all->pos.move_speed *= 0.78;
	if (all->keys.fwrd)
		move_forward(all);
	if (all->keys.bwrd)
		move_backward(all);
	if (all->keys.left)
		strafe_left(all);
	if (all->keys.right)
		strafe_right(all);
	if (all->keys.cam_left || all->keys.cam_right)
		rotate_camera(all->keys.cam_right, all->pos.dir_x, all->pos.plane_x,
				all);
	if (all->pos.in_air)
		do_jump(all);
	if (!all->pos.in_air)
		do_crouch(all, all->pos);
}	
