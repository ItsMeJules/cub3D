/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_attributes_reader.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:18:40 by jpeyron           #+#    #+#             */
/*   Updated: 2021/01/26 17:24:12 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "cub3d.h"
#include "libft.h"

int		check_valid(char *str, int type)
{
	int	i;

	i = -1;
	if (type == 1)
	{
		while (str[++i])
		{
			if (!ft_isdigit(str[i]))
				return (SMTH_INVALID);
		}
	}
	else if (type == 2 && open(str, O_RDONLY) < 0)
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
		if (check_valid(split[1], 1) && !check_valid(split[2], 1))
			return (*err = error(SMTH_INVALID, line, 0));
	}
	else if (type == 2)
	{
		if (check_valid(split[1], 1) || !check_valid(split[2], 1)
				|| check_valid(split[3], 1))
			return (*err = error(SMTH_INVALID, line, 0));
	}
	else if (type == 3)
	{
		if (check_valid(split[1], 2))
			return (*err = error(OPEN_FILE_FAILED, split[1], 0));
	}
	return (0);
}

void	verify_nset_ids(t_all *all, char **split, int *err, char *line)
{
	if (!ft_strcmp(split[0], "R"))
	{
		if (arg_len(split, err, line, 1) || val_verifs(split, err, line, 1))
			return ;
		set_attributes(all, 1, split);
	}
	else if (!ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
	{
		if (arg_len(split, err, line, 2) || val_verifs(split, err, line, 2))
			return ;
		set_attributes(all, 2, split);
	}
	else if (is_dir(split[0]))
	{
		if (arg_len(split, err, line, 3) || val_verifs(split, err, line, 3))
			return ;
		set_attributes(all, 3, split);
	}
	else if (!*err)
		*err = error(SMTH_INVALID, line, 0);
}

int		check_line(t_all *all, char *line)
{
	char	**split;
	int		err;

	err = 0;
	if (!all->win.len && !all->win.wid && !all->map.gr && !all->map.ce
			&& !all->so_txtr.path && !all->no_txtr.path && !all->we_txtr.path
			&& !all->ea_txtr.path && !all->s_txtr.path)
	{
		if ((line[0] == 'F' || line[0] == 'C') && ft_isspace(line[1]))
			split = ft_split(line, " \b\t\v\f\r,");
		else
			split = ft_split(line, " \b\t\v\f\r");
		verify_nset_ids(all, split, &err, line);
	}
	else
	{
		err = 0;	
	}
	if (err)
	{
		free(line);
		ft_free_split(split);
		exit(0);
	}
	return (1);
}
