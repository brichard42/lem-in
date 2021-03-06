/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:13:11 by brichard          #+#    #+#             */
/*   Updated: 2019/10/07 16:58:57 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree_nod	*ft_search_room(t_tree_nod *room_tree, char *key)
{
	if (room_tree == NULL || ft_strequ(room_tree->room_name, key) == TRUE)
		return (room_tree);
	else if (ft_strcmp(room_tree->room_name, key) < 0)
		return (ft_search_room(room_tree->right, key));
	else if (ft_strcmp(room_tree->room_name, key) > 0)
		return (ft_search_room(room_tree->left, key));
	return (NULL);
}
