/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:17:22 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/09 16:16:10 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int		compare_sprites(t_list *elem, t_list *next)
{
	return (((t_sprite *)next)->dist - ((t_sprite *)elem)->dist);
}

void	get_draw_posy(t_sprite *s, t_win *win, t_pos pos)
{
	s->z_offset = pos.pos_z / s->transform_y;
	s->draw_starty = -s->hei / 2 + win->len / 2 + s->vmove_screen;
	s->draw_endy = s->hei / 2 + win->len / 2 + s->vmove_screen;
	if (s->draw_starty < 0)
		s->draw_starty = 0;
	if (s->draw_endy >= win->len)
		s->draw_endy = win->len - 1;
}

void	calc_sprite(t_sprite *s, t_pos pos, t_win *win)
{
	s->sx = s->x - pos.pos_x;
	s->sy = s->y - pos.pos_y;
	s->invdet = 1.0 / (pos.plane_x * pos.dir_y - pos.dir_x * pos.plane_y);
	s->transform_x = s->invdet * (pos.dir_y * s->sx - pos.dir_x * s->sy);
	s->transform_y = s->invdet * (-pos.plane_y * s->sx + pos.plane_x * s->sy);
	s->screen_x = (int)(win->wid / 2 * (1 + s->transform_x / s->transform_y));
	s->vmove_screen = (int)(s->vmove / s->transform_y)
		+ pos.pitch + pos.pos_z / s->transform_y;
	s->hei = abs((int)(win->len / s->transform_y));
	get_draw_posy(s, win, pos);
	s->wid = abs((int)(win->len / s->transform_y));
	s->draw_startx = -s->wid / 2 + s->screen_x;
	if (s->draw_startx < 0)
		s->draw_startx = 0;
	s->draw_endx = s->wid / 2 + s->screen_x;
	if (s->draw_endx >= win->wid)
		s->draw_endx = win->wid - 1;
}

void	init_dist(t_list *lst, t_pos pos)
{
	t_sprite	*s;

	while (lst)
	{
		s = (t_sprite *)lst->content;
		s->dist = (pos.pos_x - s->x) * (pos.pos_x - s->x)
			+ (pos.pos_y - s->y) * (pos.pos_y - s->y);
		lst = lst->next;
	}
}

void	sprite_cast(t_all *all)
{
	t_list	*lst;

	init_dist(all->sprites, all->pos);
	ft_lst_sort(&all->sprites, &compare_sprites);
	lst = all->sprites;
	while (lst)
	{
		if (((t_sprite *)lst->content)->show == 1)
		{
			calc_sprite((t_sprite *)lst->content, all->pos, all->win);
			draw_sprite((t_sprite *)lst->content, all->ray, all->win,
					*get_sptexture(all->sp_txtrs,
					((t_sprite *)lst->content)->txtr));
		}
		lst = lst->next;
	}
}
