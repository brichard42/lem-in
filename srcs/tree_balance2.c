/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_balance2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:15:06 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/21 13:49:58 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_bal_l_l(t_nod **tree)
{
	t_nod	*x;
	t_nod	*y;

	x = (*tree)->left;
	y = x->left;
	x->right = (*tree);
	(*tree)->left = NULL;
	(*tree)->hei = 0;
	x->hei = 1;
	y->hei = 0;
	*tree = x;
}

static void	ft_bal_l_r(t_nod **tree)
{
	t_nod	*x;
	t_nod	*y;

	x = (*tree)->left;
	y = x->right;
	x->left = y;
	x->right = (*tree);
	(*tree)->left = NULL;
	(*tree)->hei = 0;
	x->hei = 1;
	y->hei = 0;
	*tree = x;
}

static void	ft_bal_r_r(t_nod **tree)
{
	t_nod	*x;
	t_nod	*y;

	x = (*tree)->right;
	y = x->right;
	x->left = (*tree);
	(*tree)->right = NULL;
	(*tree)->hei = 0;
	x->hei = 1;
	y->hei = 0;
	*tree = x;
}

static void	ft_bal_r_l(t_nod **tree)
{
	t_nod *x;
	t_nod *y;

	x = (*tree)->right;
	y = x->left;
	x->right = y;
	x->left = (*tree);
	(*tree)->right = NULL;
	(*tree)->hei = 0;
	x->hei = 1;
	y->hei = 0;
	*tree = x;
}

void		ft_small_balance(t_nod **tree, int bal)
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
