/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:13:11 by jules             #+#    #+#             */
/*   Updated: 2021/02/08 09:47:47 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h" 
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/*void	print_map(t_map *map)
{
	int a;

	a = 0;
	for (int i = 0; map->line[i]; i++)
	{
		if (a % map->wid == 0)
			ft_printf("\n");
		a++;
		ft_printf("%c", map->line[i]);
	}
}*/

int main(int ac, char **av)
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
		free_all(all);
		return (0);
	}
	//print_map(all->map);
	start_mlx(all, !save);
	stop_mlx(all);
	return (0);
}
