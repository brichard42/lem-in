/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:11:05 by brichard          #+#    #+#             */
/*   Updated: 2019/10/01 11:52:35 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_llist_nod	*ft_link_new(t_tree_nod *linked_room)
{
	t_llist_nod *new;

	if (!linked_room)
		return (NULL);
	if (!(new = (t_llist_nod *)ft_memalloc(sizeof(t_llist_nod))))
		return (NULL);
	new->linked_room = linked_room;
	return (new);
}

int8_t				ft_link_add(t_llist_nod **l_list, t_tree_nod *linked_room)
{
	if (*l_list == NULL)
	{
		*l_list = ft_link_new(linked_room);
		return (*l_list == NULL ? FAILURE : SUCCESS);
	}
	else if (!(*l_list)->next || (*l_list)->next->linked_room != linked_room)
		ft_link_add(&(*l_list)->next, linked_room);
	return (SUCCESS);
}
