/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:18:41 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/25 12:30:19 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_get_the_nods(t_path **paths, t_tree_nod **nodes, t_ltree_nod *link, int i)
{
	t_tree_nod	*current_room;
	t_ltree_nod	*left;
	t_ltree_nod	*right;

	right = link->right;
	left = link->left;
	current_room = link->linked_room;
	if (link)
	{
		current_room->mark = 1;
		if (ft_create_path(&paths[i], current_room) == FAILURE)
			return (0);
		nodes[i] = current_room;
		i++;
	}
	if (left)
		if (!(i = ft_get_the_nods(paths, nodes, left, i)))
			return (0);
	if (right)
		if (!(i = ft_get_the_nods(paths, nodes, right, i)))
			return (0);
	return (i);
}

static int	ft_path_helper(t_path *path, t_tree_nod **node, t_data *program_data)
{
	int		ret;

	ret = ft_get_next_node(path, node, program_data);
	if (ret == 1)
		return (1);
	if (ret == 2)
		return (2);
	return (0);
}

static int  ft_path_finder(t_path **paths, t_tree_nod **nodes, t_data *program_data)
{
	int     j;
	int     i;
	int     ret;

	j = 0;
	i = ft_path_counter(paths);
	program_data->start->mark = 0;
	program_data->end->mark = 1;
	while (j < i)
	{
		while (nodes[j]->height > 0 && paths[j]->size != -2)
		{
			while (paths[j])
			{
				if (nodes[j] != program_data->start)
				{
					if ((ret = ft_path_helper(paths[j], &nodes[j], program_data)) == 1)
						return (1);
					if (ret == 2)
						paths[j]->size = -2;
				}
				j++;
			}
			j = 0;
		}
		j++;
	}
	return (0);
}

static void    ft_tree_to_null(t_tree_nod *tree) // TO DELETE
{
	if (tree->right)
		ft_tree_to_null(tree->right);
	if (tree->left)
		ft_tree_to_null(tree->left);
	tree->mark = 0;
}

t_tree_nod			***ft_get_multi_paths(t_data *program_data)
{
	t_path	**paths;
	t_tree_nod	**nodes;
	t_tree_nod	***tmp;
	int		i;
	int		num_link;

	i = -1;
	num_link = ft_count_links(program_data->end->link_tree, -1);
	if (!(paths = (t_path **)ft_memalloc(sizeof(t_path *) * (num_link + 1))))
		return (NULL);
	if (!(nodes = (t_tree_nod **)ft_memalloc(sizeof(t_tree_nod *) * (num_link + 1))))
		return (ft_free_paths_nodes(paths, NULL));
	while (++i < num_link)
		if (ft_create_path(&paths[i], ft_room_new(program_data->end->room_name)) == FAILURE)
			return (ft_free_paths_nodes(paths, nodes));
	if (!(ft_get_the_nods(paths, nodes, program_data->end->link_tree, 0)))
		return (ft_free_paths_nodes(paths, nodes));
	if (ft_path_finder(paths, nodes, program_data))
		return (ft_free_paths_nodes(paths, nodes));
	if (!(paths = ft_check_paths(paths, program_data, num_link)))
		return (ft_free_paths_nodes(paths, nodes));
	if (!(tmp = ft_transform_paths(paths, program_data)))
		return (ft_free_paths_nodes(paths, nodes));
	ft_tree_to_null(program_data->room_tree);
	ft_memdel((void **)&nodes);
	ft_free_path(paths, 1);
	return (tmp);
}
