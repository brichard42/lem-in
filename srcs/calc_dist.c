/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:12:57 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/04 17:20:47 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_hei_to_null(t_nod *tree)
{
	if (!tree)
		return ;
	tree->hei = 0;
	if (tree->left)
		ft_hei_to_null(tree->left);
	if (tree->right)
		ft_hei_to_null(tree->right);
}

int		ft_calc_dist(t_env *env)
{
	t_nod	**current;

	if (!(current = (t_nod **)ft_memalloc(sizeof(t_nod *) * 2)))
		return (1);
	current[0] = env->start;
	ft_putendl(current[0]->room);
	return (0);
}
