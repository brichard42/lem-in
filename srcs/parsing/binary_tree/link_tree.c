/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:11:05 by brichard          #+#    #+#             */
/*   Updated: 2019/09/17 13:36:52 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ltree_nod	*ft_link_new(char *link_name, t_tree_nod *linked_room)
{
	t_ltree_nod *new;

	if (!linked_room)
		return (NULL);
	if (!(new = (t_ltree_nod *)ft_memalloc(sizeof(t_ltree_nod))))
		return (NULL);
	if (!(new->link_name = ft_strdup(link_name)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	new->linked_room = linked_room;
	return (new);
}

int8_t	ft_link_add(t_ltree_nod *parent, t_ltree_nod **l_tree, char *link_name, t_tree_nod *linked_room)
{
	if (*l_tree == NULL)
	{
		*l_tree = ft_link_new(link_name, linked_room);
		if (*l_tree != NULL)
			(*l_tree)->parent = parent;
		return (*l_tree == NULL ? FAILURE : SUCCESS);
	}
	else if (ft_strcmp(link_name, (*l_tree)->link_name) < 0)
	{
		if ((ft_link_add(*l_tree, &(*l_tree)->left, link_name, linked_room)))
			return (FAILURE);
	}
	else if (ft_strcmp(link_name, (*l_tree)->link_name) > 0)
	{
		if ((ft_link_add(*l_tree, &(*l_tree)->right, link_name, linked_room)))
			return (FAILURE);
	}
	return (SUCCESS);
}
