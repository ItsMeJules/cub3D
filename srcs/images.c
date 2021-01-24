/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:13:57 by jules             #+#    #+#             */
/*   Updated: 2021/01/24 17:41:25 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*new_image(t_mlx *vars)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		return (error(0));

	img->img = mlx_new_image(vars->mlx, vars->width, vars->length);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_l,
			&img->endian);
	return (img);
}

void	set_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
