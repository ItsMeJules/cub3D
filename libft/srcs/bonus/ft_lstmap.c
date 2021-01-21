/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:23:43 by jules             #+#    #+#             */
/*   Updated: 2020/12/18 17:37:55 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first;

	if (!lst || !f)
		return (NULL);
	first = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew(f(lst->content))))
		{
			while (first)
			{
				new = first->next;
				del(first->content);
				free(first);
				first = new;
			}
			break ;
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
