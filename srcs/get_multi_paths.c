/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:18:41 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/29 16:06:12 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_get_the_nods(t_path **paths, t_nod **nodes, t_link *link, int i)
{
	t_nod	*current_room;
	t_link	*left;
	t_link	*right;

	right = link->right;
	left = link->left;
	current_room = link->l_room;
	if (link)
	{
		current_room->u = 1;
		if (ft_create_path(&paths[i], current_room))
			return (0);
		nodes[i] = current_room;
		i++;
	}
	if (left)
		if (!(i = ft_get_the_nods(paths, nodes, left, i)))
			return (0);
	if (right)
		if (!(i = ft_get_the_nods(paths, nodes, right, i)))
			return (0);
	return (i);
}

static int	ft_path_helper(t_path *path, t_nod **node, t_env *env)
{
	int ret;

	ret = ft_get_next_node(path, node, env);
	if (ret == 1)
		return (1);
	if (ret == 2)
		(*node)->hei = -1;
	return (0);
}

static int	ft_path_finder(t_path **paths, t_nod **nodes, t_env *env)
{
	int	j;
	int	i;

	j = 0;
	i = ft_path_counter(paths);
	env->end->u = 1;
	while (j < i)
	{
		while (nodes[j]->hei > 0)
		{
			while (paths[j])
			{
				if (nodes[j] != env->start)
					if (ft_path_helper(paths[j], &nodes[j], env) == 1)
						return (1);
				j++;
			}
			j = 0;
		}
		j++;
	}
	return (0);
}

static int	ft_ret_1_free(t_path **paths)
{
	ft_memdel((void **)&paths);
	return (1);
}

int			ft_get_multi_paths(t_env *env)
{
	t_path	**paths;
	t_nod	**nodes;
	int		i;
	int		num_link;

	i = 0;
	num_link = ft_count_links(env->end->links, -1);
	if (!(paths = (t_path **)ft_memalloc(sizeof(t_path *) * (num_link + 1))))
		return (1);
	if (!(nodes = (t_nod **)ft_memalloc(sizeof(t_nod *) * (num_link + 1))))
		return (ft_ret_1_free(paths));
	if (!(ft_get_the_nods(paths, nodes, env->end->links, 0)))
		return (ft_free_paths_nodes(paths, nodes));
	env->start->u = 0;
	if (ft_path_finder(paths, nodes, env))
		return (ft_free_paths_nodes(paths, nodes));
	if (!(paths = ft_check_paths(paths, env, num_link)))
		return (ft_free_paths_nodes(paths, nodes));
	if (!(env->paths = ft_transform_paths(paths)))
		return (ft_free_paths_nodes(paths, nodes));
	ft_memdel((void **)&nodes);
	ft_free_path(paths);
	return (0);
}
