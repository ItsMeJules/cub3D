/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assigner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:44:04 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/10 18:15:22 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

t_texture	*new_txtr(char *path, char *id)
{
	t_texture	*txtr;

	if (!(txtr = malloc(sizeof(t_texture))))
	{
		error(MALLOC_FAILED, "t_texture in struct_assigner.c", 1);
		return (NULL);
	}
	if (!(txtr->img = malloc(sizeof(t_img))))
	{
		free(txtr);
		error(MALLOC_FAILED, "t_texture in struct_assigner.c", 1);
		return (NULL);
	}
	txtr->path = path;
	txtr->id = id;
	return (txtr);
}

t_all		*new_all(void)
{
	t_all	*all;

	all = extra_malloc();
	all->win = new_win();
	all->map = new_map();
	init_pos(all);
	all->ray->z_buffer = NULL;
	all->ray->x_drawstart = NULL;
	all->ray->x_drawend = NULL;
	all->floor = new_floor();
	all->txtrs = new_othertxtrs(9, -1);
	all->sp_txtrs = NULL;
	all->sprites = NULL;
	all->skybox.xdiff = 0;
	all->skybox.ydiff = 0;
	all->over = 0;
	all->player.health = PLAYER_MAX_HEALTH;
	all->hud.init = 0;
	set_keys(all);
	return (all);
}

void		free_all(t_all *all, int txtrs)
{
	free(all->map->line);
	free(all->map);
	if (all->ray->z_buffer)
		free(all->ray->z_buffer);
	if (all->ray->x_drawstart)
		free(all->ray->x_drawstart);
	if (all->ray->x_drawend)
		free(all->ray->x_drawend);
	free(all->ray);
	free(all->floor);
	if (txtrs)
		free_txtrs(all, 0, -1);
	ft_lstclear(&all->sprites, &free);
	free(all->win);
	free(all);
}
