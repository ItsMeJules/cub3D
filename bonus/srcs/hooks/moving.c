/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:55:42 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/14 15:15:12 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

void	move_forward(t_all *all)
{
	t_pos	pos;

	printf("%d %f\n", all->keys.fwrd, all->pos.move_speed);
	if (all->keys.fwrd == -1 && all->pos.move_speed <= 0.001)
	{
		all->keys.fwrd = 0;
		all->pos.move_speed = PLAYER_MOV_SPEED;
		all->pos.decelerate = 0;
		return ;
	}
	pos = all->pos;
	if (elem_at((int)(pos.pos_x + pos.dir_x * pos.move_speed), (int)pos.pos_y,
				all->map) == '0')
		all->pos.pos_x += pos.dir_x * pos.move_speed;
	if (elem_at((int)pos.pos_x, (int)(pos.pos_y + pos.dir_y * pos.move_speed),
				all->map) == '0')
		all->pos.pos_y += pos.dir_y * pos.move_speed;
}

void	move_backward(t_all *all)
{
	t_pos	pos;

	if (all->keys.bwrd == -1)
	{
		if (all->pos.move_speed == 0)
		{
			all->keys.bwrd = 0;
			all->pos.move_speed = PLAYER_MOV_SPEED;
		}
		all->pos.move_speed -= 0.01;
	}
	pos = all->pos;
	if (elem_at((int)(pos.pos_x - pos.dir_x * pos.move_speed), (int)pos.pos_y,
				all->map) == '0')
		all->pos.pos_x -= pos.dir_x * pos.move_speed;
	if (elem_at((int)pos.pos_x, (int)(pos.pos_y - pos.dir_y * pos.move_speed),
				all->map) == '0')
		all->pos.pos_y -= pos.dir_y * pos.move_speed;
}

void	strafe_left(t_all *all)
{
	t_pos	pos;

	if (all->keys.left == -1)
	{
		if (all->pos.move_speed == 0)
		{
			all->keys.left = 0;
			all->pos.move_speed = PLAYER_MOV_SPEED;
		}
		all->pos.move_speed -= 0.01;
	}
	pos = all->pos;
	if (elem_at((int)(pos.pos_x - pos.plane_x * pos.move_speed), (int)pos.pos_y,
				all->map) == '0')
		all->pos.pos_x -= pos.plane_x * pos.move_speed;
	if (elem_at((int)pos.pos_x, (int)(pos.pos_y - pos.plane_y * pos.move_speed),
				all->map) == '0')
		all->pos.pos_y -= pos.plane_y * pos.move_speed;
}

void	strafe_right(t_all *all)
{
	t_pos	pos;

	if (all->keys.right == -1)
	{
		if (all->pos.move_speed == 0)
		{
			all->keys.right = 0;
			all->pos.move_speed = PLAYER_MOV_SPEED;
		}
		all->pos.move_speed -= 0.01;
	}
	pos = all->pos;
	if (elem_at((int)(pos.pos_x + pos.plane_x * pos.move_speed), (int)pos.pos_y,
				all->map) == '0')
		all->pos.pos_x += pos.plane_x * pos.move_speed;
	if (elem_at((int)pos.pos_x, (int)(pos.pos_y + pos.plane_y * pos.move_speed),
				all->map) == '0')
		all->pos.pos_y += pos.plane_y * pos.move_speed;
}

void	rotate_camera(int right, double old_dir, double old_plane_x, t_all *all)
{
	t_pos	pos;

	pos = all->pos;
	if (!right)
	{
		all->pos.dir_x = pos.dir_x * cos(-pos.rot_speed) - pos.dir_y *
			sin(-pos.rot_speed);
		all->pos.dir_y = old_dir * sin(-pos.rot_speed) + pos.dir_y *
			cos(-pos.rot_speed);
		all->pos.plane_x = pos.plane_x * cos(-pos.rot_speed) - pos.plane_y *
			sin(-pos.rot_speed);
		all->pos.plane_y = old_plane_x * sin(-pos.rot_speed) + pos.plane_y *
			cos(-pos.rot_speed);
	}
	else
	{
		all->pos.dir_x = pos.dir_x * cos(pos.rot_speed) - pos.dir_y *
			sin(pos.rot_speed);
		all->pos.dir_y = old_dir * sin(pos.rot_speed) + pos.dir_y *
			cos(pos.rot_speed);
		all->pos.plane_x = pos.plane_x * cos(pos.rot_speed) - pos.plane_y *
			sin(pos.rot_speed);
		all->pos.plane_y = old_plane_x * sin(pos.rot_speed) + pos.plane_y *
			cos(pos.rot_speed);
	}
}
