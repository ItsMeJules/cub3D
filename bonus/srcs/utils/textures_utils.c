/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:19:57 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/19 12:13:01 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*get_texture(t_list *txtrs, int txtr)
{
	while (txtrs && txtr--)	
		txtrs = txtrs->next;
	return ((t_texture *)txtrs->content);
}

t_texture	*get_sptexture(t_list *txtrs, int sprite_num)
{
	t_texture	*txtr;

	while (txtrs)
	{
		txtr = (t_texture *)txtrs->content;
		if (txtr->is_sprite && !sprite_num--)
			return (txtr);
		txtrs = txtrs->next;
	}
}
