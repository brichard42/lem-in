/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:01:38 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/24 23:55:17 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_nod		**ft_free_ret_nod(t_nod **to_f)
{
	ft_memdel((void **)&to_f);
	return (NULL);
}

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
