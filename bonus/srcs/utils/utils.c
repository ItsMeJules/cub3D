/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:50:28 by jules             #+#    #+#             */
/*   Updated: 2021/03/12 20:13:18 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

double	get_decimals(double nb)
{
	return (nb - floor(nb));
}

double	ft_min(double n1, double n2)
{
	return (n1 > n2 ? n2 : n1);
}

double	ft_max(double n1, double n2)
{
	return (n1 < n2 ? n2 : n1);
}

char	*skip_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isspace(str[i]))
			continue ;
		return (&str[i]);
	}
	return (NULL);
}
