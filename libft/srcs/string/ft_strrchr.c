/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:29:06 by jules             #+#    #+#             */
/*   Updated: 2020/12/18 17:29:07 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	char	*last;

	str = (char *)s;
	i = -1;
	last = NULL;
	while (s[++i])
	{
		if (s[i] == c)
			last = &str[i];
	}
	if (c == 0)
		return (&str[i]);
	return (last);
}
