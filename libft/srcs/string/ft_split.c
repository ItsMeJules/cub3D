/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:27:06 by jules             #+#    #+#             */
/*   Updated: 2020/12/18 17:34:17 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char sep)
{
	return (c == 0 || c == sep);
}

static int	count_words(char const *s, char sep)
{
	int	i;
	int	count;

	count = 0;
	if (!is_sep(s[0], sep))
		count++;
	i = 0;
	while (s[++i])
	{
		if (!is_sep(s[i], sep) && is_sep(s[i - 1], sep))
			count++;
	}
	return (count + 1);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!(tab = malloc(count_words(s, c) * sizeof(char *))))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (!is_sep(s[i + j], c))
			j++;
		if (j)
		{
			tab[k++] = ft_strndup(&s[i], j);
			i += j;
		}
		else
			i++;
	}
	tab[k] = 0;
	return (tab);
}
