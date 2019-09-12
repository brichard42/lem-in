/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:11:05 by brichard          #+#    #+#             */
/*   Updated: 2019/09/12 18:49:11 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*ft_link_new(char *name, t_tree_nod *linked_room)
{
	t_link *new;

	if (!linked_room)
		return (NULL);
	if (!(new = (t_link *)ft_memalloc(sizeof(t_link))))
		return (NULL);
	if (!(new->name = ft_strdup(name)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	new->linked_room = linked_room;
	return (new);
}

int8_t	ft_link_add(t_link *parent, t_link **l_tree, char *name, t_tree_nod *linked_room)
{
	if (*l_tree == NULL)
	{
		*l_tree = ft_link_new(name, linked_room);
		if (*l_tree != NULL)
			(*l_tree)->parent = parent;
		return (*l_tree == NULL ? FAILURE : SUCCESS);
	}
	else if (ft_strcmp(name, (*l_tree)->name) < 0)
	{
		if ((ft_link_add(*l_tree, &(*l_tree)->left, name, linked_room)))
			return (FAILURE);
	}
	else if (ft_strcmp(name, (*l_tree)->name) > 0)
	{
		if ((ft_link_add(*l_tree, &(*l_tree)->right, name, linked_room)))
			return (FAILURE);
	}
	return (SUCCESS);
}
