/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assigner2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:15:31 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/04 11:16:50 by jpeyron          ###   ########.fr       */
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
