/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 00:54:05 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/14 05:47:09 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_size_collector(t_tree_nod *path)
{
	t_tree_nod	*node;
	int			count;

	node = path;
	count = 0;
	while (++count && node->mem_data)
		node = ((t_mem *)(node->mem_data->content))->node;
	return (count);
}

t_door		*ft_door_data_collector(t_list *data, int flow)
{
	t_list	*tmp;
	t_door	*current;

	tmp = data;
	while (tmp)
	{
		current = (t_door *)(tmp->content);
		if (current->flow == flow)
			return (current);
		tmp = tmp->next;
	}
	return (NULL);
}

int8_t		ft_add_doors(t_tree_nod *start, int flow)
{
	t_list			*start_mem;
	t_tree_nod		*door;
	t_door			*info;

	start_mem = start->mem_data;
	while (start_mem)
	{
		door = ((t_mem *)(start_mem->content))->node;
		if (!(info = (t_door *)ft_memalloc(sizeof(t_door))))
			return (FAILURE);
		info->flow = flow;
		info->size = ft_size_collector(door);
		ft_push_front((void *)info, &(door->door_data));
		start_mem = start_mem->next;
	}
	return (SUCCESS);
}
