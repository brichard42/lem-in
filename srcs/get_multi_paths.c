/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:50:59 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/20 15:45:18 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path	**ft_create_tab_path(t_nod *tmp)
{
	t_path	**new_tab;

	if (!(new_tab = (t_path **)ft_memalloc(sizeof(t_path *) * (tmp->hei + 2))))
		return (NULL);
	if (!(new_tab[tmp->hei] = ft_create_path(tmp)))
		return (NULL);
	return (new_tab);
}

static int ft_get_the_nods(t_path ***the_path, t_nod **the_nods, t_link *link, int i)
{
	t_nod	*current_room;
	t_link	*left;
	t_link	*right;

	right = link->right;
	left = link->left;
	current_room = link->l_room;
	if (link)
	{
		the_path[i] = ft_create_tab_path(current_room);
		the_nods[i++] = current_room;
	}
	if (left)
		i = ft_get_the_nods(the_path, the_nods, left, i);
	if (right)
		i = ft_get_the_nods(the_path, the_nods, right, i);
	return (i);
}

static t_nod    *ft_find_path(t_link *link, int dist, t_nod *end, t_nod *start)
{
	t_nod *save;

	save = NULL;
	if (link->l_room->hei == dist - 1 && link->l_room != end)
	{
		if (!link->l_room->u && link->l_room != start)
			link->l_room->u = 1;
		return (link->l_room);
	}
	if (link->left)
		if ((save = ft_find_path(link->left, dist, end, start))!= NULL)
			return (save);
	if (link->right)
		if ((save = ft_find_path(link->right, dist, end, start)) != NULL)
			return (save);
	return (NULL);
}

static int      ft_path_finder(t_path **the_path, t_nod *node, t_nod *end, t_nod *start)
{
	t_nod   *new_nod;
	t_path  *new_path;

	if (node->hei == 0)
		return (0);
	if (!(new_nod = ft_find_path(node->links, node->hei, end, start)))
		return (1);
	if (!(new_path = ft_create_path(new_nod)))
		return (1);
	the_path[new_nod->hei] = new_path;
	if (ft_path_finder(the_path, new_nod, end, start))
		return (1);
	return (0);
}

int	ft_get_multi_paths(t_env *env)
{
	t_path	***the_paths;
	t_nod	**the_nods;
	int		num_link;
	int		i;

	num_link = ft_count_links(env->end->links, -1);
	if (!(the_paths = (t_path ***)ft_memalloc(sizeof(t_path **) * (num_link + 1))))
		return (1);
	if (!(the_nods = (t_nod **)ft_memalloc(sizeof(t_nod *) * (num_link + 1))))
		return (1/*free the_paths*/);
	ft_get_the_nods(the_paths, the_nods, env->end->links, 0);
	i = -1;
	while (++i < num_link)
	{
		if (ft_path_finder(the_paths[i], the_nods[i], env->end, env->start))
			return (1);
	}
	env->the_paths = the_paths;
	ft_memdel((void **)&the_nods);
	i = -1;
	ft_aff_paths(env->the_paths);
	return (0);
}
