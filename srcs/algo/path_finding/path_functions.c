/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:14:02 by brichard          #+#    #+#             */
/*   Updated: 2019/09/25 13:14:00 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_node_in_path(t_path *path, int i)
{
	if (path->next)
		i = ft_node_in_path(path->next, i + 1);
	return (i);
}

int8_t	ft_create_path(t_path **path, t_tree_nod *new)
{
	if (*path == NULL)
	{
		*path = (t_path *)ft_memalloc(sizeof(t_path));
		if (*path == NULL)
			return (FAILURE);
		(*path)->node = new;
		(*path)->size = 1;
	}
	else
	{
		if (ft_create_path(&(*path)->next, new) == FAILURE)
			return (FAILURE);
		(*path)->size++;
	}
	return (SUCCESS);
}

int		ft_path_counter(t_path **paths)
{
	int i;

	i = 0;
	while (paths[i])
		i++;
	return (i);
}
