/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:55:42 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/03 16:40:47 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

void	move_forward(t_all *all)
{
	t_pos	pos;
	double	nextx;
	double	nexty;

	if (handle_deceler(&all->keys.fwrd, all))
		return ;
	pos = all->pos;
	nextx = pos.pos_x + pos.dir_x * pos.move_speed;
	nexty = pos.pos_y + pos.dir_y * pos.move_speed;
	if (elem_at((int)(nextx), (int)pos.pos_y, all->map) == '0')
		all->pos.pos_x = nextx; 
	if (elem_at((int)pos.pos_x, (int)(nexty), all->map) == '0')
		all->pos.pos_y = nexty; 
}

void	move_backward(t_all *all)
{
	t_pos	pos;
	double	nextx;
	double	nexty;

	if (handle_deceler(&all->keys.bwrd, all))
		return ;
	pos = all->pos;
	nextx = pos.pos_x - pos.dir_x * pos.move_speed;
	nexty = pos.pos_y - pos.dir_y * pos.move_speed;
	if (elem_at((int)(nextx), (int)pos.pos_y, all->map) == '0')
		all->pos.pos_x = nextx;
	if (elem_at((int)pos.pos_x, (int)(nexty), all->map) == '0')
		all->pos.pos_y = nexty;
}

void	strafe_left(t_all *all)
{
	t_pos	pos;
	double	nextx;
	double	nexty;

	if (handle_deceler(&all->keys.left, all))
		return ;
	pos = all->pos;
	nextx = pos.pos_x - pos.plane_x * pos.move_speed;
	nexty = pos.pos_y - pos.plane_y * pos.move_speed;
	if (elem_at((int)(nextx), (int)pos.pos_y, all->map) == '0')
		all->pos.pos_x = nextx;
	if (elem_at((int)pos.pos_x, (int)(nexty), all->map) == '0')
		all->pos.pos_y = nexty;
}

void	strafe_right(t_all *all)
{
	t_pos	pos;
	double	nextx;
	double	nexty;

	if (handle_deceler(&all->keys.right, all))
		return ;
	pos = all->pos;
	nextx = pos.pos_x + pos.plane_x * pos.move_speed;
	nexty = pos.pos_y + pos.plane_y * pos.move_speed;
	if (elem_at((int)(nextx), (int)pos.pos_y, all->map) == '0')
		all->pos.pos_x = nextx; 
	if (elem_at((int)pos.pos_x, (int)(nexty), all->map) == '0')
		all->pos.pos_y = nexty;
}

void	rotate_camera(int right, double old_dir, double old_plane_x, t_all *all)
{
	t_pos	pos;

	pos = all->pos;
	if (!right)
	{
		if (camera_deceler(&all->keys.cam_left, all))
			return ;
		all->pos.dir_x = pos.dir_x * cos(-pos.rot_speed) - pos.dir_y *
			sin(-pos.rot_speed);
		all->pos.dir_y = old_dir * sin(-pos.rot_speed) + pos.dir_y *
			cos(-pos.rot_speed);
		all->pos.plane_x = pos.plane_x * cos(-pos.rot_speed) - pos.plane_y *
			sin(-pos.rot_speed);
		all->pos.plane_y = old_plane_x * sin(-pos.rot_speed) + pos.plane_y *
			cos(-pos.rot_speed);
	}
	if (right)
	{
		if (camera_deceler(&all->keys.cam_right, all))
			return ;
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
