/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:55:42 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/10 14:17:26 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	move_forward(t_all *all)
{
	t_pos	pos;
	double	nextx;
	double	nexty;
	char	c;

	if (handle_deceler(&all->keys.fwrd, all))
		return ;
	pos = all->pos;
	nextx = pos.pos_x + pos.dir_x * pos.move_speed;
	nexty = pos.pos_y + pos.dir_y * pos.move_speed;
	c = elem_at((int)(nextx), (int)pos.pos_y, all->map);
	if (c == '0' || c == 'd' || c == 'H')
		all->pos.pos_x = nextx;
	c = elem_at((int)pos.pos_x, (int)(nexty), all->map);
	if (c == '0' || c == 'd' || c == 'H')
		all->pos.pos_y = nexty;
}

void	move_backward(t_all *all)
{
	t_pos	pos;
	double	nextx;
	double	nexty;
	char	c;

	if (handle_deceler(&all->keys.bwrd, all))
		return ;
	pos = all->pos;
	nextx = pos.pos_x - pos.dir_x * pos.move_speed;
	nexty = pos.pos_y - pos.dir_y * pos.move_speed;
	c = elem_at((int)(nextx), (int)pos.pos_y, all->map);
	if (c == '0' || c == 'd' || c == 'H')
		all->pos.pos_x = nextx;
	c = elem_at((int)pos.pos_x, (int)(nexty), all->map);
	if (c == '0' || c == 'd' || c == 'H')
		all->pos.pos_y = nexty;
}

void	strafe_left(t_all *all)
{
	t_pos	pos;
	double	nextx;
	double	nexty;
	char	c;

	if (handle_deceler(&all->keys.left, all))
		return ;
	pos = all->pos;
	nextx = pos.pos_x - pos.plane_x * pos.move_speed;
	nexty = pos.pos_y - pos.plane_y * pos.move_speed;
	c = elem_at((int)(nextx), (int)pos.pos_y, all->map);
	if (c == '0' || c == 'd' || c == 'H')
		all->pos.pos_x = nextx;
	c = elem_at((int)pos.pos_x, (int)(nexty), all->map);
	if (c == '0' || c == 'd' || c == 'H')
		all->pos.pos_y = nexty;
}

void	strafe_right(t_all *all)
{
	t_pos	pos;
	double	nextx;
	double	nexty;
	char	c;

	if (handle_deceler(&all->keys.right, all))
		return ;
	pos = all->pos;
	nextx = pos.pos_x + pos.plane_x * pos.move_speed;
	nexty = pos.pos_y + pos.plane_y * pos.move_speed;
	c = elem_at((int)(nextx), (int)pos.pos_y, all->map);
	if (c == '0' || c == 'd' || c == 'H')
		all->pos.pos_x = nextx;
	c = elem_at((int)pos.pos_x, (int)(nexty), all->map);
	if (c == '0' || c == 'd' || c == 'H')
		all->pos.pos_y = nexty;
}
