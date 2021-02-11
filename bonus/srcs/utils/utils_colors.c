/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:09:56 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/11 17:26:16 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		get_r(int trgb)
{
	return ((trgb & 0xFF000000) >> 24);
}

int		get_g(int trgb)
{
	return ((trgb & 0x00FF0000) >> 16);
}

int		get_b(int trgb)
{
	return ((trgb & 0x0000FF00) >> 8);
}
