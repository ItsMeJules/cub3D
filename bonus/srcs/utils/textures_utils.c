/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:19:57 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/19 19:46:37 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*get_sptexture(t_list *sp_txtrs, char sprite_num)
{
	t_list		*list;
	t_texture	*txtr;

	list = txtrs;
	while (list)
	{
		txtr = (t_texture *)list->content;
		if ((sprite_num - 1) == txtr->id[1])
			return (txtr);
		list = list->next;
	}
	return (NULL);
}
