/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:33:58 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/19 19:33:40 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "cub3d.h"

int		is_att_set(t_all *all, char *type)
{
	if (!ft_strcmp(type, "R") && all->win->wid != 0 && all->win->len)
		return (1);
	else if (get_texture(all->txtrs, type))
		return (1);
	else
		return (0);
}

void	handle_map(t_all *all, char *line, int *err)
{
	if (!all->at_map)
		all->at_map = 1;
	check_map_line(all->map, all->txtrs, line, err);
}

int		check_line(t_all *all, char *line)
{
	char	**split;
	int		err;

	err = 0;
	if (*line && !ft_isdigit(line[0]))
	{
		split = ft_split(line, " \b\t\v\f\r");
		if (is_att_set(all, split[0]))
			err = error(ATTRIBUTE_ALREADY_SET, split[0], 0);
		else
			verify_nset_ids(all, split, &err, line);
		if (!err)
			free(split);
	}
	else if (*line && ft_isdigit(line[0]))
		handle_map(all, line, &err);
	if (err)
	{
		free(line);
		ft_free_split(split);
		return (0);
	}
	return (1);
}

int		gnl_read(t_all *all, char *file)
{
	char	*line;
	int		fd;
	int		err;

	if ((fd = open(file, O_RDONLY)) < 0)
		error(OPEN_FILE_FAILED, file, 1);
	while ((err = get_next_line(fd, &line)) == 1)
	{
		if (!check_line(all, line))
			return (0);
		free(line);
	}
	if (err == -1)
		error(errno == 21 ? CANT_OPEN_DIR : GNL_FAILED, errno == 21 ? file :
			line, 1);
	else if (all->map->line && all->at_map)
		make_map(all);
	else
		error(FILE_MISSING_ARGS, "", 1);
	return (1);
}

int		read_file(t_all *all, char *file)
{
	char	**split;

	split = ft_split(file, ".");
	if (!split[1] || (split[1] && ft_strcmp(split[1], "cub")))
	{
		ft_free_split(split);
		error(FILE_WRONG_EXTENSION, file, 1);
	}
	ft_free_split(split);
	return (!gnl_read(all, file));
}
