/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:35:01 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/09 06:09:05 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static uint8_t	ft_bfs_updater(t_list **checking, t_list **to_check)
{
	*checking = *to_check;
	*to_check = NULL;
	if (*checking == NULL)
		return (0);
	return (1);
}

static uint8_t	ft_ok_link(t_tree_nod *parent, t_tree_nod *child)
{
	if (child->type == START || parent->type == END)
		return (1);
	if (parent->type == START && child->type == END)
	{
		if (child->parent == NULL)
		{
			child->parent = parent;
			return (0);
		}
		else
			return (1);
	}
	return (0);
}

static uint8_t	ft_good_link(t_tree_nod *parent, t_tree_nod *child, int flow)
{
	t_list	*child_mem;

	child_mem = child->mem_data;
	if (ft_ok_link(parent, child) || child->last_visit == flow)
		return (0);
	if (flow == parent->residue)
	{
		if (ft_mem_node_collector(child_mem) == parent)
			child->residue = flow;
		return (1);
	}
	if (ft_mem_node_collector(child_mem) == parent)
	{
		child->residue = flow;
		return (1);
	}
	if (ft_mem_node_collector(parent->mem_data))
	{
		if (parent->type == START && !ft_mem_node_collector(child_mem))
			return (1);
		return (0);
	}
	return (1); //THINGS TO ADD HERE OBVIOUSLY
}

static void		ft_child_updater(t_list **tmpath, t_tree_nod *parent,
				t_tree_nod *child, int flow)
{
	if (child->type == END)
		ft_push_front((void *)parent, tmpath);
	else
	{
		child->last_visit = flow;
		child->parent = parent;
	}
}

void			ft_bfs(t_data *data, t_tree_nod *start, int flow)
{
	t_llist_nod		*links;
	t_list			*to_check;
	t_list			*checking;
	t_tree_nod		*child;
	t_tree_nod		*parent;

	to_check = NULL;
	ft_push_front((void *)start, &to_check);
	while (ft_bfs_updater(&checking, &to_check))
		while (checking)
		{
			parent = (t_tree_nod *)(checking->content);
			links = parent->link_list;
			while (links)
			{
				child = (t_tree_nod *)(links->linked_room);
				if (ft_good_link(parent, child, flow))
				{
					ft_child_updater(&data->tmpath, parent, child, flow);
					ft_push_front((void *)child, &to_check);
				}
				links = links->next;
			}
			ft_del_first(&checking);
		}
}
