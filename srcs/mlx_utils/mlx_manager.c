/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:36:12 by jules             #+#    #+#             */
/*   Updated: 2021/02/11 19:05:07 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	new_window(t_win *win, char name[25], int save)
{
	int	resx;
	int	resy;

	if (!(win->img = malloc(sizeof(t_img))))
	{
		error(MALLOC_FAILED, "t_img in images.c", 1);
		return ;
	}
	win->mlx = mlx_init();
	if (!save)
	{
		mlx_get_screen_size(win->mlx, &resx, &resy);
		if (win->wid > resx)
			win->wid = resx;
		if (win->len > resy)
			win->len = resy;
		win->win = mlx_new_window(win->mlx, win->wid, win->len, name);
	}
	win->img->img = mlx_new_image(win->mlx, win->wid, win->len);
	win->img->addr = mlx_get_data_addr(win->img->img, &win->img->bpp,
			&win->img->line_l, &win->img->endian);
}

int		close_w(t_all *all)
{
	(void)all;
	mlx_loop_end(all->win->mlx);
	return (0);
}

int		load_txtr(t_all *all, t_texture *txtr)
{
	if (!(txtr->img->img = mlx_xpm_file_to_image(all->win->mlx, txtr->path,
					&txtr->wid, &txtr->hei)))
	{
		error(FAILED_TO_LOAD_TXTR, txtr->path, 0);
		free_all(all, 1);
		return (1);
	}
	txtr->img->addr = mlx_get_data_addr(txtr->img->img, &txtr->img->bpp,
			&txtr->img->line_l, &txtr->img->endian);
	return (0);
}

void	start_mlx(t_all *all, int save)
{
	all->save = save;
	new_window(all->win, "Je suis une fenetre", save);
	if (load_txtr(all, &all->txtrs[NO_TXTR])
			|| load_txtr(all, &all->txtrs[SO_TXTR])
			|| load_txtr(all, &all->txtrs[WE_TXTR])
			|| load_txtr(all, &all->txtrs[EA_TXTR])
			|| load_txtr(all, &all->txtrs[S_TXTR]))
		return ;
	if (!(all->ray->z_buffer = malloc(sizeof(double) * all->win->wid)))
		return ;
	if (!save)
	{
		mlx_hook(all->win->win, DESTROY_WIN_EVENT, 1l << 2, close_w, all);
		mlx_hook(all->win->win, KEY_PRESS_EVENT, 1l << 0, key_press, all);
		mlx_hook(all->win->win, KEY_RELEASE_EVENT, 1L << 1, key_rels, all);
	}
	mlx_loop_hook(all->win->mlx, game_loop, all);
	mlx_loop(all->win->mlx);
}

void	stop_mlx(t_all *all)
{
	free_txtrs(all, 1);
	mlx_destroy_image(all->win->mlx, all->win->img->img);
	if (!all->save)
		mlx_destroy_window(all->win->mlx, all->win->win);
	mlx_destroy_display(all->win->mlx);
	free(all->win->img);
	free(all->win->mlx);
	free_all(all, 0);
}
