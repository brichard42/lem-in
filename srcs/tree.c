/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:04:30 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/12 15:47:26 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include "../libft/includes/ft_printf.h"

t_tree_nod	*ft_node_new(char *room)
{
	t_tree_nod *new;

	if (!(new = (t_tree_nod *)ft_memalloc(sizeof(t_tree_nod))))
		return (NULL);
	if (!(new->room = ft_strdup(room)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	return (new);
}

int8_t		ft_node_add(t_state_machine *machine, t_tree_nod **room_tree, char *room)
{
	if (*room_tree == NULL)
	{
		*room_tree = ft_node_new(room);
		if (machine->special_com.is_end == TRUE)
		{
			machine->end = *room_tree;
			machine->special_com.is_end = FALSE;
		}
		else if (machine->special_com.is_start == TRUE)
		{
			machine->start = *room_tree;
			machine->special_com.is_start = FALSE;
		}
		return (*room_tree == NULL ? FAILURE : SUCCESS);
	}
	else if (ft_strcmp(room, (*room_tree)->room) < 0)
	{
		if (ft_node_add(machine, &(*room_tree)->left, room) == FAILURE)
			return (FAILURE);
	}
	else if (ft_strcmp(room, (*room_tree)->room) > 0)
	{
		if (ft_node_add(machine, &(*room_tree)->right, room) == FAILURE)
			return (FAILURE);
	}
	ft_balance_tree(room_tree, room);
	return (SUCCESS);
}
