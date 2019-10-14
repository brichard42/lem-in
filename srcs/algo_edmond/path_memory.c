/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:40:48 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/14 05:42:44 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree_nod	*ft_mem_node_collector(t_list *memory)
{
	if (memory)
		return (((t_mem *)(memory->content))->node);
	return (NULL);
}

int8_t		ft_add_node_memory(t_list *tmpath, int flow)
{
	t_tree_nod	*current;
	t_tree_nod	*next;
	t_mem		*mem;

	while (tmpath && tmpath->next)
	{
		current = (t_tree_nod *)(tmpath->content);
		next = (t_tree_nod *)(tmpath->next->content);
		if (!(mem = (t_mem *)ft_memalloc(sizeof(t_mem))))
			return (FAILURE);
		mem->flow = flow;
		if (next->mem_data
				&& ((t_mem *)(next->mem_data->content))->node == current)
		{
			mem->node = NULL;
			ft_push_front((void *)mem, &(next->mem_data));
		}
		else
		{
			mem->node = next;
			ft_push_front((void *)mem, &(current->mem_data));
		}
		tmpath = tmpath->next;
	}
	return (SUCCESS);
}
