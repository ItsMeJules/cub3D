/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 20:22:51 by jules             #+#    #+#             */
/*   Updated: 2021/02/10 13:29:08 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_wall_dist(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		if (ray->step_x == -1)
			ray->side = 0;
		else
			ray->side = 1;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		if (ray->step_y == -1)
			ray->side = 2;
		else
			ray->side = 3;
	}
}

void	dda(t_ray *ray, t_map *map)
{
	while (!ray->hit)
	{
		get_wall_dist(ray);
		if (elem_at(ray->map_x, ray->map_y, map) == '1')
			ray->hit = 1;
	}
}
