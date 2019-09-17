/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:01:38 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/31 09:27:57 by tlandema         ###   ########.fr       */
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

static void	ft_free_path_helper(t_path *path, int i)
{
	if (!path)
		return ;
	if (path->next)
		ft_free_path_helper(path->next, 1);
	if (!i)
	{
		ft_memdel((void **)&path->node->room);
		ft_memdel((void **)&path->node);
	}
	ft_memdel((void **)&path);
}

void		ft_free_path(t_path **path, int j)
{
	int	i;

	i = -1;
	if (path)
		while (path[++i])
			ft_free_path_helper(path[i], j);
	ft_memdel((void **)&path);
}
