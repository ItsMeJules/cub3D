/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assigner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42->fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:44:04 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/02 22:14:32 by jules            ###   ########.fr       */
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
	txtr->img = NULL;
	txtr->wid = 0;
	txtr->hei = 0;
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
	free(all->so_txtr->path);
	free(all->so_txtr);
	free(all->no_txtr->path);
	free(all->no_txtr);
	free(all->we_txtr->path);
	free(all->we_txtr);
	free(all->ea_txtr->path);
	free(all->ea_txtr);
	free(all->s_txtr->path);
	free(all->s_txtr);
	free(all);
}
