/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:33:58 by jpeyron           #+#    #+#             */
/*   Updated: 2021/01/26 17:21:08 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "cub3d.h"
#include "libft.h"

int		is_dir(char *dir)
{
	return (!ft_strcmp(dir, "NO") || !ft_strcmp(dir, "SO")
			|| !ft_strcmp(dir, "WE") || !ft_strcmp(dir, "EA")
			|| !ft_strcmp(dir, "S"));
}

void	set_attributes(t_all *all, int type, char **split)
{
	if (type == 1)
	{
		all->win.wid = ft_atoi(split[1]);
		all->win.len = ft_atoi(split[2]);
	}
	else if (type == 2)
	{
		if (!ft_strcmp(split[0], "F"))
			all->map.ce = create_trgb(0, ft_atoi(split[1]), ft_atoi(split[2]),
				ft_atoi(split[3]));
		else
			all->map.gr = create_trgb(0, ft_atoi(split[1]), ft_atoi(split[2]),
				ft_atoi(split[3]));
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
	}
}

void	read_file(t_all *all, char *file)
{
	char	**split;
	char	*line;
	int		fd;
	int		err;

	if (ft_strcmp((split = ft_split(file, "."))[1], "cub"))
	{
		ft_free_split(split);
		error(FILE_WRONG_EXTENSION, file, 1);
	}
	if ((fd = open(file, O_RDONLY)) < 0)
		error(OPEN_FILE_FAILED, file, 1);
	while ((err = get_next_line(fd, &line)) == 1)
	{
		if (*line && !check_line(all, line))
			free(line);
	}
	if (err == -1)
		error(GNL_FAILED, line, 1);
}
