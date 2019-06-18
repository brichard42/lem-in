/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:04:30 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/18 15:13:20 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_nod	*ft_node_new(char *room, char s_e)
{
	t_nod *new;

	if (!(new = (t_nod *)ft_memalloc(sizeof(t_nod))))
		return (NULL);
	new->s_e = s_e;
	if (!(new->room = ft_strdup(room)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	return (new);
}

void	ft_print_tree(t_nod *tree)
{
	if (tree->right)
		ft_print_tree(tree->right);
	if (tree->left)
		ft_print_tree(tree->left);
	ft_putendl(tree->room);
}

int		ft_node_add(t_nod **tree, char *room, char s_e)
{
	if (!*tree)
	{
		if (!(*tree = ft_node_new(room, s_e)))
			return (1);
	}
	else if (ft_strcmp(room, (*tree)->room) < 0)
		ft_node_add(&(*tree)->left, room, s_e);
	else
		ft_node_add(&(*tree)->right, room, s_e);
	return (0);
}

void        ft_free_tree(t_nod *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		ft_free_tree(tree->left);
	if (tree->right)
		ft_free_tree(tree->right);
	ft_strdel(&tree->room);
	ft_memdel((void **)&tree);
}
