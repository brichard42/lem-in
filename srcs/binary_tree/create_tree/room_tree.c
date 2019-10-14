/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:51:25 by brichard          #+#    #+#             */
/*   Updated: 2019/10/14 07:11:28 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree_nod	*ft_room_new(char *room_name)
{
	t_tree_nod *new;

	if (!(new = (t_tree_nod *)ft_memalloc(sizeof(t_tree_nod))))
		return (NULL);
	if (!(new->room_name = ft_strdup(room_name)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	return (new);
}

static void	set_start_end(t_state_machine *machine, t_tree_nod *current)
{
	if (machine->special_com.is_end == TRUE)
	{
		machine->program_data.end = current;
		current->type = END;
		machine->special_com.is_end = FALSE;
	}
	else
	{
		machine->program_data.start = current;
		current->type = START;
		machine->special_com.is_start = FALSE;
	}
}

int8_t		ft_room_add(t_state_machine *machine, t_tree_nod **room_tree
															, char *room_name)
{
	if (*room_tree == NULL)
	{
		*room_tree = ft_room_new(room_name);
		if (machine->special_com.is_end == TRUE
				|| machine->special_com.is_start == TRUE)
			set_start_end(machine, *room_tree);
		return (*room_tree == NULL ? FAILURE : SUCCESS);
	}
	else if (ft_strcmp(room_name, (*room_tree)->room_name) < 0)
	{
		if (ft_room_add(machine, &(*room_tree)->left, room_name) == FAILURE)
			return (FAILURE);
	}
	else if (ft_strcmp(room_name, (*room_tree)->room_name) > 0)
	{
		if (ft_room_add(machine, &(*room_tree)->right, room_name) == FAILURE)
			return (FAILURE);
	}
	ft_balance_tree(room_tree, room_name);
	return (SUCCESS);
}
