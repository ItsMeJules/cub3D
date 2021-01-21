/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:29:18 by jules             #+#    #+#             */
/*   Updated: 2020/12/18 17:29:19 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		if (!(cpy = malloc(sizeof(char))))
			return (NULL);
		cpy[0] = 0;
		return (cpy);
	}
	i = 0;
	s += start;
	while (s[i] && i < len)
		i++;
	if (!(cpy = ft_strnew(i)))
		return (NULL);
	i = -1;
	while (++i < len && s[i])
		cpy[i] = s[i];
	cpy[i] = 0;
	return (cpy);
}
