/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:13:11 by brichard          #+#    #+#             */
/*   Updated: 2019/06/27 10:45:08 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_nod	*ft_search_room(t_nod *tree, char *key)
{
	if (!tree || ft_strequ(tree->room, key))
		return (tree);
	else if (ft_strcmp(tree->room, key) < 0)
		return (ft_search_room(tree->right, key));
	else if (ft_strcmp(tree->room, key) > 0)
		return (ft_search_room(tree->left, key));
	return (NULL);
}

t_link	*ft_search_link(t_link *tree, char *key)
{
	if (!tree || ft_strequ(tree->name, key))
		return (tree);
	else if (ft_strcmp(tree->name, key) < 0)
		return (ft_search_link(tree->right, key));
	else if (ft_strcmp(tree->name, key) > 0)
		return (ft_search_link(tree->left, key));
	return (NULL);
}
