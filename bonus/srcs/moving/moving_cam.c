/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:14:21 by jules             #+#    #+#             */
/*   Updated: 2021/03/10 14:28:11 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	rotate_left(double old_dir, double old_plane_x, t_all *all)
{
	t_pos	pos;

	if (camera_deceler(&all->keys.cam_left, all))
		return ;
	pos = all->pos;
	all->pos.dir_x = pos.dir_x * cos(-pos.rot_speed) - pos.dir_y *
		sin(-pos.rot_speed);
	all->pos.dir_y = old_dir * sin(-pos.rot_speed) + pos.dir_y *
		cos(-pos.rot_speed);
	all->pos.plane_x = pos.plane_x * cos(-pos.rot_speed) - pos.plane_y *
		sin(-pos.rot_speed);
	all->pos.plane_y = old_plane_x * sin(-pos.rot_speed) + pos.plane_y *
		cos(-pos.rot_speed);
}

void	rotate_right(double old_dir, double old_plane_x, t_all *all)
{
	t_pos	pos;

	if (camera_deceler(&all->keys.cam_right, all))
		return ;
	pos = all->pos;
	all->pos.dir_x = pos.dir_x * cos(pos.rot_speed) - pos.dir_y *
		sin(pos.rot_speed);
	all->pos.dir_y = old_dir * sin(pos.rot_speed) + pos.dir_y *
		cos(pos.rot_speed);
	all->pos.plane_x = pos.plane_x * cos(pos.rot_speed) - pos.plane_y *
		sin(pos.rot_speed);
	all->pos.plane_y = old_plane_x * sin(pos.rot_speed) + pos.plane_y *
		cos(pos.rot_speed);
}

void	rotate_camera(int right, double old_dir, double old_plane_x, t_all *all)
{
	if (!right)
		rotate_left(old_dir, old_plane_x, all);
	else
		rotate_right(old_dir, old_plane_x, all);
}
