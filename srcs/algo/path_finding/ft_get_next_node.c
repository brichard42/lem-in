/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:43:25 by brichard          #+#    #+#             */
/*   Updated: 2019/10/01 11:48:48 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_get_links(t_tree_nod **tab_link, t_llist_nod *link, int i)
{
	if (!link)
		return (0);
	if (!link->linked_room->mark)
		tab_link[i++] = link->linked_room;
	if (link->next)
		i = ft_get_links(tab_link, link->next, i);
	return (i);
}

static t_tree_nod	*ft_best_link(t_tree_nod **tab_link)
{
	int i;
	int min_height;

	i = 1;
	if (!tab_link[0])
		return (NULL);
	min_height = tab_link[0]->height;
	while (tab_link[i])
	{
		if (tab_link[i]->height < min_height)
			min_height = tab_link[i]->height;
		i++;
	}
	i = 0;
	while (tab_link[i])
	{
		if (tab_link[i]->height == min_height)
			return (tab_link[i]);
		i++;
	}
	return (NULL);
}

static t_tree_nod	**ft_get_unvisited_links(t_tree_nod *node)
{
	int		num_link;
	t_tree_nod	**link_tree;

	num_link = ft_count_links(node->link_list, -1);
	if (!(link_tree = (t_tree_nod **)ft_memalloc(sizeof(t_tree_nod *) * (num_link + 1))))
		return (NULL);
	if (ft_get_links(link_tree, node->link_list, 0) == 0)
		return (NULL);
	return (link_tree);
}

int				ft_get_next_node(t_path *path, t_tree_nod **node, t_data *program_data)
{
	t_tree_nod	*new;
	t_tree_nod	**links;

	if (!(links = ft_get_unvisited_links(*node)))
		return (2);
	if (!links[0] && !links[1])
		return (ft_free_tree_nod_with_ret(links, 2));
	if (!(new = ft_best_link(links)))
		return (ft_free_tree_nod_with_ret(links, 1));
	if (new != program_data->start)
		new->mark++;
	ft_memdel((void **)&links);
	if (ft_create_path(&path, new) == FAILURE)
		return (1);
	*node = new;
	return (0);
}
