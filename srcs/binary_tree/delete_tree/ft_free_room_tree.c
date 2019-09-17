/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_room_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:46:31 by brichard          #+#    #+#             */
/*   Updated: 2019/09/17 18:46:33 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_free_room_tree(t_tree_nod *room_tree)
{
	if (room_tree != NULL)
	{
		if (room_tree->left)
			ft_free_room_tree(room_tree->left);
		if (room_tree->right)
			ft_free_room_tree(room_tree->right);
		ft_free_link_tree(room_tree->link_tree);
		ft_strdel(&room_tree->room_name);
		ft_memdel((void **)&room_tree);
	}
}
