/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_attributes_reader.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:18:40 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/19 21:23:44 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

void	set_textures(t_all *all, char **split)
{
	char	**splitted;

	if (!ft_strcmp(split[0], "NO"))
		all->txtrs[NO_TXTR].path = split[1];
	else if (!ft_strcmp(split[0], "SO"))
		all->txtrs[SO_TXTR].path = split[1];
	else if (!ft_strcmp(split[0], "WE"))
		all->txtrs[WE_TXTR].path = split[1];
	else if (!ft_strcmp(split[0], "EA"))
		all->txtrs[EA_TXTR].path = split[1];
	else if (split[0][0] == 'F')
		all->txtrs[F_TXTR].path = split[1];
	else if (split[0][0] == 'C')
	{
		all->txtrs[C_TXTR].path = split[1];
		splitted = ft_split(split[1], "/");
		if (!ft_strncmp(splitted[ft_split_size(splitted) - 1], "sky", 3))
			all->skybox = 1;
		else
			all->skybox = 0;
		ft_free_split(splitted);
	}
	free(split[0]);
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
		if (split[0][0] == 'S' && ft_isdigit(split[0][1]))
		{
			ft_lstadd_back(&all->sp_txtrs, ft_lstnew(new_txtr(split[1],
							split[0])));
		}
		else
			set_textures(all, split);
	}
}

void	verify_nset_ids(t_all *all, char **split, int *err, char *line)
{
	if (!ft_strcmp(split[0], "R"))
	{
		if (arg_len(split, err, line, 1) || val_verifs(split, err, line, 1))
			return ;
		set_attributes(all, 1, split);
		free(split[0]);
	}
	else if (!ft_strcmp(split[0], "NO") || !ft_strcmp(split[0], "SO")
			|| !ft_strcmp(split[0], "WE") || !ft_strcmp(split[0], "EA")
			|| (split[0][0] == 'S'
				&& split[0][1] != '0' && ft_isdigit(split[0][1]))
			|| !ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
	{
		if (arg_len(split, err, line, 2) || val_verifs(split, err, line, 2))
			return ;
		set_attributes(all, 2, split);
	}
	else if (!*err)
		*err = error(SMTH_INVALID, line, 0);
}
