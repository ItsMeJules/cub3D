/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:09:56 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/12 19:17:02 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

char	*f_lter(char *line, char c)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (ft_isalpha(line[i]) && line[i] == c)
			return (&line[i]);
		else if (ft_isalpha(line[i]))
			break ;
	}
	return (NULL);
}
