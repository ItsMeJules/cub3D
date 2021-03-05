/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:50:28 by jules             #+#    #+#             */
/*   Updated: 2021/03/05 13:18:20 by jpeyron          ###   ########.fr       */
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

double	ft_max(double n1, double n2)
{
	return (n1 < n2 ? n2 : n1);
}
