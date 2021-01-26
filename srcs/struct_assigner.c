/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assigner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:44:04 by jpeyron           #+#    #+#             */
/*   Updated: 2021/01/26 17:25:17 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*new_map()
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

t_all	*new_all()
{
	t_all	*all;

	if (!(all = malloc(sizeof(t_all))))
	{
		error(MALLOC_FAILED, "t_all in struct_assigner.c", 1);
		return (NULL);
	}
	//all->map = new_map();
	all->so_txtr.path = NULL;
	all->no_txtr.path = NULL;
	all->we_txtr.path = NULL;
	all->ea_txtr.path = NULL;
	all->s_txtr.path = NULL;
	return (all);
}
