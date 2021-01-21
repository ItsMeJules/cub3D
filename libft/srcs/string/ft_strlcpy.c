/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:28:04 by jules             #+#    #+#             */
/*   Updated: 2020/12/18 17:28:04 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (size != 0)
	{
		while (*src && --size)
			*dest++ = *src++;
		*dest = 0;
	}
	return (srclen);
}
