/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:18:41 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/25 05:48:02 by tlandema         ###   ########.fr       */
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

static int	ft_path_counter(t_path **paths)
{
	int i;

	i = 0;
	while (paths[i])
		i++;
	return (i);
}

static int	ft_get_links(t_nod **tab_link, t_link *link, int i)
{
	if (!link)
		return (0);
	if (!link->l_room->u)
	{
		tab_link[i] = link->l_room;
		i++;
	}
	if (link->left)
		i = ft_get_links(tab_link, link->left, i);
	if (link->right)
		i = ft_get_links(tab_link, link->right, i);
	return (i);
}

static t_nod	**ft_get_unvisited_links(t_nod *node)
{
	int		num_link;
	t_nod	**links;

	num_link = ft_count_links(node->links, -1);
	if (!(links = (t_nod **)ft_memalloc(sizeof(t_nod *) * (num_link + 1))))
		return (NULL);
	ft_get_links(links, node->links, 0);
	return (links);
}

static t_nod	*ft_best_link(t_nod **tab_link)
{
	int i;
	int min_hei;

	i = 1;
	if (!tab_link[0])
		return (NULL);
	min_hei = tab_link[0]->hei;
	while (tab_link[i])
	{
		if (tab_link[i]->hei < min_hei)
			min_hei = tab_link[i]->hei;
		i++;
	}
	i = 0;
	while (tab_link[i])
	{
		if (tab_link[i]->hei == min_hei)
			return (tab_link[i]);
		i++;
	}
	return (NULL);
}

static int	ft_ret_2_del_links(t_nod **links)
{
	ft_memdel((void **)&links);
	return (2);
}

static int	ft_get_next_node(t_path *path, t_nod **node, t_env *env)
{
	t_nod	*new;
	t_nod	**links;

	if (!(links = ft_get_unvisited_links(*node)))
		return (1);
	if (!links[0])
		return (ft_ret_2_del_links(links));
	if (!(new = ft_best_link(links)))
		return (1);
	if (new != env->start)
		new->u++;
	ft_memdel((void **)&links);
	ft_create_path(&path, new);
	*node = new;
	return (0);
}

static int	ft_path_finder(t_path **paths, t_nod **nodes, t_env *env)
{
	int	j;
	int	i;
	int	ret;

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
				{
					ret = ft_get_next_node(paths[j], &nodes[j], env);
					if (ret == 1)
						return (1);
					if (ret == 2)
						nodes[j]->hei = -1;
				}
				j++;
			}
			j = 0;
		}
		j++;
	}
	return (0);
}

int			ft_get_multi_paths(t_env *env)
{
	t_path	**paths;
	t_nod	**nodes;
	int		num_link;

	num_link = ft_count_links(env->end->links, -1);
	if (!(paths = (t_path **)ft_memalloc(sizeof(t_path *) * (num_link + 1))))
		return (1);
	if (!(nodes = (t_nod **)ft_memalloc(sizeof(t_nod *) * (num_link + 1))))
		return (1/*free paths properly*/);
	if (!(ft_get_the_nods(paths, nodes, env->end->links, 0)))
		return (1/*free paths properly*/);
	if (ft_path_finder(paths, nodes, env))
		return (1/*free paths properly*/);
	ft_memdel((void **)&nodes);
	env->paths = paths;
	ft_aff_paths(paths);
	return (0);
}
