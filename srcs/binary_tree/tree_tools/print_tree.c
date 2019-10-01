/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:42:25 by brichard          #+#    #+#             */
/*   Updated: 2019/10/01 11:35:22 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_link_list(t_llist_nod *link_list)
{
	if (link_list != NULL)
	{
		if (link_list->next)
			ft_print_link_list(link_list->next);
		ft_printf("[%s]\n", link_list->linked_room->room_name);
	}
}

void	ft_print_room_tree(t_tree_nod *room_tree)
{
	if (room_tree->right)
		ft_print_room_tree(room_tree->right);
	if (room_tree->left)
		ft_print_room_tree(room_tree->left);
	ft_printf("|\t%-30s\t|\tHeight in Tree: %d\t|\n", room_tree->room_name, room_tree->height);
	ft_print_link_list(room_tree->link_list);
}
