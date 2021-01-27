/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:39:01 by jules             #+#    #+#             */
/*   Updated: 2021/01/26 12:11:46 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include "libft.h"

void	files_error(int type, char *print)
{
	ft_putstr_fd("Error\n", 2);
	if (type == OPEN_FILE_FAILED)
		ft_printf("Failed to open file '%s'", print);
	else if (type == GNL_FAILED)
		ft_printf("Failed to read the following line : \n\t%s", print);
	else if (type == SMTH_INVALID)
		ft_printf("Something is invalid in the following string '%s'", print);
	else if (type == TOO_MANY_ARGS)
		ft_printf("Too many arguments in the following string '%s'", print);
	else if (type == FILE_WRONG_EXTENSION) 
		ft_printf("The file '%s' does not have the expected extension", print);
	else if (type == TOO_FEW_ARGS) 
		ft_printf("Too few arguments in the following string '%s'", print);
}

int	error(int type, char *print, int ex)
{
	if (type == MALLOC_FAILED)
		ft_printf("Malloc failed for '%s'", print);
	else if (type >= MIN_FILE_ERROR && type <= MAX_FILE_ERROR)
		files_error(type, print);
	ft_printf("\nQuitting program...");
	if (ex)
		exit(0);
	return (1);
}