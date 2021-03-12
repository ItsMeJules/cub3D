/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:13:11 by jules             #+#    #+#             */
/*   Updated: 2021/03/12 17:00:32 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int		read_file(t_all *all, char *file)
{
	char	**split;
	int		fd;

	split = ft_split(file, ".");
	if (!split[1] || (split[1] && ft_strcmp(split[1], "cub")))
	{
		ft_free_split(split);
		error(FILE_WRONG_EXTENSION, file, 1);
	}
	ft_free_split(split);
	if ((fd = open(file, O_RDONLY)) < 0)
		error(OPEN_FILE_FAILED, file, 1);
	return (!gnl_read(all, fd, 0, file));
}

int		main(int ac, char **av)
{
	t_all	*all;
	int		save;

	save = 1;
	if (ac < 2)
	{
		error(NO_CUB_FILE_SPECIFIED, "", 1);
		return (0);
	}
	else if (ac > 2 && (save = ft_strcmp("--save", av[2])) != 0)
	{
		error(UNKNOWN_ARGUMENT, av[2], 1);
		return (0);
	}
	all = new_all();
	if (read_file(all, av[1]))
	{
		free_all(all, 1);
		return (0);
	}
	start_mlx(all, !save);
	stop_mlx(all);
	return (0);
}
