/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:42:14 by jules             #+#    #+#             */
/*   Updated: 2021/02/13 00:17:15 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	do_jump(t_all *all)
{
	static double jratio = -M_PI_2;
	int	ratio;

	ratio = cos(jratio) * 400;
	if (jratio <= M_PI_2)
		jratio += 0.1;
	else
	{
		all->pos.in_air = 0;
		jratio = -M_PI_2;
		ratio = 0;
	}
	all->pos.jump_crouch = ratio;
}

//on commence a 3p/2
/*void	do_jump(t_all *all, t_pos pos)
{
	int	ratio;

	ratio = cos(pos.jump_ratio) * 400; //0
	if (!pos.falling && all->pos.jump_ratio <= 5 * M_PI_2)
	{
		all->pos.jump_ratio += 0.1;
		printf("%f\n", pos.jump_ratio);
	}
	if (!pos.falling && all->pos.jump_ratio >= 5 * M_PI_2)
	{
		printf("%f %f\n", pos.jump_ratio, 5 * M_PI_2);
		all->pos.falling = 1;
	}
	else if (pos.falling && all->pos.jump_ratio >= 5 * M_PI_2)
	{
		printf("fefe %f %f\n", pos.jump_ratio, 5 * M_PI_2);
		all->pos.jump_ratio -= 0.1;
		if (pos.jump_ratio <= 3 * M_PI_2)
		{
			all->pos.falling = 0;
			all->pos.in_air = 0;
		}
	}
	all->pos.jump_crouch = ratio < 0 ? 0 : ratio;
}*/

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
