/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:18:41 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/23 16:26:45 by tlandema         ###   ########.fr       */
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
	int		ret;

	ret = ft_get_next_node(path, node, env);
	if (ret == 1)
		return (1);
	if (ret == 2)
		return (2);
	return (0);
}

static int  ft_path_finder(t_path **paths, t_nod **nodes, t_env *env)
{
	int     j;
	int     i;
	int     ret;

	j = 0;
	i = ft_path_counter(paths);
	env->start->u = 0;
	env->end->u = 1;
	while (j < i)
	{
		while (nodes[j]->hei > 0 && paths[j]->size != -2)
		{
			while (paths[j])
			{
				if (nodes[j] != env->start)
				{
					if ((ret = ft_path_helper(paths[j], &nodes[j], env)) == 1)
						return (1);
					if (ret == 2)
						paths[j]->size = -2;
				}
				j++;
			}
			j = 0;
		}
		j++;
	}
	return (0);
}
/*
static void	suppr_lnk(t_link **new, t_link *link, t_nod *to_suppr)
{
	if (!link || !to_suppr)
		return ;
	if (link->l_room && link->l_room != to_suppr)
		ft_link_add(NULL, new, link->l_room->room, link->l_room);
	if (link->left)
		suppr_lnk(new, link->left, to_suppr);
	if (link->right)
		suppr_lnk(new, link->right, to_suppr);
}

static void	remove_lnk(t_path **paths, t_nod *start)
{
	int		i;
	t_path	*tmp;
	t_link	*new;

	i = 0;
	if (!paths)
		return ;
	while (paths[i])
	{
		new = NULL;
		tmp = paths[i]->next;
		while (tmp && tmp->node != start)
		{
			if (tmp->next->node != start)
			{
				suppr_lnk(&new, tmp->node->links, tmp->next->node);
				ft_free_link(tmp->node->links);
				tmp->node->links = new;
				new = NULL;
			}
			tmp = tmp->next;
		}
		i++;
	}
}
*/
static void    ft_tree_to_null(t_nod *tree) // TO DELETE
{
	if (tree->right)
		ft_tree_to_null(tree->right);
	if (tree->left)
		ft_tree_to_null(tree->left);
	tree->u = 0;
}

t_nod			***ft_get_multi_paths(t_env *env)
{
	t_path	**paths;
	t_nod	**nodes;
	t_nod	***tmp;
	int		i;
	int		num_link;

	i = -1;
	num_link = ft_count_links(env->end->links, -1);
	if (!(paths = (t_path **)ft_memalloc(sizeof(t_path *) * (num_link + 1))))
		return (NULL);
	if (!(nodes = (t_nod **)ft_memalloc(sizeof(t_nod *) * (num_link + 1))))
		return (ft_free_paths_nodes(paths, NULL));
	while (++i < num_link)
		if (ft_create_path(&paths[i], ft_node_new(env->end->room)))
			return (ft_free_paths_nodes(paths, nodes));
	if (!(ft_get_the_nods(paths, nodes, env->end->links, 0)))
		return (ft_free_paths_nodes(paths, nodes));
	if (ft_path_finder(paths, nodes, env))
		return (ft_free_paths_nodes(paths, nodes));
	if (!(paths = ft_check_paths(paths, env, num_link)))
		return (ft_free_paths_nodes(paths, nodes));
	if (!(tmp = ft_transform_paths(paths, env)))
		return (ft_free_paths_nodes(paths, nodes));
	//remove_lnk(paths, env->start);
	ft_tree_to_null(env->tree);
	ft_memdel((void **)&nodes);
	ft_free_path(paths, 1);
	return (tmp);
}
