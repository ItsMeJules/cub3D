/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:33:58 by jpeyron           #+#    #+#             */
/*   Updated: 2021/01/27 22:06:54 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "cub3d.h"
#include "libft.h"

int		check_line(t_all *all, char *line)
{
	char	**split;
	int		err;

	err = 0;
	if (all->all_set != 8)
	{
		if ((line[0] == 'F' || line[0] == 'C') && ft_isspace(line[1]))
			split = ft_split(line, " \b\t\v\f\r,");
		else
			split = ft_split(line, " \b\t\v\f\r");
		verify_nset_ids(all, split, &err, line);
		if (!err)
			free(split[0]); /*au cas ou je reoublie, il faudra free tout ce qui a ete split et assigne aux structures*/
	}
	else
	{
		check_map_line(&all->map, line, &err);
	}
	if (err)
	{
		free(line);
		ft_free_split(split);
		exit(0);
	}
	return (1);
}

void	read_file(t_all *all, char *file)
{
	char	**split;
	char	*line;
	int		fd;
	int		err;

	split = ft_split(file, ".");
	if (split[1] && ft_strcmp(split[1], "cub"))
	{
		ft_free_split(split);
		error(FILE_WRONG_EXTENSION, file, 1);
	}
	ft_free_split(split);
	if ((fd = open(file, O_RDONLY)) < 0)
		error(OPEN_FILE_FAILED, file, 1);
	while ((err = get_next_line(fd, &line)) == 1)
	{
		if (*line)
			check_line(all, line);
		free(line);
	}
	if (err == -1)
		error(errno == 21 ? CANT_OPEN_DIR : GNL_FAILED, errno == 21 ? file :
			line, 1);
	else
		make_map(all);
}
