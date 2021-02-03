/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:39:01 by jules             #+#    #+#             */
/*   Updated: 2021/02/01 16:05:16 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include "libft.h"

void	files_error2(int type, char *print)
{
	if (type == NEGATIVE_RESOLUTION)
		ft_printf("Why the fuck is the resolution negative ?", print);
	else if (type == FILE_MISSING_ARGS)
		ft_printf("The file is incomplete some attributes or map are missing.");
	else if (type == PLAYER_START_POS_NOT_FOUND)
		ft_printf("The starting position for the player was not found.");
	else if (type == LINES_AFTER_MAP)
		ft_printf("There are extra lines after the map.");
	else if (type == ATTRIBUTE_ALREADY_SET)
		ft_printf("The '%s' attribute was already set !", print);
}

void	files_error(int type, char *print)
{
	ft_putstr_fd("Error\n", 1);
	if (type == OPEN_FILE_FAILED)
		ft_printf("Failed to open file '%s'", print);
	else if (type == GNL_FAILED)
		ft_printf("Failed to read the following line : \n\t%s", print);
	else if (type == SMTH_INVALID)
		ft_printf("Attribut is invalid in the following string '%s'", print);
	else if (type == TOO_MANY_ARGS)
		ft_printf("Too many arguments in the following string '%s'", print);
	else if (type == FILE_WRONG_EXTENSION)
		ft_printf("The file '%s' does not have the expected extension", print);
	else if (type == TOO_FEW_ARGS)
		ft_printf("Too few arguments in the following string '%s'", print);
	else if (type == PLAYER_POS_ALREADY_SET)
		ft_printf("Player starting pos already set, error at line %s", print);
	else if (type == INVALID_CHAR_IN_MAP)
		ft_printf("The char '%c' is invalid in the map", *print);
	else if (type == CANT_OPEN_DIR)
		ft_printf("'%s' is a directory !", print);
	else if (type == MAP_NOT_CLOSED)
		ft_printf("The map is not closed !");
	else
		files_error2(type, print);
}

int		error(int type, char *print, int ex)
{
	if (type == MALLOC_FAILED)
		ft_printf("Malloc failed for '%s'", print);
	else if (type >= MIN_FILE_ERROR && type <= MAX_FILE_ERROR)
		files_error(type, print);
	else if (type == NO_CUB_FILE_SPECIFIED)
		ft_putstr_fd("No map file was specified. Please specify one.", 1);
	ft_printf("\nQuitting program...");
	if (ex)
		exit(0);
	return (1);
}
