/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 03:55:20 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/26 00:00:57 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_print_path(t_path *path)
{
	if (!path)
		return ;
	if (path->next)
		ft_print_path(path->next);
	ft_putendl(path->node->room);
	return ;
}

void		ft_aff_paths(t_path **the_paths)
{
	int i;

	i = -1;
	while (the_paths[++i])
	{
		ft_putendl("THE PATH");
		ft_print_path(the_paths[i]);
		ft_putendl("C'ETAIT THE PATH");
	}
}

int			ft_create_path(t_path **path, t_nod *new)
{
	if (!*path)
	{
		if (!(*path = (t_path *)ft_memalloc(sizeof(t_path))))
			return (1);
		(*path)->node = new;
		(*path)->size = 1;
	}
	else
	{
		ft_create_path(&(*path)->next, new);
		(*path)->size++;
	}
	return (0);
}

void		ft_hei_to_neg(t_nod *tree)
{
	if (!tree)
		return ;
	tree->hei = -1;
	if (tree->left)
		ft_hei_to_neg(tree->left);
	if (tree->right)
		ft_hei_to_neg(tree->right);
}

int			ft_path_counter(t_path **paths)
{
	int i;

	i = 0;
	while (paths[i])
		i++;
	return (i);
}
