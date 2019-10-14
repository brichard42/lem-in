/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:33:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/14 05:51:25 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_path_size(t_tree_nod *start)
{
	t_tree_nod	*node;
	int			value;

	value = 1;
	node = start;
	while (node && node->parent)
	{
		value += ft_mem_node_collector(node->mem_data) == node->parent ? -1 : 1;
		node = node->parent;
	}
	return (value);
}

static void		ft_path_transformer(t_data *data, t_tree_nod *path)
{
	t_tree_nod	*node;
	t_list		**tmpath_address;

	if (!path)
		return ;
	ft_del_list(&(data->tmpath));
	tmpath_address = &(data->tmpath);
	node = path;
	ft_push_front((void *)(data->end), tmpath_address);
	while (node)
	{
		ft_push_front((void *)node, tmpath_address);
		node = node->parent;
	}
}

static int8_t	ft_best_path(t_data *data, t_list *paths)
{
	int			size_min;
	int			size;
	t_tree_nod	*node;
	t_tree_nod	*the_path;

	size_min = 0;
	the_path = NULL;
	if (data->flow == 1 && !paths)
		return (FAILURE);
	while (paths)
	{
		node = (t_tree_nod *)(paths->content);
		size = ft_path_size(node);
		if (!size_min || size < size_min)
		{
			size_min = size;
			the_path = node;
		}
		paths = paths->next;
	}
	ft_path_transformer(data, the_path);
	return (SUCCESS);
}

int8_t			ft_algorithm(t_data *data)
{
	while (data->tmpath || data->flow == 0)
	{
		data->flow++;
		ft_del_list(&data->tmpath);
		data->start->last_visit = data->flow;
		ft_bfs(data, data->start, data->flow);
		if (ft_best_path(data, data->tmpath) == FAILURE)
			return (FAILURE);
		if ((ft_add_node_memory(data->tmpath, data->flow) == FAILURE))
			return (FAILURE);
		if ((ft_add_doors(data->start, data->flow) == FAILURE))
			return (FAILURE);
		ft_simulator(data, data->start, data->flow, data->ant_nb);
	}
	return (SUCCESS);
}
