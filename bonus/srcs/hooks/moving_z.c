/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:42:14 by jules             #+#    #+#             */
/*   Updated: 2021/02/12 17:24:55 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

/*void	do_jump(t_all *all, t_pos pos)
{
	if (pos.jump_crouch <= JUMP_HEIGHT_PX && pos.in_air && !pos.falling)
	{
		all->pos.jump_crouch += cos(-M_PI_2 + pos.acc) * 100;
		all->pos.acc += 0.5;
	}
	else if (pos.jump_crouch >= JUMP_HEIGHT_PX && !pos.falling)
		all->pos.falling = 1;
	else if (pos.falling)
	{
		if (cos())
		{
			all->pos.falling = 0;
			all->pos.in_air = 0;
			return ;
		}
		all->pos.jump_crouch -= cos(-M_PI_2 + pos.acc) * 100;
		all->pos.acc -= 0.5;
	}
}*/

void	do_jump(t_all *all, t_pos pos)
{
	int	ratio;

	ratio = cos(pos.jump_ratio) * 400; //0
	if (!pos.falling && all->pos.jump_ratio < 5 * M_PI_2)
		all->pos.jump_ratio += 0.5;
	printf("%d %f %f\n", ratio, all->pos.jump_ratio, 5 * M_PI_2);
	if (!pos.falling && ratio <= 0 && all->pos.jump_ratio >= 5 * M_PI_2)
		all->pos.falling = 1;
	else if (pos.falling && all->pos.jump_ratio >= 3 * M_PI_2)
	{
		all->pos.jump_ratio -= 0.5;
		if (pos.jump_ratio == 3 * M_PI_2)
		{
			all->pos.falling = 0;
			all->pos.in_air = 0;
		}
	}
	all->pos.jump_crouch = ratio < 0 ? 0 : ratio;
}

void	do_crouch(t_all *all, t_pos pos)
{
	if (all->keys.crouch)
	{
		if (pos.jump_crouch > CROUCH_HEIGHT_PX)
			all->pos.jump_crouch -= 10;
	}
	else if (pos.jump_crouch != 0)
		all->pos.jump_crouch += 10;
}
