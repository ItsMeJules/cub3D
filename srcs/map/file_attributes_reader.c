/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_attributes_reader.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:18:40 by jpeyron           #+#    #+#             */
/*   Updated: 2021/01/29 00:19:10 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "cub3d.h"
#include "libft.h"

int		check_valid(char *str, int type)
{
	int	i;
	int	fd;

	i = -1;
	if (type == 1)
	{
		while (str[++i])
		{
			if (!ft_isdigit(str[i]))
				return (SMTH_INVALID);
		}
	}
	else if ((fd = open(str, O_RDONLY)) < 0)
	{
		close(fd);
		return (OPEN_FILE_FAILED);
	}
	else if (fd && read(fd, NULL, 0) == -1)
		return (OPEN_FILE_FAILED);
	return (0);
}

int		arg_len(char **split, int *err, char *line, int type)
{
	if (type == 1)
	{
		if (!split[1] || !split[2])
			return (*err = error(TOO_FEW_ARGS, line, 0));
		else if (split[3])
			return (*err = error(TOO_MANY_ARGS, line, 0));
	}
	else if (type == 2)
	{
		if (!split[1] || !split[2] || !split[3])
			return (*err = error(TOO_FEW_ARGS, line, 0));
		else if (split[4])
			return (*err = error(TOO_MANY_ARGS, line, 0));
	}
	else if (type == 3)
	{
		if (!split[1])
			return (*err = error(TOO_FEW_ARGS, line, 0));
		else if (split[2])
			return (*err = error(TOO_MANY_ARGS, line, 0));
	}
	return (0);
}

int		val_verifs(char **split, int *err, char *line, int type)
{
	if (type == 1)
	{
		if (check_valid(split[1], 1) || check_valid(split[2], 1))
			return (*err = error(SMTH_INVALID, line, 0));
		if (split[1][0] == '-' || split[2][0] == '-')
			return (*err = error(NEGATIVE_RESOLUTION, line, 0));
	}
	else if (type == 2)
	{
		if (check_valid(split[1], 1) || check_valid(split[2], 1)
				|| check_valid(split[3], 1))
			return (*err = error(SMTH_INVALID, line, 0));
	}
	else if (type == 3)
	{
		if (check_valid(split[1], 2))
			return (*err = error(errno == 21 ? CANT_OPEN_DIR : OPEN_FILE_FAILED
						, split[1], 0));
	}
	return (0);
}

void	set_attributes(t_all *all, int type, char **split) //free les attributs tramsformees en int
{
	if (type == 1)
	{
		all->win.wid = ft_atoi(split[1]);
		all->win.len = ft_atoi(split[2]);
		free(split[1]);
		free(split[2]);
	}
	else if (type == 2)
	{
		if (!ft_strcmp(split[0], "F"))
			all->map.gr = create_trgb(0, ft_atoi(split[1]), ft_atoi(split[2]),
				ft_atoi(split[3]));
		else
			all->map.ce = create_trgb(0, ft_atoi(split[1]), ft_atoi(split[2]),
				ft_atoi(split[3]));
		free(split[1]);
		free(split[2]);
		free(split[3]);
	}
	else if (type == 3)
	{
		if (!ft_strcmp(split[0], "NO"))
			all->no_txtr.path = split[1];
		else if (!ft_strcmp(split[0], "SO"))
			all->so_txtr.path = split[1];
		else if (!ft_strcmp(split[0], "WE"))
			all->we_txtr.path = split[1];
		else if (!ft_strcmp(split[0], "EA"))
			all->ea_txtr.path = split[1];
		free(split[1]);
	}
}

void	verify_nset_ids(t_all *all, char **split, int *err, char *line)
{
	ft_printf("%p", split);
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
		ft_printf("test");
		if (arg_len(split, err, line, 3) || val_verifs(split, err, line, 3))
			return ;
		set_attributes(all, 3, split);
		all->all_set++;
	}
	else if (!*err)
		*err = error(SMTH_INVALID, line, 0);
}
