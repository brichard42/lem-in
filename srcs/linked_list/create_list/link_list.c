/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:59:58 by brichard          #+#    #+#             */
/*   Updated: 2019/10/16 16:25:41 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_llist_nod	*ft_link_new(t_tree_nod *linked_room)
{
	t_llist_nod *new;

	new = NULL;
	if (linked_room != NULL)
	{
		new = (t_llist_nod *)ft_memalloc(sizeof(t_llist_nod));
		if (new != NULL)
			new->linked_room = linked_room;
	}
	return (new);
}

int8_t				ft_link_add(t_llist_nod **l_list, t_tree_nod *linked_room)
{
	if (*l_list == NULL)
		*l_list = ft_link_new(linked_room);
	else if ((*l_list)->linked_room != linked_room)
		if (ft_link_add(&(*l_list)->next, linked_room) == FAILURE)
			return (FAILURE);
	return (*l_list == NULL ? FAILURE : SUCCESS);
}
