/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deceleration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:13:20 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/09 17:02:55 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (all->keys.cam_left == 1 || all->keys.cam_right == 1
			|| all->keys.cam_up == 1 || all->keys.cam_down == 1)
		*key = 0;
	if (all->pos.cam_decelerate == 1 && all->pos.rot_speed <= 0.001)
	{
		all->keys.cam_right = 0;
		all->keys.cam_left = 0;
		all->keys.cam_up = 0;
		all->keys.cam_down = 0;
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
