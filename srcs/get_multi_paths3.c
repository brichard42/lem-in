/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_paths3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 08:51:59 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/30 16:56:18 by tlandema         ###   ########.fr       */
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

t_nod		***ft_transform_paths(t_path **path, t_env *env)
{
	t_nod	***n_path;
	int		i;
	int		count;

	i = -1;
	count = ft_path_counter(path);
	if (!(n_path = (t_nod ***)ft_memalloc(sizeof(t_nod **) * (count + 1))))
		return (NULL);
	while (path[++i])
	{
		count = ft_node_in_path(path[i], 1);
		if (!(n_path[i] = (t_nod **)ft_memalloc(sizeof(t_nod *) * (count + 2))))
			return (NULL/*free*/);
		ft_transform(n_path[i], path[i], 0, 1);
		n_path[i][count + 1] = env->end;
	}
	return (n_path);
}
