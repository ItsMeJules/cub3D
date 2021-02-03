/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:02:44 by jules             #+#    #+#             */
/*   Updated: 2021/02/02 17:22:49 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int		key_press(int keycode, t_all *all)
{
	if (keycode == ESC_KEY)
	{	
		mlx_loop_end(all->win->mlx);
		return (0);
	}
	else if (keycode == W_KEY)
		all->keys.fwrd = 1;
	else if (keycode == A_KEY)
		all->keys.bwrd = 1;
	else if (keycode == S_KEY)
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
	else if (keycode == A_KEY)
		all->keys.bwrd = 0;
	else if (keycode == S_KEY)
		all->keys.left = 0;
	else if (keycode == D_KEY)
		all->keys.right = 0;
	else if (keycode == ARROW_LEFT_KEY)
		all->keys.cam_left = 0;
	else if (keycode == ARROW_RIGHT_KEY)
		all->keys.cam_right = 0;
	return (1);
}
