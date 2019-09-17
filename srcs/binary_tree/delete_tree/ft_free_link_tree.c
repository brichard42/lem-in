/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_link_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:45:43 by brichard          #+#    #+#             */
/*   Updated: 2019/09/17 18:45:54 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_link_tree(t_ltree_nod *link_tree)
{
	if (link_tree != NULL)
	{
		if (link_tree->right)
			ft_free_link_tree(link_tree->right);
		if (link_tree->left)
			ft_free_link_tree(link_tree->left);
		ft_strdel(&link_tree->link_name);
		ft_memdel((void **)&link_tree);
	}
}
