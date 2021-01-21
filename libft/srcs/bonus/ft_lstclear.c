/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:23:21 by jules             #+#    #+#             */
/*   Updated: 2020/12/18 17:45:06 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		elem = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = elem;
	}
	lst = NULL;
}
