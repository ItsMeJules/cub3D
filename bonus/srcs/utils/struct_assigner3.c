/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assigner3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:33:00 by jules             #+#    #+#             */
/*   Updated: 2021/03/10 14:34:19 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_all	*extra_malloc(void)
{
	t_all	*all;

	if (!(all = malloc(sizeof(t_all))))
	{
		error(MALLOC_FAILED, "t_all in struct_assigner.c", 1);
		return (NULL);
	}
	if (!(all->ray = malloc(sizeof(t_ray))))
	{
		error(MALLOC_FAILED, "t_ray in struct_assigner.c", 1);
		return (NULL);
	}
	return (all);
}
