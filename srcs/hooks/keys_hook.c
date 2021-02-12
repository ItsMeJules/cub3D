/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:02:44 by jules             #+#    #+#             */
/*   Updated: 2021/02/12 13:25:33 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

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
	return (1);
}

int		key_rels(int keycode, t_all *all)
{
	if (keycode == W_KEY)
		all->keys.fwrd = 0;
	else if (keycode == S_KEY)
		all->keys.bwrd = 0;
	else if (keycode == A_KEY)
		all->keys.left = 0;
	else if (keycode == D_KEY)
		all->keys.right = 0;
	else if (keycode == ARROW_LEFT_KEY)
		all->keys.cam_left = 0;
	else if (keycode == ARROW_RIGHT_KEY)
		all->keys.cam_right = 0;
	return (1);
}

void	keys_manager(t_all *all)
{
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
}
