/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 11:08:34 by brichard          #+#    #+#             */
/*   Updated: 2019/06/24 15:27:58 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*ft_link_new(char *name, t_nod *l_room)
{
	t_link *new;

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

int		ft_link_add(t_link *parent, t_link **tree, char *name)
{
	if (!*tree)
	{
		if (!(*tree = ft_link_new(name,)))
			return (1);
		tree->parent = parent;
		return (0);
	}
	else if (ft_strcmp(name, (*tree)->name) < 0)
	{
		if (!(ft_link_add(*tree, &(*tree)->left, name)))
			return (1);
	}
	else if (ft_strcmp(name, (*tree)->name) > 0)
	{
		if (!(ft_link_add(*tree, &(*tree)->right, name)))
			return (1);
	}
	return (0);
}
