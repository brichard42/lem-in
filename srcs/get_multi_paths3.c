/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_paths3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 08:51:59 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/29 18:18:08 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_transform(t_nod **new_path, t_path *path, int j, int i)
{
	if (path->next)
		j = ft_transform(new_path, path->next, j, i + 1);
	new_path[j] = path->node;
	if (j == 1)
		new_path[j]->hei = i + 1;
	j++;
	return (j);
}

t_nod		***ft_transform_paths(t_path **path)
{
	t_nod	***new_path;
	int		i;
	int		count;

	i = -1;
	if (!(new_path = (t_nod ***)ft_memalloc(sizeof(t_nod **) * (ft_path_counter(path) + 1))))
		return (NULL);
	while (path[++i])
	{
		count = ft_node_in_path(path[i], 1);
		if (!(new_path[i] = (t_nod **)ft_memalloc(sizeof(t_nod *) * (count + 2))))
			return (NULL/*free*/);
		ft_transform(new_path[i], path[i], 0, 1);
	}
	return (new_path);
}
