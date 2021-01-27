/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assigner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:44:04 by jpeyron           #+#    #+#             */
/*   Updated: 2021/01/26 22:12:02 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map		*new_map()
{
	t_map	*map;

	if (!(map = malloc(sizeof(t_map))))
	{
		error(MALLOC_FAILED, "t_map in struct_assigner.c", 1);
		return (NULL);
	}
	map->wid = 0;
	map->len = 0;
	map->gr = 0;
	map->ce = 0;
	return (map);
}

t_texture	*new_txtr()
{
	t_texture	*txtr;

	if (!(txtr = malloc(sizeof(t_texture))))
	{
		error(MALLOC_FAILED, "t_texture in struct_assigner.c", 1);
		return (NULL);
	}
	txtr->path = NULL;
	txtr->img = NULL;
	txtr->x = 0;
	txtr->y = 0;
	return (txtr);
}

t_all		*new_all()
{
	t_all	*all;

	if (!(all = malloc(sizeof(t_all))))
	{
		error(MALLOC_FAILED, "t_all in struct_assigner.c", 1);
		return (NULL);
	}
	all->all_set = 0;
	all->win.wid = 0;
	all->win.len = 0;
	all->map = *new_map();
	all->so_txtr = *new_txtr();
	all->no_txtr = *new_txtr();
	all->we_txtr = *new_txtr();
	all->ea_txtr = *new_txtr();
	all->s_txtr = *new_txtr();
	return (all);
}
