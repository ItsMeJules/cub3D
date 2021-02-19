/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:19:57 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/19 13:46:45 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*get_texture(t_list *txtrs, char *id)
{
	t_texture	*txtr;

	while (txtrs)
	{
		txtr = (t_texture *)txtrs->content;
		if (!ft_strcmp(txtr->id, id))
			return (txtr);
		txtrs = txtrs->next;
	}
	return (NULL);
}

t_texture	*get_sptexture(t_list *txtrs, char sprite_num)
{
	t_texture	*txtr;

	while (txtrs)
	{
		txtr = (t_texture *)txtrs->content;
		if (!ft_strncmp(txtr->id, "S", 1) && (sprite_num - 1) == txtr->id[1])
			return (txtr);
		txtrs = txtrs->next;
	}
	return (NULL);
}
