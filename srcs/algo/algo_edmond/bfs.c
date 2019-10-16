/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:35:01 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/16 14:30:45 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static uint8_t	ft_bfs_updater(t_list **checking, t_list **to_check)
{
	*checking = *to_check;
	*to_check = NULL;
	if (*checking == NULL)
		return (FALSE);
	return (TRUE);
}

static uint8_t	ft_ok_link(t_tree_nod *parent, t_tree_nod *child)
{
	if (child->type == START || parent->type == END)
		return (TRUE);
	if (parent->type == START && child->type == END)
	{
		if (child->parent == NULL)
		{
			child->parent = parent;
			return (FALSE);
		}
		else
			return (TRUE);
	}
	return (FALSE);
}

static uint8_t	ft_good_link(t_tree_nod *parent, t_tree_nod *child, int flow)
{
	t_list	*child_mem;

	child_mem = child->mem_data;
	if (ft_ok_link(parent, child) || child->last_visit == flow)
		return (FALSE);
	if (flow == parent->residue)
	{
		if (ft_mem_node_collector(child_mem) == parent)
			child->residue = flow;
		return (TRUE);
	}
	if (ft_mem_node_collector(child_mem) == parent)
	{
		child->residue = flow;
		return (TRUE);
	}
	if (ft_mem_node_collector(parent->mem_data))
	{
		if (parent->type == START && !ft_mem_node_collector(child_mem))
			return (TRUE);
		return (FALSE);
	}
	return (TRUE);
}

static int8_t	ft_child_updater(t_list **tmpath, t_tree_nod *parent,
				t_tree_nod *child, int flow)
{
	if (child->type == END)
	{
		if (ft_push_front((void *)parent, tmpath) == FAILURE)
			return (FAILURE);
	}
	else
	{
		child->last_visit = flow;
		child->parent = parent;
	}
	return (SUCCESS);
}

int8_t			ft_bfs(t_data *data, t_tree_nod *start, int flow)
{
	t_bfs		bfs;

	ft_bzero((void *)&bfs, sizeof(t_bfs));
	if (ft_push_front((void *)start, &bfs.to_check) == FAILURE)
		return (FAILURE);
	while (ft_bfs_updater(&bfs.checking, &bfs.to_check))
		while (bfs.checking)
		{
			bfs.parent = (t_tree_nod *)(bfs.checking->content);
			bfs.links = bfs.parent->link_list;
			while (bfs.links)
			{
				bfs.child = (t_tree_nod *)(bfs.links->linked_room);
				if (ft_good_link(bfs.parent, bfs.child, flow) == TRUE)
				{
					if (ft_child_updater(&data->tmpath, bfs.parent, bfs.child,
					flow) == FAILURE || ft_push_front((void *)bfs.child,
					&bfs.to_check) == FAILURE)
						return (FAILURE);
				}
				bfs.links = bfs.links->next;
			}
			ft_del_first(&bfs.checking);
		}
	return (SUCCESS);
}
