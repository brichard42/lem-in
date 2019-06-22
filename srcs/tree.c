/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:04:30 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/22 15:41:09 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_nod	*ft_node_new(char *room)
{
	t_nod *new;

	if (!(new = (t_nod *)ft_memalloc(sizeof(t_nod))))
		return (NULL);
	if (!(new->room = ft_strdup(room)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	return (new);
}

#include <stdio.h>
void	ft_print_tree(t_nod *tree) // TO DELETE	
{
	if (tree->right)
		ft_print_tree(tree->right);
	if (tree->left)
		ft_print_tree(tree->left);
	printf("%s\t|\t\t%d\t\n", tree->room, tree->hei);
}

int		ft_node_add(t_env *env, t_nod **tree, char *room, char s_e)
{
	if (!*tree)
	{
		if (!(*tree = ft_node_new(room)))
			return (1);
		if (s_e == 'e')
			env->end = *tree;
		else if (s_e == 's')
			env->start = *tree;
		return (0);
	}
	else if (ft_strcmp(room, (*tree)->room) < 0)
		ft_node_add(env, &(*tree)->left, room, s_e); //manque protection !
	else if (ft_strcmp(room, (*tree)->room) > 0)
		ft_node_add(env, &(*tree)->right, room, s_e); //manque protection !
	ft_balance_tree(tree, room);
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
