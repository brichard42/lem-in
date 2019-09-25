/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_paths2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:25:34 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/24 15:41:49 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_get_links(t_tree_nod **tab_link, t_ltree_nod *link, int i)
{
	if (!link)
		return (0);
	if (!link->linked_room->mark)
		tab_link[i++] = link->linked_room;
	if (link->left)
		i = ft_get_links(tab_link, link->left, i);
	if (link->right)
		i = ft_get_links(tab_link, link->right, i);
	return (i);
}

static t_tree_nod	**ft_get_unvisited_links(t_tree_nod *node)
{
	int		num_link;
	t_tree_nod	**link_tree;

	num_link = ft_count_links(node->link_tree, -1);
	if (!(link_tree = (t_tree_nod **)ft_memalloc(sizeof(t_tree_nod *) * (num_link + 1))))
		return (NULL);
	if (ft_get_links(link_tree, node->link_tree, 0) == 0)
		return (NULL);
	return (link_tree);
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

int				ft_get_next_node(t_path *path, t_tree_nod **node, t_data *program_data)
{
	t_tree_nod	*new;
	t_tree_nod	**links;

	if (!(links = ft_get_unvisited_links(*node)))
		return (2);
	if (!links[0] && !links[1])
		return (ft_ret_i_del_links(links, 2));
	if (!(new = ft_best_link(links)))
		return (ft_ret_i_del_links(links, 1));
	if (new != program_data->start)
		new->mark++;
	ft_memdel((void **)&links);
	if (ft_create_path(&path, new))
		return (1);
	*node = new;
	return (0);
}

t_path			**ft_check_paths(t_path **old_paths, t_data *program_data, int num)
{
	t_path	**new_paths;
	t_path	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new_paths = (t_path **)ft_memalloc(sizeof(t_path *) * num + 1)))
		return (NULL);
	while (old_paths[i])
	{
		tmp = old_paths[i];
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->node == program_data->start)
			new_paths[j++] = old_paths[i];
		else
			ft_free_path_helper(old_paths[i], 0);
		i++;
	}
	if (i == j)
	{
		ft_memdel((void **)&new_paths);
		return (old_paths);
	}
	ft_memdel((void **)&old_paths);
	return (new_paths);
}
