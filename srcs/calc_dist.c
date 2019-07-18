/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:12:57 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/18 04:18:46 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_count_links(t_link *count, int new_hei)
{
	int i;

	i = 0;
	if (!count)
		return (0);
	else
		i++;
	if (count->left && (count->left->l_room->hei > new_hei
				|| count->left->l_room->hei == 0))
		i = i + ft_count_links(count->left, new_hei);
	if (count->right && (count->right->l_room->hei > new_hei
				|| count->right->l_room->hei == 0))
		i = i + ft_count_links(count->right, new_hei);
	return (i);
}

int		ft_set_links(t_link *to_put, t_nod **new_tab, int i, int new_hei)
{
	if (to_put && (to_put->l_room->hei > new_hei || to_put->l_room->hei == 0))
		new_tab[i++] = to_put->l_room;
	if (to_put->left)
		i = ft_set_links(to_put->left, new_tab, i, new_hei);
	if (to_put->right)
		i = ft_set_links(to_put->right, new_tab, i, new_hei);
	return (i);
}

void	ft_get_links(t_nod **current, t_nod **new_tab, int i, int new_hei)
{
	int	j;

	j = 0;
	while (current[j])
	{
		i = ft_set_links(current[j]->links, new_tab, i, new_hei);
		j++;
	}
}

t_nod	**ft_get_current(t_nod **current, int new_hei)
{
	int		i;
	int		count;
	t_nod	**new_tab;

	count = 0;
	i = 0;
	while (current[i])
	{
		count = count + ft_count_links(current[i]->links, new_hei);
		i++;
	}
	if (count == 0)
		return (ft_free_ret_nod(current));
	if (!(new_tab = (t_nod **)ft_memalloc(sizeof(t_nod *) * (count + 1))))
		return (ft_free_ret_nod(current));
	ft_get_links(current, new_tab, 0, new_hei);
	i = 0;
	while (new_tab[i])
	{
		new_tab[i]->hei = new_hei;
		i++;
	}
	ft_memdel((void **)&current);
	return (new_tab);
}

int		ft_calc_dist(t_env *env)
{
	t_nod	**current;
	int		i;

	i = 1;
	ft_hei_to_null(env->tree);
	env->start->hei = -1;
	if (!(current = (t_nod **)ft_memalloc(sizeof(t_nod *) * 2)))
		return (1);
	current[0] = env->start;
	while (current)
	{
		if (!(current = ft_get_current(current, i)))
			break ;
		i++;
	}
	return (0);
}
