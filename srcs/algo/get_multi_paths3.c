/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_paths3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 08:51:59 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/24 14:54:11 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_transform(t_tree_nod **new_path, t_path *path, int j, int i)
{
	if (path->next)
		j = ft_transform(new_path, path->next, j, i + 1);
	new_path[j] = path->node;
	if (j == 1)
		new_path[j]->height = i + 1;
	j++;
	return (j);
}

static t_tree_nod	***free_ret_nod(t_tree_nod ***n_path)
{
	ft_free_transformed_path(n_path);
	return (NULL);
}

t_tree_nod			***ft_transform_paths(t_path **path, t_data *program_data)
{
	t_tree_nod	***n_path;
	int		i;
	int		count;

	i = -1;
	count = ft_path_counter(path);
	if (!(n_path = (t_tree_nod ***)ft_memalloc(sizeof(t_tree_nod **) * (count + 1))))
		return (NULL);
	while (path[++i])
	{
		count = ft_node_in_path(path[i], 1);
		if (!(n_path[i] = (t_tree_nod **)ft_memalloc(sizeof(t_tree_nod *) * (count + 2))))
			return (free_ret_nod(n_path));
		ft_transform(n_path[i], path[i], 0, 1);
		n_path[i][count + 1] = program_data->end;
	}
	return (n_path);
}
