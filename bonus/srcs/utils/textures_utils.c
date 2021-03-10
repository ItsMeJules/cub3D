/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:19:57 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/10 18:04:29 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*get_sptexture(t_list *sp_txtrs, char sprite_num)
{
	t_list		*list;
	t_texture	*txtr;

	list = sp_txtrs;
	while (list)
	{
		txtr = (t_texture *)list->content;
		if ((sprite_num - 1) == txtr->id[1])
			return (txtr);
		list = list->next;
	}
	return (NULL);
}

int			load_txtr(t_all *all, t_texture *txtr)
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

int			load_txtrs(t_all *all)
{
	t_list		*list;
	int			i;

	i = -1;
	while (++i <= K1_TXTR)
	{
		if (load_txtr(all, &all->txtrs[i]))
			return (1);
	}
	list = all->sp_txtrs;
	while (list)
	{
		if (load_txtr(all, (t_texture *)list->content))
			return (1);
		list = list->next;
	}
	return (0);
}
