/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:12:57 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/03 15:46:54 by tlandema         ###   ########.fr       */
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

int		ft_calc_dist(t_env *env, t_nod *start, t_nod *parent, int dist)
{
	if (start->hei != 0)
		return (1);
	start->hei = dist;
	if (!start || start == env->end)
		return (1);
	if (!start->links)
		return (1/*si il n'y a pas de link dans la sale elle est useless donc delete
				   si il s'avere que c'est start qu'est link a rien on peut arreter le
				   traitement de données*/);
	if (start->links && parent != start->links->l_room)
		ft_calc_dist(env, start->links->l_room, start, dist + 1);
	if (start->links->left && parent != start->links->left->l_room)
		ft_calc_dist(env, start->links->left->l_room, start, dist + 1);
	if (start->links->right && parent != start->links->right->l_room)
		ft_calc_dist(env, start->links->right->l_room, start, dist + 1);
	return (0);
}
