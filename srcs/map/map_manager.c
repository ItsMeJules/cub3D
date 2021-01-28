/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:24:07 by jpeyron           #+#    #+#             */
/*   Updated: 2021/01/28 18:47:07 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	print_map(t_map map)
{
	int a;

	a = 0;
	for (int i = 0; map.line[i]; i++)
	{
		if (a % map.wid == 0)
		{
			ft_printf("\n");
			a = 0;
		}
		a++;
		ft_printf("%c", map.line[i]);
	}
}

char	elem_at(int x, int y, t_map map)
{
	return (map.line[(map.wid) * y + x]);
}
