/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_balance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:58:19 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/22 16:05:39 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_hei(t_nod *tree)
{
	if (tree == NULL)
		return (0);
	return (tree->hei);
}

static void	ft_rotate(t_nod **tree, char r_l)
{
	t_nod	*x;
	t_nod	*y;
	t_nod	*tmp;

	if (r_l == 'l')
	{
		tmp = *tree;
		x = tmp->right;
		y = x->left;
		x->left = tmp;
		tmp->right = y;
	}
	else
	{
		tmp = *tree;
		x = tmp->left;
		y = x->right;
		x->right = tmp;
		tmp->left = y;	
	}
	tmp->hei = 1 + (ft_hei(tmp->left) > ft_hei(tmp->right)
			? ft_hei(tmp->left) : ft_hei(tmp->right));
	x->hei = 1 + (ft_hei(x->left) > ft_hei(x->right) ? ft_hei(x->left) : ft_hei(x->right));
	*tree = x;
}

void		ft_balance_tree(t_nod **tree, char *room)
{
	int	bal;

	(*tree)->hei = 1 + (ft_hei((*tree)->left) > ft_hei((*tree)->right) ? ft_hei((*tree)->left) : ft_hei((*tree)->right));
	bal = ft_hei((*tree)->left) - ft_hei((*tree)->right);
	if ((bal == 1 && (*tree)->right == NULL) || (bal == -1 && ((*tree)->left == NULL)))
		ft_small_balance(tree, bal);
	else if (bal > 1 && ft_strcmp(room, (*tree)->left->room) < 0)
		ft_rotate(tree, RIGHT);
	else if (bal < -1 && ft_strcmp(room, (*tree)->right->room) > 0)
		ft_rotate(tree, LEFT);
	else if (bal > 1 && ft_strcmp(room, (*tree)->left->room) > 0)
	{
		ft_rotate(&(*tree)->left, LEFT);
		ft_rotate(tree, RIGHT);
	}
	else if (bal < -1 && ft_strcmp(room, (*tree)->right->room) < 0)
	{
		ft_rotate(&(*tree)->right, RIGHT);
		ft_rotate(tree, LEFT);
	}
}
