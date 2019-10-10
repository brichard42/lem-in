/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:49:11 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/10 08:56:30 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_delink(t_llist_nod **new, t_llist_nod *link, t_tree_nod *to_del)
{
	if (!link)
		return (0);
	if (link->linked_room && link->linked_room != to_del)
		ft_link_add(new, link->linked_room);
	if (link->next)
		ft_delink(new, link->next, to_del);
	return (1);
}

static int	ft_smalletor(t_tree_nod **paths, t_data *program_data)
{
	int		i;
	t_llist_nod	*new;

	new = NULL;
	i = 1;
	while (paths[i])
	{
		if (ft_count_links(paths[i]->link_list, -1) > 2 && paths[i]
			&& paths[i - 1] && paths[i] != program_data->end && paths[i - 1] != program_data->start)
		{
			ft_delink(&new, paths[i]->link_list, paths[i - 1]);
			paths[i]->link_list = new;
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
