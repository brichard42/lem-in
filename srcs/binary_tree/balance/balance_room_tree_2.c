/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_balance2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:15:06 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/12 15:52:20 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_bal_l_l(t_tree_nod **tree)
{
	t_tree_nod	*x;
	t_tree_nod	*y;

	x = (*tree)->left;
	y = x->left;
	x->right = (*tree);
	(*tree)->left = NULL;
	(*tree)->height = 0;
	x->height = 1;
	y->height = 0;
	*tree = x;
}

static void	ft_bal_l_r(t_tree_nod **tree)
{
	t_tree_nod	*x;
	t_tree_nod	*y;

	x = (*tree)->left;
	y = x->right;
	y->left = x;
	y->right = (*tree);
	(*tree)->left = NULL;
	x->right = NULL;
	(*tree)->height = 0;
	x->height = 0;
	y->height = 1;
	*tree = y;
}

static void	ft_bal_r_r(t_tree_nod **tree)
{
	t_tree_nod	*x;
	t_tree_nod	*y;

	x = (*tree)->right;
	y = x->right;
	x->left = (*tree);
	(*tree)->right = NULL;
	(*tree)->height = 0;
	x->height = 1;
	y->height = 0;
	*tree = x;
}

static void	ft_bal_r_l(t_tree_nod **tree)
{
	t_tree_nod *x;
	t_tree_nod *y;

	x = (*tree)->right;
	y = x->left;
	y->right = x;
	y->left = (*tree);
	(*tree)->right = NULL;
	x->left = NULL;
	(*tree)->height = 0;
	x->height = 0;
	y->height = 1;
	*tree = y;
}

void		ft_small_balance(t_tree_nod **tree, int bal)
{
	if (bal == 1)
	{
		if ((*tree)->left->left)
			ft_bal_l_l(tree);
		else if ((*tree)->left->right)
			ft_bal_l_r(tree);
	}
	else
	{
		if ((*tree)->right->right)
			ft_bal_r_r(tree);
		else if ((*tree)->right->left)
			ft_bal_r_l(tree);
	}
}
