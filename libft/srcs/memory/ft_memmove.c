/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:26:44 by jules             #+#    #+#             */
/*   Updated: 2020/12/18 17:37:13 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cd;
	unsigned char	*cs;

	if (!src && !dest)
		return (dest);
	cd = (unsigned char *)dest;
	cs = (unsigned char *)src;
	if (cs < cd)
	{
		while (n--)
			cd[n] = cs[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
