/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_balance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:58:19 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/19 17:11:48 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_hei(t_nod *tree)
{
	if (tree == NULL)
		return(0);
	return (tree->hei);
}

static void	ft_right_rotate(t_nod **tree)
{
	t_nod	*x;
	t_nod	*y;
	t_nod	*tmp;

	tmp = *tree;
	x = tmp->left;
	y = x->right;
	x->right = tmp;
	tmp->left = y;
	tmp->hei = 1 + (ft_hei(tmp->left) > ft_hei(tmp->right)
			? ft_hei(tmp->left) : ft_hei(tmp->right));
	x->hei = 1 + (ft_hei(x->left) > ft_hei(x->right) ? ft_hei(x->left) : ft_hei(x->right));
	*tree = x;
}

static void	ft_left_rotate(t_nod **tree)
{
	t_nod	*x;
	t_nod	*y;
	t_nod	*tmp;

	tmp = *tree;
	x = tmp->right;
	y = x->left;
	x->left = tmp;
	tmp->right = y;
	tmp->hei = 1 + (ft_hei(tmp->left) > ft_hei(tmp->right)
			? ft_hei(tmp->left) : ft_hei(tmp->right));
	x->hei = 1 + (ft_hei(x->left) > ft_hei(x->right) ? ft_hei(x->left) : ft_hei(x->right));
	*tree = x;
}

void	ft_balance_tree(t_nod **tree, char *room)
{
	int	bal;

	(*tree)->hei = 1 + (ft_hei((*tree)->left) > ft_hei((*tree)->right) ? ft_hei((*tree)->left) : ft_hei((*tree)->right));
	bal = ft_hei((*tree)->left) - ft_hei((*tree)->right);
	if (bal > 1 && ft_strcmp(room, (*tree)->left->room) < 0)
		ft_right_rotate(tree);
	else if (bal < -1 && ft_strcmp(room, (*tree)->right->room) > 0)
		ft_left_rotate(tree);
	else if (bal > 1 && ft_strcmp(room, (*tree)->left->room) > 0)
	{
		ft_left_rotate(&(*tree)->left);
		ft_right_rotate(tree);
	}
	else if (bal < -1 && ft_strcmp(room, (*tree)->right->room) < 0)
	{
		ft_right_rotate(&(*tree)->right);
		ft_left_rotate(tree);
	}
}
