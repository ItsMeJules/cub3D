/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:17:22 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/09 19:48:17 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_cast(t_all *all)
{
	t_list		*lst;
	t_sprite	*s;
	
	lst = all->sprites;
	while (lst)
	{
		s = (t_sprite *)lst->content; 
		s->dist = (all->pos.pos_x - s->x) * (all->pos.pos_x - s->x)
			+ (all->pos.pos_y - s->y) * (all->pos.pos_y - s->y);
		lst = lst->next;
	}
}
