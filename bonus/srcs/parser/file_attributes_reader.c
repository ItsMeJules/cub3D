/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_attributes_reader.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:18:40 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/18 17:19:19 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int		is_tsprite(char *id)
{
	int	i;
	
	i = 0;
	while (id[++i])
	{
		if (!ft_isdigit(id[i]))	
			return (0);
	}
	return (1);
}

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
	else if (!ft_strncmp(split[0], "S", 1) &&)
		all->txtrs[S_TXTR].path = split[1];
	else if (!ft_strcmp(split[0], "F"))
		all->txtrs[F_TXTR].path = split[1];
	else if (!ft_strcmp(split[0], "C"))
	{
		all->txtrs[C_TXTR].path = split[1];
		splitted = ft_split(split[1], "/");
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
		all->all_set++;
	}
	else if (!ft_strcmp(split[0], "NO") || !ft_strcmp(split[0], "SO")
			|| !ft_strcmp(split[0], "WE") || !ft_strcmp(split[0], "EA")
			|| !ft_strcmp(split[0], "S") || !ft_strcmp(split[0], "F")
			|| !ft_strcmp(split[0], "C"))
	{
		if (arg_len(split, err, line, 2) || val_verifs(split, err, line, 2))
			return ;
		set_attributes(all, 2, split);
		all->all_set++;
	}
	else if (!*err)
		*err = error(SMTH_INVALID, line, 0);
}
