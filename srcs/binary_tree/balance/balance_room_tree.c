/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_balance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:58:19 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/17 13:20:23 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_hei(t_tree_nod *tree)
{
	if (tree == NULL)
		return (0);
	return (tree->height);
}

static void	ft_rotate(t_tree_nod **tree, char r_l)
{
	t_tree_nod	*x;
	t_tree_nod	*y;
	t_tree_nod	*tmp;

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
	tmp->height = 1 + (ft_hei(tmp->left) > ft_hei(tmp->right)
			? ft_hei(tmp->left) : ft_hei(tmp->right));
	x->height = 1 + (ft_hei(x->left) > ft_hei(x->right)
			? ft_hei(x->left) : ft_hei(x->right));
	*tree = x;
}

void		ft_balance_tree(t_tree_nod **tree, char *room_name)
{
	int	bal;

	(*tree)->height = 1 + (ft_hei((*tree)->left) > ft_hei((*tree)->right)
			? ft_hei((*tree)->left) : ft_hei((*tree)->right));
	bal = ft_hei((*tree)->left) - ft_hei((*tree)->right);
	if ((bal == 1 && (*tree)->right == NULL)
			|| (bal == -1 && ((*tree)->left == NULL)))
		ft_small_balance(tree, bal);
	else if (bal > 1 && ft_strcmp(room_name, (*tree)->left->room_name) < 0)
		ft_rotate(tree, RIGHT);
	else if (bal < -1 && ft_strcmp(room_name, (*tree)->right->room_name) > 0)
		ft_rotate(tree, LEFT);
	else if (bal > 1 && ft_strcmp(room_name, (*tree)->left->room_name) > 0)
	{
		ft_rotate(&(*tree)->left, LEFT);
		ft_rotate(tree, RIGHT);
	}
	else if (bal < -1 && ft_strcmp(room_name, (*tree)->right->room_name) < 0)
	{
		ft_rotate(&(*tree)->right, RIGHT);
		ft_rotate(tree, LEFT);
	}
}
