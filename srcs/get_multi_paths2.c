/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_paths2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:25:34 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/30 14:25:15 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_get_links(t_nod **tab_link, t_link *link, int i)
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

int				ft_get_next_node(t_path *path, t_nod **node, t_env *env)
{
	t_nod	*new;
	t_nod	**links;

	if (!(links = ft_get_unvisited_links(*node)))
		return (1);
	if (!links[0])
		return (ft_ret_i_del_links(links, 2));
	if (!(new = ft_best_link(links)))
		return (1);
	if (new != env->start)
		new->u++;
	ft_memdel((void **)&links);
	ft_create_path(&path, new);
	*node = new;
	return (0);
}

t_path			**ft_check_paths(t_path **old_paths, t_env *env, int num)
{
	t_path	**new_paths;
	t_path	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new_paths = (t_path **)ft_memalloc(sizeof(t_path *) * num + 1)))
		return (NULL);
	while (old_paths[i])
	{
		tmp = old_paths[i];
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->node == env->start)
			new_paths[j++] = old_paths[i];
		i++;
	}
	if (i == j)
	{
		ft_memdel((void **)&new_paths);
		return (old_paths);
	}
	ft_memdel((void **)&old_paths);
	return (new_paths);
}
