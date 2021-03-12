/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:33:58 by jpeyron           #+#    #+#             */
/*   Updated: 2021/03/12 21:18:14 by jules            ###   ########.fr       */
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
	else if (!ft_strcmp(type, "F") && all->txtrs[F_TXTR].path)
		return (1);
	else if (!ft_strcmp(type, "C") && all->txtrs[C_TXTR].path)
		return (1);
	else if (!ft_strcmp(type, "NO") && all->txtrs[NO_TXTR].path)
		return (1);
	else if (!ft_strcmp(type, "SO") && all->txtrs[SO_TXTR].path)
		return (1);
	else if (!ft_strcmp(type, "WE") && all->txtrs[WE_TXTR].path)
		return (1);
	else if (!ft_strcmp(type, "EA") && all->txtrs[EA_TXTR].path)
		return (1);
	else if (!ft_strcmp(type, "WEA") && all->txtrs[K_TXTR].path)
		return (1);
	else if (!ft_strcmp(type, "DO") && all->txtrs[DO_TXTR].path)
		return (1);
	else if (type[0] == 'S' && get_sptexture(all->sp_txtrs, type[1] + 1))
		return (1);
	else
		return (0);
}

void	handle_map(t_all *all, char *line, int *err)
{
	if (!all->at_map && (!is_att_set(all, "R") || !is_att_set(all, "F")
			|| !is_att_set(all, "C") || !is_att_set(all, "NO")
			|| !is_att_set(all, "SO") || !is_att_set(all, "WE")
			|| !is_att_set(all, "EA") || !is_att_set(all, "WEA")))
	{
		*err = error(ATTRIBUTE_MISSING, "", 0);
		all->at_map = 1;
		return ;
	}
	if (!all->at_map)
		all->at_map = 1;
	check_map_line(all->map, all->sp_txtrs, line, err);
}

int		free_after_verifs(int err, char *line, t_all *all, char **split)
{
	if (err)
	{
		free(line);
		if (!all->at_map)
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
	if (*line && skip_spaces(line) && !ft_isdigit(skip_spaces(line)[0]))
	{
		if (all->at_map)
		{
			err = error(LINES_AFTER_MAP, "", 0);
			return (free_after_verifs(err, line, all, NULL));
		}
		split = ft_split(line, " \b\t\v\f\r");
		if (is_att_set(all, split[0]))
			err = error(ATTRIBUTE_ALREADY_SET, split[0], 0);
		else
			verify_nset_ids(all, split, &err, line);
		if (!err)
			free(split);
	}
	else if (*line && skip_spaces(line) && ft_isdigit(skip_spaces(line)[0]))
		handle_map(all, line, &err);
	return (free_after_verifs(err, line, all, split));
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
	else if (all->map->line && all->at_map)
		make_map(all);
	else
		error(FILE_MISSING_MAP, "", 1);
	return (1);
}
