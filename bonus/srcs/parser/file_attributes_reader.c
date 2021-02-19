/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_attributes_reader.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:18:40 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/19 14:25:42 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

void	set_textures(t_all *all, char **spli)
{
	char	**splitted;

	if (!ft_strcmp(spli[0], "NO")
			|| !ft_strcmp(spli[0], "SO")
			|| !ft_strcmp(spli[0], "WE")
			|| !ft_strcmp(spli[0], "EA")
			|| !ft_strncmp(spli[0], "S", 1)
			|| !ft_strcmp(spli[0], "F"))
		ft_lstadd_back(&all->txtrs, ft_lstnew(new_sprite(spli[1], spli[0])));
	else if (!ft_strcmp(spli[0], "C"))
	{
		ft_lstadd_back(&all->txtrs, ft_lstnew(new_sprite(spli[1], spli[0])));
		splitted = ft_spli(spli[1], "/");
		if (!ft_strncmp(splitted[ft_split_size(splitted) - 1], "sky", 3))
			all->skybox = 1;
		else
			all->skybox = 0;
		ft_free_split(splitted);
	}
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
		set_textures(all, split);
}

void	verify_nset_ids(t_all *all, char **split, int *err, char *line)
{
	if (!ft_strcmp(split[0], "R"))
	{
		if (arg_len(split, err, line, 1) || val_verifs(split, err, line, 1))
			return ;
		set_attributes(all, 1, split);
	}
	else if (!ft_strcmp(split[0], "NO") || !ft_strcmp(split[0], "SO")
			|| !ft_strcmp(split[0], "WE") || !ft_strcmp(split[0], "EA")
			|| (!ft_strncmp(split[0], "S", 1) && ft_isdigit(spli[0][1]))
			|| !ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
	{
		if (arg_len(split, err, line, 2) || val_verifs(split, err, line, 2))
			return ;
		set_attributes(all, 2, split);
		all->all_set++;
	}
	else if (!*err)
		*err = error(SMTH_INVALID, line, 0);
}
