/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:04:35 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/21 13:52:45 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_nod	*ft_search_node(t_nod *tree, char *key)
{
	if (!tree || ft_strequ(tree->room, key))
		return (tree);
	else if (ft_strcmp(tree->room, key) < 0)
		return (ft_search_node(tree->right, key));
	else if (ft_strcmp(tree->room, key) > 0)
		return (ft_search_node(tree->left, key));
	return (NULL);
}
