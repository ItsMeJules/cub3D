/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:26:38 by jules             #+#    #+#             */
/*   Updated: 2020/12/18 17:43:30 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *o1;
	unsigned char *o2;

	if (dest == src || n == 0)
		return (dest);
	o1 = (unsigned char*)dest;
	o2 = (unsigned char*)src;
	while (n--)
		*o1++ = *o2++;
	return (dest);
}
