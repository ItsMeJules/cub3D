/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assigner2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:15:31 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/09 15:05:42 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_keys(t_all *all)
{
	all->keys.fwrd = 0;
	all->keys.bwrd = 0;
	all->keys.left = 0;
	all->keys.right = 0;
	all->keys.cam_left = 0;
	all->keys.cam_right = 0;
}

t_sprite	*new_sprite(int txtr, double x, double y)
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

void	free_txtrs(t_all *all, int mlx)
{
	int	i;

	i = -1;
	while (all->txtrs[++i].path)
	{
		if (mlx)
			mlx_destroy_image(all->win->mlx, all->txtrs[i].img->img);
		free(all->txtrs[i].img);	
		if (all->txtrs[i].path)
			free(all->txtrs[i].path);
		free(&all->txtrs[i]);
	}
}
