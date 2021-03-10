/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:09:56 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/10 14:37:48 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		depth_shade(int color, double dist)
{
	int		r;
	int		g;
	int		b;
	double	shade;

	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	shade = dist / PLAYER_VIEW_DIST > 1 ? 1 : dist / PLAYER_VIEW_DIST;
	return (create_trgb(0, r - r * shade, g - g * shade, b - b * shade));
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		get_r(int trgb)
{
	return ((trgb & 0x00FF0000) >> 16);
}

int		get_g(int trgb)
{
	return ((trgb & 0x0000FF00) >> 8);
}

int		get_b(int trgb)
{
	return ((trgb & 0x000000FF));
}
