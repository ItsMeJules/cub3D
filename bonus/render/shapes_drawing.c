/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 09:35:58 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/09 14:58:29 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	incr_line(t_line *line, int *err, int sx, int sy)
{
	int	e2;

	e2 = 2 * *err;
	if (e2 >= line->dy)
	{
		*err += line->dy;
		line->x0 += sx;
	}
	if (e2 <= line->dx)
	{
		*err += line->dx;
		line->y0 += sy;
	}
}

void	draw_line(t_line line, t_win *win, int thickness, int color)
{
	int	sx;
	int sy;
	int err;
	int tmp;

	line.dy = -line.dy;
	sx = line.x0 < line.x1 ? 1 : -1;
	sy = line.y0 < line.y1 ? 1 : -1;
	err = line.dx + line.dy;
	tmp = thickness;
	while (1)
	{
		while (--thickness)
		{
			set_pixel(win, line.x0, line.y0, color);
			set_pixel(win, line.x0, line.y0 - thickness, color);
			set_pixel(win, line.x0 - thickness, line.y0, color);
		}
		thickness = tmp;
		if (line.y0 == line.y1 && line.x0 == line.x1)
			break ;
		incr_line(&line, &err, sx, sy);
	}
}
