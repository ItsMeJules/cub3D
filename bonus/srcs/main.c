/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:13:11 by jules             #+#    #+#             */
/*   Updated: 2021/03/09 16:47:13 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
** BONUS:
** 1: Collisions
** 2: Skybox
** 3: Text sol & plafond
** 4: HUD
** 5: Vue haut bas
** 6: Ombre distance
** 8: Vie
** 9: Sprites modulable
** 10: Collision sprites murs
** 11: Portes ouvertes fermees
** 12: Portes secretes
** 13: Decelration du joueur
** 14: Perte de vie
** 15: Weapon & Kill
** 16: Minimap
*/

int	main(int ac, char **av)
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
	init_minimap(all);
	start_mlx(all, !save);
	stop_mlx(all);
	return (0);
}
