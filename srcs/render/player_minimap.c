/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:11:50 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/04 23:26:27 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

int		draw_dir_ray(t_coord start, t_coord end, t_win *win)
{
	int	i;
	int	j;	

	i = 0;
	j = 0;
	if (start.x < end.x)
		i = 1;
	else if (start.x > end.x)
		i = -1;
	if (start.y < end.y)
		j = 1;
	else if (start.y > end.y)
		j = -1;
	printf("================%d %d==========\n", end.x, end.y);
	while ((start.x += i) != end.x || (start.y += j) != end.y)
	{
		printf("----------------%d %d----------\n", start.x, start.y);
		set_pixel(win, start.x, start.y, 0x009E00);
		set_pixel(win, start.x + j, start.y + i, 0x009E00); //Jai inverse i et j pour des tests
	}
	return (1);
}

void	draw_dir(t_pos pos, int x, int y, t_win *win)
{
	int	incri;
	int	incrj;
	t_coord start;
	t_coord end;

	start.x = x * MAP_ELEM_PX_SIZE + MAP_PLAYER_PX_SIZE / 2 + (MAP_PLAYER_PX_SIZE + 9) * pos.dir_x;
	start.y = y * MAP_ELEM_PX_SIZE + MAP_PLAYER_PX_SIZE / 2 + (MAP_PLAYER_PX_SIZE + 9) * pos.dir_y;
	end.x = x * MAP_ELEM_PX_SIZE + MAP_PLAYER_PX_SIZE / 2 + MAP_PLAYER_PX_SIZE * pos.dir_x;
	end.y = y * MAP_ELEM_PX_SIZE + MAP_PLAYER_PX_SIZE / 2 + MAP_PLAYER_PX_SIZE * pos.dir_y;
	draw_dir_ray(start, end, win);

	if (pos.dir_x > 0)
		incri = -1;
	else
		incri = 1;
	if (pos.dir_y > 0)
		incrj = -1;
	else
		incrj = 1;
	printf("%f %f -- %d < %d || %d < %d // %d %d\n", pos.dir_x, pos.dir_y, end.x, start.x, end.y, start.y, incri, incrj);

	/*while ((i < win->wid && i != x * MAP_ELEM_PX_SIZE + MAP_PLAYER_PX_SIZE / 2 + MAP_PLAYER_PX_SIZE * pos.dir_x) || (j < win->len && j != y * MAP_ELEM_PX_SIZE + MAP_PLAYER_PX_SIZE / 2 + MAP_PLAYER_PX_SIZE * pos.dir_y))
	{
		printf("bef %d %d\n", (int)(x * MAP_ELEM_PX_SIZE + MAP_PLAYER_PX_SIZE / 2 + MAP_PLAYER_PX_SIZE * pos.dir_x), (int)(x * MAP_ELEM_PX_SIZE + MAP_PLAYER_PX_SIZE / 2 + MAP_PLAYER_PX_SIZE * pos.dir_x));
		if (i < win->wid && i != x * MAP_ELEM_PX_SIZE + MAP_PLAYER_PX_SIZE / 2 + MAP_PLAYER_PX_SIZE * pos.dir_x)
			i += incri;
		if (j < win->len && j != y * MAP_ELEM_PX_SIZE + MAP_PLAYER_PX_SIZE / 2 + MAP_PLAYER_PX_SIZE * pos.dir_y)
			j += incrj;
		if (j > 150)
			exit(0);
		printf("%d %d\n\n", i, j);
		set_pixel(win, i, j, 0x000000);
	}*/
	(void)win;
}

void	draw_player(t_pos pos, t_win *win)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = (int)pos.pos_x;
	y = (int)pos.pos_y;
	i = x * MAP_ELEM_PX_SIZE - 1;
	while (++i < win->wid && i < x * MAP_ELEM_PX_SIZE + MAP_PLAYER_PX_SIZE - 1)
	{
		j = y * MAP_ELEM_PX_SIZE - 1;
		while (++j < win->len && j < y * MAP_ELEM_PX_SIZE + MAP_PLAYER_PX_SIZE - 1)
			set_pixel(win, i, j, MAP_PLAYER_COLOR);
	}
	draw_dir(pos, x, y, win);
}
