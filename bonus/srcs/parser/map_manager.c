/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:24:07 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/09 16:15:03 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		elem_at(int x, int y, t_map *map)
{
	return (map->line[map->wid * y + x]);
}

t_sprite	*get_sprite(int x, int y, t_list *lst)
{
	t_sprite	*sprite;

	while (lst)
	{
		sprite = (t_sprite *)lst->content;
		if ((int)sprite->x == x && (int)sprite->y == y)
			return (sprite);
		lst = lst->next;
	}
	return (NULL);
}
