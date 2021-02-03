/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:19:22 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/03 17:16:19 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h> 
#include "cub3d.h"
#include "libft.h"

void	draw_line(t_all *all, int x)
{
	int y = all->ray->draw_start - 1;
	int	color = create_trgb(0, 100, 100, 200);
	//ft_printf("%d %d\n", all->ray->draw_start, all->ray->draw_end);
	while (++y < all->ray->draw_end)
		set_pixel(all->win, x, y, color);
}

void	init_wall_txtr(t_all *all, t_ray *ray, int x)
{
	t_texture	*txtr;

	if (ray->side == 0)	
		txtr = all->ea_txtr;
	else if (ray->side == 1)
		txtr = all->we_txtr;
	else if (ray->side == 2)
		txtr = all->so_txtr;
	else
		txtr = all->no_txtr;
	ray->text_x = (int)(ray->wall_x * (double)txtr->wid);
	if ((ray->side == 0 || ray->side == 1) && ray->dir_x > 0)
		ray->text_x = txtr->wid - ray->text_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->dir_y < 0)
		ray->text_x = txtr->wid - ray->text_x - 1;
	//draw_txtr(all, ray, txtr, x);
	draw_line(all, x);
}

void	calc_hit(t_all *all, t_ray *ray, t_pos pos, int x)
{
	ray->draw_start = -ray->line_h / 2 + all->win->len / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_h / 2 + all->win->len / 2;
	if (ray->draw_end >= all->win->len)
		ray->draw_end = all->win->len - 1;
	if (ray->side == 0 || ray->side == 1)
		ray->wall_x = pos.pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = pos.pos_x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	init_wall_txtr(all, ray, x);
}

void	draw_col(t_all *all, int x)
{
	calc_hit(all, all->ray, all->pos, x);
}
