/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:50:28 by jules             #+#    #+#             */
/*   Updated: 2021/03/03 01:08:24 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	get_decimals(double nb)
{
	return (nb - floor(nb));
}

double	ft_min(double n1, double n2)
{
	return (n1 > n2 ? n2 : n1);
}