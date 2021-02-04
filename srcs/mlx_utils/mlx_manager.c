/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:36:12 by jules             #+#    #+#             */
/*   Updated: 2021/02/04 11:27:41 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	new_window(t_win *win, char name[25])
{
	if (!(win->img = malloc(sizeof(t_img))))
	{
		error(MALLOC_FAILED, "t_img in images.c", 1);
		return ;
	}
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->wid, win->len, name);
	win->img->img = mlx_new_image(win->mlx, win->wid, win->len);
	win->img->addr = mlx_get_data_addr(win->img->img, &win->img->bpp,
			&win->img->line_l, &win->img->endian);
}

int		close_w(t_all *all)
{
	(void)all;
//	mlx_loop_end(all->win->mlx);
	return (0);
}

int		load_txtr(t_all *all, t_texture *txtr)
{
	if (!(txtr->img->img = mlx_xpm_file_to_image(all->win->mlx, txtr->path,
					&txtr->wid, &txtr->hei)))
	{
		error(FAILED_TO_LOAD_TXTR, txtr->path, 0);
		free_all(all);
		return (1);
	}
	txtr->img->addr = mlx_get_data_addr(txtr->img->img, &txtr->img->bpp,
			&txtr->img->line_l, &txtr->img->endian);
	return (0);
}

void	start_mlx(t_all *all)
{
	new_window(all->win, "Je suis une fenetre");
	if (load_txtr(all, all->no_txtr) || load_txtr(all, all->so_txtr) || load_txtr(all, all->we_txtr) || load_txtr(all, all->ea_txtr) || load_txtr(all, all->s_txtr))
		return ;
	mlx_hook(all->win->win, DESTROY_WIN_EVENT, DESTROY_WIN_MASK, close_w, all);
	mlx_hook(all->win->win, KEY_PRESS_EVENT, KEY_PRESS_MASK, key_press, all);
	mlx_hook(all->win->win, KEY_RELEASE_EVENT, KEY_RELEASE_MASK, key_rels, all);
	mlx_loop_hook(all->win->mlx, game_loop, all);
	mlx_loop(all->win->mlx);
}

void	stop_mlx(t_all *all)
{
	mlx_destroy_image(all->win->mlx, all->win->img->img);
	mlx_destroy_window(all->win->mlx, all->win->win);
	//mlx_destroy_display(all->win->mlx);
	free(all->win->img);
	free(all->win->mlx);
	free_all(all);
}
