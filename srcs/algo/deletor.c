/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:49:11 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/24 14:54:11 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_delink(t_ltree_nod **new, t_ltree_nod *link, t_tree_nod *to_del)
{
	if (link->linked_room && link->linked_room != to_del)
		ft_link_add(NULL, new, link->linked_room->room_name, link->linked_room);
	if (link->left)
		ft_delink(new, link->left, to_del);
	if (link->right)
		ft_delink(new, link->right, to_del);
	return (1);
}

static int	ft_smalletor(t_tree_nod **paths, t_data *program_data)
{
	int		i;
	t_ltree_nod	*new;

	new = NULL;
	i = 1;
	while (paths[i])
	{
		if (ft_count_links(paths[i]->link_tree, -1) > 2 && paths[i]
			&& paths[i - 1] && paths[i] != program_data->end && paths[i - 1] != program_data->start)
		{
//			ft_putchar('\n');
//			ft_putstr(paths[i - 1]->room_name);
//			ft_print_links(paths[i]->link_tree);
			ft_delink(&new, paths[i]->link_tree, paths[i - 1]);
//			ft_putchar('\n');
			paths[i]->link_tree = new;
//			ft_print_links(paths[i]->link_tree);
//			ft_putchar('\n');
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_delete_links(t_tree_nod ****pathss, t_data *program_data)
{
	int	i;
	int	j;

	i = 0;
	while (pathss[i])
	{
		j = 0;
		while (pathss[i][j])
		{
			if (ft_smalletor(pathss[i][j], program_data))
				return ;
			j++;
		}
		i++;
	}
}
