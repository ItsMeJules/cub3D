/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors_42docs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:23:37 by jules             #+#    #+#             */
/*   Updated: 2021/02/11 19:26:25 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		go_lsd_haha(int color, double dist)
{
	int		r;
	int 	g;
	int 	b;
	double	shade;
	
	r = get_r_42docs(color);
	g = get_g_42docs(color);
	b = get_b_42docs(color);
	shade = dist / PLAYER_VIEW_DIST > 1 ? 1 : dist / PLAYER_VIEW_DIST;
	return (create_trgb(0, r - r * shade, g - g * shade, b - b * shade));
}

int		get_r_42docs(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g_42docs(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b_42docs(int trgb)
{
	return (trgb & 0xFF);
}
