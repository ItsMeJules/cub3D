/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assigner2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:15:31 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/19 18:52:03 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_keys(t_all *all)
{
	all->keys.fwrd = 0;
	all->keys.bwrd = 0;
	all->keys.left = 0;
	all->keys.right = 0;
	all->keys.cam_left = 0;
	all->keys.cam_right = 0;
	all->keys.crouch = 0;
	all->keys.sprint = 0;
}

t_sprite	*new_sprite(char txtr, double x, double y)
{
	t_sprite	*sprite;

	if (!(sprite = malloc(sizeof(t_sprite))))
	{
		error(MALLOC_FAILED, "t_sprite in struct_assigner2.c", 1);
		return (NULL);
	}
	sprite->txtr = txtr;
	sprite->x = x;
	sprite->y = y;
	sprite->dist = 0;
	return (sprite);
}

t_floor		*new_floor()
{
	t_floor	*floor;

	if (!(floor = malloc(sizeof(t_floor))))
	{
		error(MALLOC_FAILED, "t_floor in struct_assigner2.c", 1);
		return (NULL);
	}
	return (floor);
}

void		free_txtrs(t_all *all, int mlx)
{
	t_list		*list;
	t_texture	*txtr;
	int			i;

	list = all->txtrs;
	i = -1;
	while (list)
	{
		txtr = (t_texture *)list->content;
		if (mlx)
			mlx_destroy_image(all->win->mlx, txtr->img->img);
		free(txtr->img);
		if (txtr->path)
			free(txtr->path);
		list = list->next;
	}
	//if (mlx)
	//	free(all->txtrs[i].img);
	ft_lstclear(&all->txtrs, &free);
}
