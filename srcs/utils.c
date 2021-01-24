/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:39:01 by jules             #+#    #+#             */
/*   Updated: 2021/01/24 15:43:29 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include "libft.h"

void	*error(int type)
{
	if (type == 0)
		ft_putstr_fd("Malloc failed quitting program...", 2);
	exit(0);
	return (NULL);
}
