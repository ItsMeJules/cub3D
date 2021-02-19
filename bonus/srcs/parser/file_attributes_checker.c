/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_attributes_checker.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:46:12 by jules             #+#    #+#             */
/*   Updated: 2021/02/19 14:26:05 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "cub3d.h"

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
	{
		close(fd);
		return (OPEN_FILE_FAILED);
	}
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
		if (ft_atoi(split[1]) <= 0 || ft_atoi(split[2]) <= 0)
			return (*err = error(NEGATIVE_RESOLUTION, line, 0));
	}
	else if (type == 2)
	{
		if (check_valid(split[1], 2))
			return (*err = error(errno == 21 ? CANT_OPEN_DIR : OPEN_FILE_FAILED
						, split[1], 0));
	}
	return (0);
}
