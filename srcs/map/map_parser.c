/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:32:58 by jpeyron           #+#    #+#             */
/*   Updated: 2021/01/27 16:04:49 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	concat_line(t_map *map, char *line)
{
	char	*tmp;
	int		line_wid;

	map->len++;
	if ((line_wid = ft_strlen(line)) > map->wid)
		map->wid = line_wid;
	if (map->line != NULL)
		tmp = ft_strjoin_sep(map->line, ";", line);
	else
		tmp = ft_strjoin("", line);
	free(map->line);
	map->line = tmp;
}

void	check_map_line(t_map *map, char *line, int *err)
{
	int		i;
	
	i = -1;
	while (line[++i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
				|| line[i] == 'E')
		{
			if (map->start_dir)
			{
				*err = error(PLAYER_POS_ALREADY_SET, line, 1);
				return ;
			}
			map->start_dir = line[i];
			line[i] = '0';
		}
		else if (ft_isspace(line[i]))
			line[i] = ' ';
		else if (line[i] != '0' && line[i] != '1' && line[i] != '2')
		{
			*err = error(INVALID_CHAR_IN_MAP, &line[i], 1);
			return ;
		}
	}
	concat_line(map, line);
}

void	rewrite_line(t_map *map, char *final, int *j, int i)
{
	int	k;

	k = 0;
	while (map->line[++i])
	{
		if (map->line[i] != ';')
		{
			final[(*j)++] = map->line[i];
			k++;
			if (map->line[i + 1] && map->line[i + 1] == ';')
			{
				while (++k < map->wid - 1)
					final[(*j)++] = ' ';
				final[(*j)++] = '#';
			}
		}
		else
		{
			final[(*j)++] = '#';
			k = 0;
		}
	}
	while (++k < map->wid - 1)
		final[(*j)++] = ' ';
}

void	make_map(t_map *map)
{
	char	*final;
	int		i;
	int		j;

	map->wid += 2;
	map->len += 2;
	final = ft_strnew(map->wid * map->len);
	j = -1;
	while (++j <= map->wid)
		final[j] = '#';
	i = -1;
	final[j] = '#';
	rewrite_line(map, final, &j, i);
	final[j] = '#';
	i = -1;
	while (++i <= map->wid)
		final[j + i] = '#';
	final[j + i] = 0;
}
