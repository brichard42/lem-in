/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_collector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 07:52:07 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/12 17:12:07 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_tree_nod	*ft_node_with_flow(t_list *mem_list, int flow)
{
	t_list	*current;
	t_mem	*mem;

	current = mem_list;
	while (current)
	{
		mem = (t_mem *)(current->content);
		if (mem->flow <= flow)
			return (mem->node);
		current = current->next;
	}
	return (NULL);
}

static int			ft_get_sub_path(t_tree_nod **path, t_tree_nod *door,
					int flow, int size)
{
	int			i;
	t_tree_nod	*node;

	i = 2;
	node = door;
	path[1] = node;
	while (node && node->type != END)
	{
		node = ft_node_with_flow(node->mem_data, flow);
		if (node->type != END)
			path[i++] = node;
	}
	if (node)
		return (1);
	else
	{
		i = -1;
		while (++i <= size + 1)
			path[i] = NULL;
		return (0);
	}
}

t_tree_nod			***ft_path_collector(t_data *data, t_tree_nod *start)
{
	t_llist_nod	*link;
	t_tree_nod	***paths;
	int			i;
	t_door		*tmp;

	paths = NULL;
	link = start->link_list;
	if (!(paths = (t_tree_nod ***)ft_memalloc(sizeof(t_tree_nod **) *
					(ft_count_links(link, -1) + 2))))
		return (NULL);
	i = 0;
	while (link)
	{
		tmp = ft_door_data_collector(link->linked_room->door_data, data->the_flow);
		if (tmp)
		{
			if (!(paths[i] = (t_tree_nod **)ft_memalloc(sizeof(t_tree_nod *) * (tmp->size + 2))))
				return (NULL);
			paths[i][0] = data->start;
			if (ft_get_sub_path(paths[i], link->linked_room, data->the_flow, tmp->size))
			{
				paths[i][tmp->size] = ft_room_new(data->end->room_name);
				i++;
			}
		}
		link = link->next;
	}
	return (paths);
}
