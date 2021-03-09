/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:55:01 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/09 17:12:08 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	transparency_px(int px, int px2, double t)
{
	return (create_trgb(0, get_r(px) / t + get_r(px2) / t,
			get_g(px) / t + get_g(px2) / t,
			get_b(px) / t + get_b(px2) / t));
}

int	map_color(char c)
{
	if (c == '1')
		return (MAP_WALL_COLOR);
	else if (c == 'D' || c == 'd' || c == 'H')
		return (MAP_DOOR_COLOR);
	return (0);
}
