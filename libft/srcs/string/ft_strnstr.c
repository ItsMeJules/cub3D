/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:29:01 by jules             #+#    #+#             */
/*   Updated: 2020/12/18 17:33:40 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	if (!to_find[0])
		return ((char*)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] && i + j < len &&
				to_find[j] && str[i + j] == to_find[j])
			j++;
		if (!to_find[j])
			return ((char*)&str[i]);
		i++;
	}
	return (NULL);
}
