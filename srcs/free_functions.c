/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:01:38 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/02 10:04:57 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_free_link(t_link *link)
{
	if (!link)
		return ;
	if (link->right)
		ft_free_link(link->right);
	if (link->left)
		ft_free_link(link->left);
	ft_strdel(&link->name);
	ft_memdel((void **)&link);
}

void		ft_free_tree(t_nod *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		ft_free_tree(tree->left);
	if (tree->right)
		ft_free_tree(tree->right);
	ft_free_link(tree->links);
	ft_strdel(&tree->room);
	ft_memdel((void **)&tree);
}
