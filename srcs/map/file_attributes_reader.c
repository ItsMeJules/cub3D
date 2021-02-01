/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_attributes_reader.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:18:40 by jpeyron           #+#    #+#             */
/*   Updated: 2021/01/29 16:41:56 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "cub3d.h"
#include "libft.h"

void	set_texture_path(t_all *all, char **split)
{
	if (!ft_strcmp(split[0], "NO"))
		all->no_txtr->path = split[1];
	else if (!ft_strcmp(split[0], "SO"))
		all->so_txtr->path = split[1];
	else if (!ft_strcmp(split[0], "WE"))
		all->we_txtr->path = split[1];
	else if (!ft_strcmp(split[0], "EA"))
		all->ea_txtr->path = split[1];
	else if (!ft_strcmp(split[0], "S"))
		all->s_txtr->path = split[1];
}

void	set_attributes(t_all *all, int type, char **split)
{
	if (type == 1)
	{
		all->win->wid = ft_atoi(split[1]);
		all->win->len = ft_atoi(split[2]);
		free(split[1]);
		free(split[2]);
	}
	else if (type == 2)
	{
		if (!ft_strcmp(split[0], "F"))
			all->map->gr = create_trgb(0, ft_atoi(split[1]), ft_atoi(split[2]),
				ft_atoi(split[3]));
		else
			all->map->ce = create_trgb(0, ft_atoi(split[1]), ft_atoi(split[2]),
				ft_atoi(split[3]));
		free(split[1]);
		free(split[2]);
		free(split[3]);
	}
	else if (type == 3)
		set_texture_path(all, split);
}

void	verify_nset_ids(t_all *all, char **split, int *err, char *line)
{
	if (!ft_strcmp(split[0], "R"))
	{
		if (arg_len(split, err, line, 1) || val_verifs(split, err, line, 1))
			return ;
		set_attributes(all, 1, split);
		all->all_set++;
	}
	else if (!ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
	{
		if (arg_len(split, err, line, 2) || val_verifs(split, err, line, 2))
			return ;
		set_attributes(all, 2, split);
		all->all_set++;
	}
	else if (!ft_strcmp(split[0], "NO") || !ft_strcmp(split[0], "SO")
			|| !ft_strcmp(split[0], "WE") || !ft_strcmp(split[0], "EA")
			|| !ft_strcmp(split[0], "S"))
	{
		if (arg_len(split, err, line, 3) || val_verifs(split, err, line, 3))
			return ;
		set_attributes(all, 3, split);
		all->all_set++;
	}
	else if (!*err)
		*err = error(SMTH_INVALID, line, 0);
}
