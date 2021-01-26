/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:33:58 by jpeyron           #+#    #+#             */
/*   Updated: 2021/01/26 16:21:15 by jpeyron          ###   ########.fr       */
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

void	read_map(t_map *map, char *file)
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
		if (*line && !check_line(map, line))
			free(line);
	}
	if (err == -1)
		error(GNL_FAILED, line, 1);
}
