/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:06:10 by jules             #+#    #+#             */
/*   Updated: 2021/01/24 18:24:21 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		close_win(t_win *win)
{
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
	return (0);
}

int		close_win_key(int keycode, t_win *win)
{
	if (keycode != ESC_KEY)
		return (1);
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
	return (0);
}

void	handle_destroy_win(t_win *win)
{
	mlx_hook(win->win, DESTROY_WIN, 1L<<2, close_win, win);
	mlx_hook(win->win, KEY_PRESS, KEY_PRESS_MASK, close_win_key, win);
}
