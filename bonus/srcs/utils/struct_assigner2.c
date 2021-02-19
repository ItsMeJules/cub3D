/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assigner2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:15:31 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/19 19:58:11 by jules            ###   ########.fr       */
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

t_texture	*new_othertxtrs(int amount, int i)
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
			while (i-- >= 0)
				free(txtr[i].img);
			free(txtr);
			error(MALLOC_FAILED, "t_texture in struct_assigner.c", 1);
			return (NULL);
		}
	}
	txtr[i].path = NULL;
	txtr[i].id = NULL;
	return (txtr);
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

void		free_txtrs(t_all *all, int mlx, int i)
{
	t_list		*list;
	t_texture	*txtr;

	list = all->sp_txtrs;
	while (list)
	{
		txtr = (t_texture *)list->content;
		if (mlx)
			mlx_destroy_image(all->win->mlx, txtr->img->img);
		free(txtr->img);
		free(txtr->path);
		free(txtr->id);
		list = list->next;
	}
	i = -1;
	while (all->txtrs[++i].path)
	{
		if (mlx)
			mlx_destroy_image(all->win->mlx, all->txtrs[i].img->img);
		free(all->txtrs[i].img);
		if (all->txtrs[i].path)
			free(all->txtrs[i].path);
	}
	free(all->txtrs);
	ft_lstclear(&all->sp_txtrs, &free);
}
