/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:13:11 by jules             #+#    #+#             */
/*   Updated: 2021/02/04 17:19:03 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h" 
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int ac, char **av)
{
	t_all *all;

	if (ac < 2)
	{
		error(NO_CUB_FILE_SPECIFIED, "", 1);
		return (0);
	}
	all = new_all();
	if (read_file(all, av[1]))
	{
		free_all(all);
		return (0);
	}
	start_mlx(all);
	stop_mlx(all);
	return (0);
}
