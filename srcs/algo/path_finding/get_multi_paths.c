/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:18:41 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/14 07:19:06 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_get_the_nods(t_path **paths, t_tree_nod **nodes,
			t_llist_nod *link, int i)
{
	t_tree_nod	*current_room;
	t_llist_nod	*next;

	next = link->next;
	current_room = link->linked_room;
	if (link)
	{
		current_room->last_visit = 1;
		if (ft_create_path(&paths[i], current_room) == FAILURE)
			return (0);
		nodes[i] = current_room;
		i++;
	}
	if (next)
		if (!(i = ft_get_the_nods(paths, nodes, next, i)))
			return (0);
	return (i);
}

static int		ft_path_helper(t_path *path, t_tree_nod **node,
			t_data *program_data)
{
	int		ret;

	ret = ft_get_next_node(path, node, program_data);
	if (ret == 1)
		return (1);
	if (ret == 2)
	{
		path->size = -2;
		return (2);
	}
	return (0);
}

static int		ft_path_finder(t_path **paths, t_tree_nod **nodes,
			t_data *program_data)
{
	int	j;
	int	i;

	j = 0;
	i = ft_path_counter(paths);
	program_data->start->last_visit = 0;
	program_data->end->last_visit = 1;
	while (j < i)
	{
		while (nodes[j]->height > 0 && paths[j]->size != -2)
		{
			while (paths[j])
			{
				if (nodes[j] != program_data->start)
				{
					if (ft_path_helper(paths[j], &nodes[j], program_data) == 1)
						return (1);
				}
				j++;
			}
			j = 0;
		}
		j++;
	}
	return (0);
}

t_tree_nod		***ft_get_multi_paths(t_data *program_data, int i)
{
	t_path		**paths;
	t_tree_nod	**nodes;
	t_tree_nod	***tmp;
	int			n_link;

	n_link = ft_count_links(program_data->end->link_list, -1);
	if (!(paths = (t_path **)ft_memalloc(sizeof(t_path *) * (n_link + 1))))
		return (NULL);
	if (!(nodes = (t_tree_nod **)ft_memalloc(sizeof(t_tree_nod *) *
			(n_link + 1))))
		return (ft_free_paths_nodes(paths, NULL, 0));
	while (++i < n_link)
		if (ft_create_path(&paths[i],
				ft_room_new(program_data->end->room_name)) == FAILURE)
			return (ft_free_paths_nodes(paths, nodes, 0));
	if (!(ft_get_the_nods(paths, nodes, program_data->end->link_list, 0)))
		return (ft_free_paths_nodes(paths, nodes, 0));
	if (ft_path_finder(paths, nodes, program_data))
		return (ft_free_paths_nodes(paths, nodes, 0));
	if (!(paths = ft_check_paths(paths, program_data, n_link, 0)))
		return (ft_free_paths_nodes(paths, nodes, 0));
	if (!(tmp = ft_transform_paths(paths, program_data)))
		return (ft_free_paths_nodes(paths, nodes, 0));
	ft_free_paths_nodes(paths, nodes, 1);
	return (tmp);
}
