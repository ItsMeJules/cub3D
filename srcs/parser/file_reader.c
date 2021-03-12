/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:33:58 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/12 21:10:51 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int		is_att_set(t_all *all, char *type)
{
	if (!ft_strcmp(type, "R") && all->win->wid != 0 && all->win->len)
		return (1);
	else if (!ft_strcmp(type, "F") && all->map->gr != 0)
		return (1);
	else if (!ft_strcmp(type, "C") && all->map->ce != 0)
		return (1);
	else if (!ft_strcmp(type, "NO") && all->txtrs[NO_TXTR].path)
		return (1);
	else if (!ft_strcmp(type, "SO") && all->txtrs[SO_TXTR].path)
		return (1);
	else if (!ft_strcmp(type, "WE") && all->txtrs[WE_TXTR].path)
		return (1);
	else if (!ft_strcmp(type, "EA") && all->txtrs[EA_TXTR].path)
		return (1);
	else if (!ft_strcmp(type, "S") && all->txtrs[S_TXTR].path)
		return (1);
	else
		return (0);
}

void	handle_map(t_all *all, char *line, int *err)
{
	if (all->all_set == 8)
	{
		if ((!ft_isdigit(line[0]) && !ft_isspace(line[0])) && all->map->line)
			*err = error(LINES_AFTER_MAP, "", 0);
		else
			check_map_line(all->map, line, err);
	}
}

int		free_on_err(int err, char *line, t_all *all, char **split)
{
	if (err)
	{
		free(line);
		if (all->all_set != 8)
			ft_free_split(split);
		return (0);
	}
	return (1);
}

int		check_line(t_all *all, char *line)
{
	char	**split;
	int		err;

	err = 0;
	split = NULL;
	if (all->all_set != 8 && *line)
	{
		if ((f_lter(line, 'F') && ft_isspace(f_lter(line, 'F')[1]))
				|| (f_lter(line, 'C') && ft_isspace(f_lter(line, 'C')[1])))
			split = count_comas(line, &err);
		else
			split = ft_split(line, " \b\t\v\f\r");
		if (split && is_att_set(all, split[0]))
			err = error(ATTRIBUTE_ALREADY_SET, split[0], 0);
		else if (split)
			verify_nset_ids(all, split, &err, line);
		free_after_verifs(err, split);
	}
	else
		handle_map(all, line, &err);
	return (free_on_err(err, line, all, split));
}

int		gnl_read(t_all *all, int fd, int invalid, char *file)
{
	char	*line;
	int		err;

	while ((err = get_next_line(fd, &line)) == 1)
	{
		if (!invalid)
		{
			if (!(invalid = !check_line(all, line)))
				free(line);
		}
		else
			free(line);
	}
	close(fd);
	if (invalid)
		return (0);
	if (err == -1)
		error(errno == 21 ? CANT_OPEN_DIR : GNL_FAILED, errno == 21 ? file :
			line, 1);
	else if (all->map->line && all->all_set == 8)
		make_map(all);
	else
		error(FILE_MISSING_ARGS, "", 1);
	return (1);
}
