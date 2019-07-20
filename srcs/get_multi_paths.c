/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:50:59 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/20 08:15:05 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path   *ft_create_path(t_nod *tmp)
{
	t_path *new;

	if (!(new = (t_path *)ft_memalloc(sizeof(t_path))))
		return (NULL);
	if (!(new->name = ft_strdup(tmp->room)))
		return (NULL/*free new*/);
	return (new);
}

static int ft_get_the_nods(t_path **the_path, t_nod **the_nods, t_link *link, int i)
{
	t_nod	*current_room;
	t_link	*left;
	t_link	*right;

	right = link->right;
	left = link->left;
	current_room = link->l_room;
	if (link)
	{
		the_path[i] = ft_create_path(current_room);
		the_nods[i++] = current_room;
	}
	if (left)
		i = ft_get_the_nods(the_path, the_nods, left, i);
	if (right)
		i = ft_get_the_nods(the_path, the_nods, right, i);
	return (i);
}

static t_nod    *ft_find_path(t_link *link, int dist, t_nod *end)
{
	t_nod *save;

	save = NULL;
	if (link->l_room->hei == dist - 1 && link->l_room != end)
		return (link->l_room);
	if (link->left)
		if ((save = ft_find_path(link->left, dist, end))!= NULL)
			return (save);
	if (link->right)
		if ((save = ft_find_path(link->right, dist, end)) != NULL)
			return (save);
	return (NULL);
}


static void ft_push_path(t_path *curr, t_path *add)
{
	if (curr->next != NULL)
	{
		ft_push_path(curr->next, add);
	}
	else
	{
		curr->next = add;
		add->prev = curr;
	}
}

static int      ft_path_finder(t_path *the_path, t_nod *node, t_nod *end)
{
	t_nod   *new_nod;
	t_path  *new_path;

	if (node->hei == 0)
		return (0);
	if (!(new_nod = ft_find_path(node->links, node->hei, end)))
		return (1);
	if (!(new_path = ft_create_path(new_nod)))
		return (1);
	ft_push_path(the_path, new_path);
	if (ft_path_finder(the_path, new_nod, end))
		return (1);
	return (0);
}

static void     ft_print_path(t_path *path, int i) /* TO TEJ */
{

	if (i == 0)
		while (path->next)
			path = path->next;
	if (path)
	{
		ft_putendl(path->name);
		ft_print_path(path->prev, 1);
	}
}

int	ft_get_multi_paths(t_env *env)
{
	t_path	**the_paths;
	t_nod	**the_nods;
	int		num_link;
	int		i;

	num_link = ft_count_links(env->end->links, -1);
	if (!(the_paths = (t_path **)ft_memalloc(sizeof(t_path *) * (num_link + 1))))
		return (1);
	if (!(the_nods = (t_nod **)ft_memalloc(sizeof(t_nod *) * (num_link + 1))))
		return (1/*free the_paths*/);
	ft_get_the_nods(the_paths, the_nods, env->end->links, 0);
	i = -1;
	while (++i < num_link)
	{
		if (ft_path_finder(the_paths[i], the_nods[i], env->end))
			return (1);
	}
	env->the_paths = the_paths;
	ft_memdel((void **)&the_nods);
	i = -1;
	while (env->the_paths[++i])
	{
		/* a enlever */
		ft_putendl("THE PATH");
		ft_print_path(env->the_paths[i], 0);
		ft_putendl("C'ETAIT THE PATH");
		/* jusque la */
	}
	return (0);
}
