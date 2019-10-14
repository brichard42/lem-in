/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:30:13 by brichard          #+#    #+#             */
/*   Updated: 2019/10/14 06:23:51 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree_nod	***ft_free_paths_nodes(t_path **paths, t_tree_nod **nodes, int i)
{
	if (paths)
		ft_free_path(paths, i);
	ft_memdel((void **)&nodes);
	return (NULL);
}

void		ft_free_path_helper(t_path *path, int i)
{
	if (!path)
		return ;
	if (path->next)
		ft_free_path_helper(path->next, 1);
	if (!i)
	{
		ft_memdel((void **)&path->node->room_name);
		ft_memdel((void **)&path->node);
	}
	ft_memdel((void **)&path);
}

void		ft_free_path(t_path **path, int j)
{
	int	i;

	i = -1;
	if (path)
		while (path[++i])
			ft_free_path_helper(path[i], j);
	ft_memdel((void **)&path);
}
