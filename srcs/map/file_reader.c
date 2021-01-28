/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:33:58 by jpeyron           #+#    #+#             */
/*   Updated: 2021/01/28 19:15:51 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "cub3d.h"
#include "libft.h"

/*penser a fix les espaces dans la map | les , en trop dans le rgb*/

int		is_att_set(t_all *all, char *type)
{
	if (!ft_strcmp(type, "R") && all->win.wid != 0 && all->win.len)
		return (1);
	else if (!ft_strcmp(type, "F") && all->map.gr != 0)
		return (1);
	else if (!ft_strcmp(type, "C") && all->map.ce != 0)
		return (1);
	else if (!ft_strcmp(type, "NO") && all->no_txtr.path)
		return (1);
	else if (!ft_strcmp(type, "SO") && all->so_txtr.path)
		return (1);
	else if (!ft_strcmp(type, "WE") && all->we_txtr.path)
		return (1);
	else if (!ft_strcmp(type, "EA") && all->ea_txtr.path)
		return (1);
	else if (!ft_strcmp(type, "S") && all->s_txtr.path)
		return (1);
	else
		return (0);
}

char	**count_comas(char *line)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (line[++i])
	{
		if (line[i] == ',')
		{
			if (c == 2)
			{
				error(SMTH_INVALID, line, 1);
				return (NULL);
			}
			c++;
		}
	}
	return (ft_split(line, " \b\t\v\f\r,"));
}

int		check_line(t_all *all, char *line)
{
	char	**split;
	int		err;

	err = 0;
	if (all->all_set != 8 && *line)
	{
		if ((line[0] == 'F' || line[0] == 'C') && ft_isspace(line[1]))
			split = count_comas(line);
		else
			split = ft_split(line, " \b\t\v\f\r");
		if (is_att_set(all, split[0]))
			err = error(ATTRIBUTE_ALREADY_SET, split[0], 0);
		else
			verify_nset_ids(all, split, &err, line);
		if (!err)
			free(split[0]); /*au cas ou je reoublie, il faudra free tout ce qui a ete split et assigne aux structures*/
	}
	else if (all->all_set == 8)
		check_map_line(&all->map, line, &err);
	if (err)
	{
		free(line);
		ft_free_split(split);
		exit(0);
	}
	return (1);
}

void	gnl_read(t_all *all, char *file)
{
	char	*line;
	int		fd;
	int		err;

	if ((fd = open(file, O_RDONLY)) < 0)
		error(OPEN_FILE_FAILED, file, 1);
	while ((err = get_next_line(fd, &line)) == 1)
	{
		check_line(all, line);
		free(line);
	}
	if (err == -1)
		error(errno == 21 ? CANT_OPEN_DIR : GNL_FAILED, errno == 21 ? file :
			line, 1);
	else if (all->all_set == 8)
		make_map(all);
	else
		error(FILE_MISSING_ARGS, "", 1);
}

void	read_file(t_all *all, char *file)
{
	char	**split;

	split = ft_split(file, ".");
	if (!split[1] || (split[1] && ft_strcmp(split[1], "cub")))
	{
		ft_free_split(split);
		error(FILE_WRONG_EXTENSION, file, 1);
	}
	ft_free_split(split);
	gnl_read(all, file);
}
