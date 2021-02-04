/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assigner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42->fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:44:04 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/04 11:17:45 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_map		*new_map()
{
	t_map	*map;

	if (!(map = malloc(sizeof(t_map))))
	{
		error(MALLOC_FAILED, "t_map in struct_assigner->c", 1);
		return (NULL);
	}
	map->line = NULL;
	map->start_dir = 0;
	map->wid = 0;
	map->len = 0;
	map->gr = 0;
	map->ce = 0;
	return (map);
}

t_win		*new_win()
{
	t_win	*win;

	if (!(win = malloc(sizeof(t_win))))
	{
		error(MALLOC_FAILED, "t_win in struct_assigner.c", 1);
		return (NULL);
	}
	win->len = 0;
	win->wid = 0;
	return (win);
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
	if (!(txtr->img = malloc(sizeof(t_img))))
	{
		free(txtr);
		error(MALLOC_FAILED, "t_texture in struct_assigner.c", 1);
		return (NULL);
	}
	return (txtr);
}

t_all		*new_all()
{
	t_all	*all;

	if (!(all = malloc(sizeof(t_all))) || !(all->ray = malloc(sizeof(t_ray))))
	{
		error(MALLOC_FAILED, "t_all or t_ray in struct_assigner.c", 1);
		return (NULL);
	}
	all->all_set = 0;
	all->win = new_win();
	all->map = new_map();
	set_keys(all);
	all->so_txtr = new_txtr();
	all->no_txtr = new_txtr();
	all->we_txtr = new_txtr();
	all->ea_txtr = new_txtr();
	all->s_txtr = new_txtr();
	return (all);
}

void	free_all(t_all *all)
{
	free(all->win);
	free(all->map->line);
	free(all->map);
	if (all->so_txtr->path)
		free(all->so_txtr->path);
	free(all->so_txtr);
	if (all->no_txtr->path)
		free(all->no_txtr->path);
	free(all->no_txtr);
	if (all->we_txtr->path)
		free(all->we_txtr->path);
	free(all->we_txtr);
	if (all->ea_txtr->path)
		free(all->ea_txtr->path);
	free(all->ea_txtr);
	if (all->s_txtr->path)
		free(all->s_txtr->path);
	free(all->s_txtr);
	free(all);
}
