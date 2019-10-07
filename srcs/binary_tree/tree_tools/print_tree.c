/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:42:25 by brichard          #+#    #+#             */
/*   Updated: 2019/10/07 16:58:41 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_room_tree(t_tree_nod *room_tree)
{
	if (room_tree->right)
		ft_print_room_tree(room_tree->right);
	if (room_tree->left)
		ft_print_room_tree(room_tree->left);
	ft_printf("|\t%-30s\t|\tHeight in Tree: %d\t|\n", room_tree->room_name, room_tree->height);
	ft_print_link_list(room_tree->link_list);
}
