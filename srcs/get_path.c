/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:49:31 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/19 10:26:55 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_nod	*ft_find_path(t_link *link, int dist)
{
	t_nod *save;

	save = NULL;
	if (link->l_room->hei == dist - 1)
		return (link->l_room);
	if (link->left)
		if ((save = ft_find_path(link->left, dist))!= NULL)
			return (save);
	if (link->right)
		if ((save = ft_find_path(link->right, dist)) != NULL)
			return (save);
	return (NULL);
}

static t_path	*ft_create_path(t_nod *tmp)
{
	t_path *new;

	if (!(new = (t_path *)ft_memalloc(sizeof(t_path))))
		return (NULL);
	if (!(new->name = ft_strdup(tmp->room)))
		return (NULL/*free new*/);
	return (new);
}

static void		ft_push_path(t_path *curr, t_path *add)
{
	if (curr->next != NULL)
		ft_push_path(curr->next, add);
	else
	{
		curr->next = add;
		add->prev = curr;
	}
}

static int		ft_path_finder(t_path *the_path, t_nod *node)
{
	t_nod	*new_nod;
	t_path	*new_path;

	if (node->hei == 0)
		return (0);
	if (!(new_nod = ft_find_path(node->links, node->hei)))
		return (1);
	if (!(new_path = ft_create_path(new_nod)))
		return (1);
	ft_push_path(the_path, new_path);
	if (ft_path_finder(the_path, new_nod))
		return (1);
	return (0);
}

static void		ft_print_path(t_path *path, int i) /* TO TEJ */
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

int				ft_get_path(t_env *env)
{
	t_path	*the_path;

	if (!(the_path = (t_path *)ft_memalloc(sizeof(t_path))))
		return (1);
	if (!(the_path->name = ft_strdup(env->end->room)))
		return (1);
	if (ft_path_finder(the_path, env->end))
		return (1);
	env->the_path = the_path;
	ft_putendl("THE PATH");
	ft_print_path(env->the_path, 0);
	ft_putendl("C'ETAIT THE PATH");
	ft_putchar('\n');
	return (0);
}
