/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 03:55:20 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/20 10:17:33 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_print_path(t_path **path, int i) /* TO_REMOVE */
{
	(void)i;
	while (path[i])
		ft_putendl(path[i++]->name);
}

void		ft_aff_paths(t_path ***the_paths) /* TO REMOVE */
{
	int i;

	i = -1;
	while (the_paths[++i])
	{
		ft_putendl("THE PATH");
		ft_print_path(the_paths[i], 0);
		ft_putendl("C'ETAIT THE PATH");
	}
}

void	ft_hei_to_neg(t_nod *tree)
{
	if (!tree)
		return ;
	tree->hei = -1;
	if (tree->left)
		ft_hei_to_neg(tree->left);
	if (tree->right)
		ft_hei_to_neg(tree->right);
}
