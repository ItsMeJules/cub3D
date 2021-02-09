/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assigner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:44:04 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/09 19:53:32 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_map		*new_map(void)
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

t_win		*new_win(void)
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

t_texture	*new_txtrs(int amount, int i)
{
	t_texture	*txtr;

	if (!(txtr = malloc(sizeof(t_texture) * (amount + 1))))
	{
		error(MALLOC_FAILED, "t_texture in struct_assigner.c", 1);
		return (NULL);
	}
	while (++i < amount)
	{
		txtr[i].path = NULL;
		if (!(txtr[i].img = malloc(sizeof(t_img))))
		{
			free(&txtr[i]);
			while (i-- >= 0)
			{
				free(txtr[i].img);
				free(&txtr[i]);
			}
			error(MALLOC_FAILED, "t_texture in struct_assigner.c", 1);
			return (NULL);
		}
	}
	txtr[i].path = NULL;
	return (txtr);
}

t_all		*new_all(void)
{
	t_all	*all;

	if (!(all = malloc(sizeof(t_all))))
	{
		error(MALLOC_FAILED, "t_all in struct_assigner.c", 1);
		return (NULL);
	}
	if (!(all->ray = malloc(sizeof(t_ray))))
	{
		error(MALLOC_FAILED, "t_ray in struct_assigner.c", 1);
		return (NULL);
	}
	all->all_set = 0;
	all->win = new_win();
	all->map = new_map();
	all->txtrs = new_txtrs(5, -1);
	all->sprites = NULL;
	set_keys(all);
	return (all);
}

void		free_all(t_all *all, int txtrs)
{
	free(all->win);
	free(all->map->line);
	free(all->map);
	if (all->ray->z_buffer)
		free(all->ray->z_buffer);
	free(all->ray);
	if (txtrs)
		free_txtrs(all, 0);
	free(all);
}
