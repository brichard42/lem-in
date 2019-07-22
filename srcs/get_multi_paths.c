/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:50:59 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/22 20:45:53 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path	**ft_create_tab_path(t_nod *tmp)
{
	t_path	**new_tab;

	if (!(new_tab = (t_path **)ft_memalloc(sizeof(t_path *) * (tmp->hei + 2))))
		return (NULL);
	if (!(new_tab[tmp->hei] = ft_create_path(tmp, 0)))
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

static void		ft_rem_links(t_link	*link, t_nod *nods)
{
	if (link->left)
		ft_rem_links(link->left, nods);
	if (link->right)
		ft_rem_links(link->right, nods);
	if (link->l_room == nods)
		link->l_room = NULL;
}

static void		ft_clear_links(t_link *link, t_nod *nod)
{
	if (!link->l_room)
		return ;
	if (link->left)
		ft_clear_links(link->left, nod);
	if (link->right)
		ft_clear_links(link->right, nod);
	ft_rem_links(link->l_room->links, nod);
}

static t_nod	*ft_find_path(t_link *link, int dist, t_env *env)
{
	t_nod *save;
	t_nod *tmp;

	save = NULL;
	if (!link)
		return (NULL);
	if (link->l_room)
	{
		if ((link->l_room->hei == dist - 1 && link->l_room != env->end))
		{
			tmp = link->l_room;
			ft_clear_links(link->l_room->links, link->l_room);
			return (tmp);
		}
	}
	if (link->left)
		if ((save = ft_find_path(link->left, dist, env)) != NULL)
			return (save);
	if (link->right)
		if ((save = ft_find_path(link->right, dist, env)) != NULL)
			return (save);
	return (NULL);
}

static int		ft_counti_tab(int *sizes)
{
	int i;

	i = 0;
	while (sizes[i])
		i++;
	return (i);
}

static int		ft_path_finder(t_path ***paths, t_nod **nods, t_env *env, int *sizes)
{
	t_path  *new_path;
	int		j;
	int i;

	j = 0;
	i = ft_counti_tab(sizes);
	while (j < i)
	{
		while (sizes[j] > 0)
		{
			while (paths[j])
			{
				if (!nods[j]->hei)
				{
					sizes[j]--;
					j++;
					break ;
				}
				if (++nods[j]->u > 1 && nods[j] != env->start)
				{
				nods[j] = ft_find_path(nods[j]->links, nods[j]->hei, env);
				if (!(new_path = ft_create_path(nods[j], 2)))
					return (1);
				}
				else
				{
					nods[j] = ft_find_path(nods[j]->links, nods[j]->hei, env);
					if (!(new_path = ft_create_path(nods[j], 0)))
						return (1);
				}
				paths[j][sizes[j] - 1] = new_path;
				sizes[j++]--;	
			}
			j = 0;
		}
		j++;
	}
	return (0);
}

static int		*ft_get_path_sizes(t_nod **nods, int num_link)
{
	int	*sizes;
	int i;

	i = 0;
	if (!(sizes = (int *)ft_memalloc(sizeof(int) * (num_link + 1))))
		return (NULL);
	while (i < num_link)
	{
		sizes[i] = nods[i]->hei;
		i++;
	}
	i = 0;
	return (sizes);
}

static t_path	***ft_check_paths(t_path ***old_paths, int num_link)
{
	int i;
	int j;
	int k;
	t_path ***new_paths;

	i = 0;
	j = 0;
	k = 0;
	if (!(new_paths = (t_path ***)ft_memalloc(sizeof(t_path **) * num_link)))
		return (NULL);
	while (old_paths[j] && old_paths[j][0])
	{
		if (old_paths[j][0]->u != 2)
		{
			new_paths[i] = old_paths[j];
			i++;
		}
		else
			old_paths[j][0] = NULL;
		j++;
	}
	if (i == num_link)
	{
		ft_memdel((void **)&new_paths);
		return (old_paths/*oublie po les free*/);
	}
	return (new_paths);
	//REGARDE BIEN CETTE FONCTION IL MANQUE SURREMENT 20000 FREE
}

int	ft_get_multi_paths(t_env *env)
{
	t_path	***the_paths;
	t_nod	**the_nods;
	int		num_link;
	int		*sizes;

	num_link = ft_count_links(env->end->links, -1);
	if (!(the_paths = (t_path ***)ft_memalloc(sizeof(t_path **) * (num_link + 1))))
		return (1);
	if (!(the_nods = (t_nod **)ft_memalloc(sizeof(t_nod *) * (num_link + 1))))
		return (1/*free the_paths*/);
	ft_get_the_nods(the_paths, the_nods, env->end->links, 0);
	if (!(sizes = ft_get_path_sizes(the_nods, num_link)))
		return (1); //free paths and nods
	ft_path_finder(the_paths, the_nods, env, sizes);
	the_paths = ft_check_paths(the_paths, num_link);
	env->the_paths = the_paths;
	ft_memdel((void **)&the_nods);
	ft_memdel((void **)&sizes);
	ft_aff_paths(env->the_paths);
	return (0);
}
