/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:11:05 by brichard          #+#    #+#             */
/*   Updated: 2019/06/27 10:44:05 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*ft_link_new(char *name, t_nod *l_room)
{
	t_link *new;

	if (!l_room)
		return (NULL);
	if (!(new = (t_link *)ft_memalloc(sizeof(t_link))))
		return (NULL);
	if (!(new->name = ft_strdup(name)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	new->l_room = l_room;
	return (new);
}

int		ft_link_add(t_link *parent, t_link **l_tree, char *name, t_nod *r_tree)
{
	if (!*l_tree)
	{
		if (!(*l_tree = ft_link_new(name, ft_search_room(r_tree, name))))
			return (1);
		(*l_tree)->parent = parent;
		return (0);
	}
	else if (ft_strcmp(name, (*l_tree)->name) < 0)
	{
		if (!(ft_link_add(*l_tree, &(*l_tree)->left, name, r_tree)))
			return (1);
	}
	else if (ft_strcmp(name, (*l_tree)->name) > 0)
	{
		if (!(ft_link_add(*l_tree, &(*l_tree)->right, name, r_tree)))
			return (1);
	}
	return (0);
}
