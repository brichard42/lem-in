/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:12:57 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/23 16:27:10 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_count_links(t_link *count, int n_hei)
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
	if (left && (left->l_room->hei > n_hei || left->l_room->hei == -1))
		i = i + ft_count_links(left, n_hei);
	if (right && (right->l_room->hei > n_hei || right->l_room->hei == -1))
		i = i + ft_count_links(right, n_hei);
	return (i);
}

static int		ft_set_links(t_link *to_put, t_nod **n_tab, int i, int n_hei)
{
	t_nod	*current_room;
	t_link	*left;
	t_link	*right;

	left = to_put->left;
	right = to_put->right;
	current_room = to_put->l_room;
	if (to_put && (current_room->hei > n_hei || current_room->hei == -1))
		n_tab[i++] = current_room;
	if (left)
		i = ft_set_links(left, n_tab, i, n_hei);
	if (right)
		i = ft_set_links(right, n_tab, i, n_hei);
	return (i);
}

static void		ft_get_links(t_nod **curr, t_nod **n_tab, int n_hei, t_nod *end)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (curr[j])
	{
		if (curr[j] != end)
			i = ft_set_links(curr[j]->links, n_tab, i, n_hei);
		j++;
	}
}

static t_nod	**ft_get_current(t_nod **curr, int n_hei, t_nod *end)
{
	int		i;
	int		count;
	t_nod	**n_tab;

	count = 0;
	i = 0;
	while (curr[i])
		count = count + ft_count_links(curr[i++]->links, n_hei);
	if (count == 0)
		return (ft_free_ret_nod(curr));
	if (!(n_tab = (t_nod **)ft_memalloc(sizeof(t_nod *) * (count + 1))))
		return (ft_free_ret_nod(curr));
	ft_get_links(curr, n_tab, n_hei, end);
	i = -1;
	while (n_tab[++i])
		n_tab[i]->hei = n_hei;
	ft_memdel((void **)&curr);
	return (n_tab);
}

int				ft_calc_dist(t_env *env)
{
	t_nod	**curr;
	int		i;

	i = 1;
	ft_hei_to_neg(env->tree);
	env->start->hei = 0;
	if (!(curr = (t_nod **)ft_memalloc(sizeof(t_nod *) * 2)))
		return (1);
	curr[0] = env->start;
	while (curr)
	{
		if (!(curr = ft_get_current(curr, i, env->end)))
			break ;
		i++;
	}
	return (0);
}
