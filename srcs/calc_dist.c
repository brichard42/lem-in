/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:12:57 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/18 16:24:09 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_count_links(t_link *count, int new_hei)
{
	int		i;
	t_link	*left;
	t_link	*right;

	i = 0;
	right = count->right;
	left = count->left;
	if (!count)
		return (0);
	else
		i++;
	if (left && (left->l_room->hei > new_hei || left->l_room->hei == -1))
		i = i + ft_count_links(left, new_hei);
	if (right && (right->l_room->hei > new_hei || right->l_room->hei == -1))
		i = i + ft_count_links(right, new_hei);
	return (i);
}

int		ft_set_links(t_link *to_put, t_nod **new_tab, int i, int new_hei)
{
	t_nod	*current_room;
	t_link	*left;
	t_link	*right;

	left = to_put->left;
	right = to_put->right;
	current_room = to_put->l_room;
	if (to_put && (current_room->hei > new_hei || current_room->hei == -1))
		new_tab[i++] = current_room;
	if (left)
		i = ft_set_links(left, new_tab, i, new_hei);
	if (right)
		i = ft_set_links(right, new_tab, i, new_hei);
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
	ft_hei_to_neg(env->tree);
	env->start->hei = 0;
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
