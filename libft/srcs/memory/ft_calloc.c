/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:26:22 by jules             #+#    #+#             */
/*   Updated: 2020/12/18 17:26:22 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmenb, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(nmenb * size)))
		return (NULL);
	ft_bzero(ptr, nmenb * size);
	return (ptr);
}
