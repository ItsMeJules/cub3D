/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assigner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:44:04 by jpeyron           #+#    #+#             */
/*   Updated: 2021/01/26 11:03:47 by jpeyron          ###   ########.fr       */
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
	map->so_txtr.path = NULL;
	map->no_txtr.path = NULL;
	map->we_txtr.path = NULL;
	map->ea_txtr.path = NULL;
	map->s_txtr.path = NULL;
	return (map);
}
