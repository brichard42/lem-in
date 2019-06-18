/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:58:19 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/18 17:21:51 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_right_rotate(t_nod **tree)
{
	t_nod	*x;
	t_nod	*y;
	t_nod	*tmp;

	tmp = *tree;
	x = tmp->left;
	y = x->right;
	x->right = tmp;
	tmp->left = y;
	tmp->hei = 1 + (tmp->left->hei > tmp->right->hei
			? tmp->left->hei : tmp->right->hei);
	x->hei = 1 + (x->left->hei > x->right->hei ? x->left->hei : x->right->hei);
}

void	ft_left_rotate(t_nod **tree)
{
	t_nod	*x;
	t_nod	*y;
	t_nod	*tmp;

	tmp = *tree;
	x = tmp->right;
	y = x->left;
	x->left = tmp;
	tmp->right = y;
	tmp->hei = 1 + (tmp->left->hei > tmp->right->hei
			? tmp->left->hei : tmp->right->hei);
	x->hei = 1 + (x->left->hei > x->right->hei ? x->left->hei : x->right->hei);
}
