/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assigner3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:33:00 by jules             #+#    #+#             */
/*   Updated: 2021/03/10 17:54:10 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_all	*extra_malloc(void)
{
	t_all	*all;

	if (!(all = malloc(sizeof(t_all))))
	{
		error(MALLOC_FAILED, "t_all in struct_assigner.c", 1);
		return (NULL);
	}
	if (!(all->ray = malloc(sizeof(t_ray))))
	{
		error(MALLOC_FAILED, "t_ray in struct_assigner.c", 1);
		return (NULL);
	}
	all->at_map = 0;
	all->frames = 0;
	return (all);
}

void	init_pos(t_all *all)
{
	all->pos.in_air = 0;
	all->pos.decelerate = 0;
	all->pos.cam_decelerate = 0;
}
