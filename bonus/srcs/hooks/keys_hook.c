/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:02:44 by jules             #+#    #+#             */
/*   Updated: 2021/03/09 17:02:27 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int		key_press_simple(int keycode, t_all *all)
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
	else if (keycode == ARROW_UP_KEY)
		all->keys.cam_up = 1;
	else if (keycode == ARROW_DOWN_KEY)
		all->keys.cam_down = 1;
	else if (keycode == SPACE_KEY && !all->pos.in_air)
		all->pos.in_air = 1;
	return (1);
}

int		key_press(int keycode, t_all *all)
{
	if (!key_press_simple(keycode, all))
		return (0);
	if (keycode == SHIFT_KEY && !all->pos.in_air && !all->keys.sprint)
	{
		all->keys.crouch = 1;
		if (!all->pos.decelerate)
			all->pos.move_speed *= PLAYER_CROUCH_MULT;
	}
	else if (keycode == CTRL_KEY && !all->keys.crouch && !all->pos.decelerate)
	{
		all->keys.sprint = 1;
		if (!all->pos.decelerate)
			all->pos.move_speed *= PLAYER_SPRINT_MULT;
	}
	else if (keycode == C_KEY)
		all->keys.crosshair = !all->keys.crosshair;
	else if (keycode == E_KEY)
		interact(all);
	else if (keycode == R_KEY && all->keys.attack != 1)
	{
		all->keys.attack = 1;
		attack_sprite(all);
	}
	return (1);
}

void	key_rels_simple(int keycode, t_all *all)
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
	else if (keycode == ARROW_UP_KEY)
		all->keys.cam_up = -1;
	else if (keycode == ARROW_DOWN_KEY)
		all->keys.cam_down = -1;
}

int		key_rels(int keycode, t_all *all)
{
	key_rels_simple(keycode, all);
	if (keycode == SHIFT_KEY)
	{
		all->keys.crouch = 0;
		if (!all->pos.decelerate)
			all->pos.move_speed = PLAYER_MOV_SPEED;
	}
	else if (keycode == CTRL_KEY && !all->pos.decelerate)
	{
		all->keys.sprint = 0;
		all->pos.move_speed = PLAYER_MOV_SPEED;
	}
	init_decelerate(keycode, all);
	return (1);
}

void	keys_manager(t_all *all)
{
	if (all->pos.decelerate == 1)
		all->pos.move_speed *= PLAYER_MOV_DECELERATE;
	if (all->pos.cam_decelerate == 1)
		all->pos.rot_speed *= PLAYER_ROT_DECELERATE;
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
	if (all->keys.cam_up || all->keys.cam_down)
		handle_pitch(all, all->keys.cam_up);
	if (all->pos.in_air)
		do_jump(all);
	if (!all->pos.in_air)
		do_crouch(all, all->pos);
}
