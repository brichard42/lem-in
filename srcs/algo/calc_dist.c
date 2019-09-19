/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:12:57 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/19 17:39:24 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		set_nod_hei_to_nb(t_tree_nod *room_tree, int8_t nb)
{
	if (room_tree != NULL)
	{
		room_tree->height = nb;
		if (room_tree->left)
			set_nod_hei_to_nb(room_tree->left, nb);
		if (room_tree->right)
			set_nod_hei_to_nb(room_tree->right, nb);
	}
}

static int		ft_count_link_tree(t_ltree_nod *count, int n_hei)
{
	int		i;
	t_ltree_nod	*left;
	t_ltree_nod	*right;

	i = 0;
	right = count->right;
	left = count->left;
	if (!count)
		return (0);
	else
		i++;
	if (left)
		i = i + ft_count_link_tree(left, n_hei);
	if (right)
		i = i + ft_count_link_tree(right, n_hei);
	return (i);
}

static int		ft_set_link_tree(t_ltree_nod *to_put, t_tree_nod **n_tab, int i, int64_t n_hei)
{
	t_tree_nod	*current_room;
	t_ltree_nod	*left;
	t_ltree_nod	*right;

	left = to_put->left;
	right = to_put->right;
	current_room = to_put->linked_room;
	if (to_put && (current_room->height > n_hei || current_room->height == -1))
		n_tab[i++] = current_room;
	if (left)
		i = ft_set_link_tree(left, n_tab, i, n_hei);
	if (right)
		i = ft_set_link_tree(right, n_tab, i, n_hei);
	return (i);
}

static void		ft_get_link_tree(t_tree_nod **curr, t_tree_nod **n_tab, int64_t n_hei, t_tree_nod *end)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (curr[j])
	{
		if (curr[j] != end)
			i = ft_set_link_tree(curr[j]->link_tree, n_tab, i, n_hei);
		j++;
	}
}

static t_tree_nod	**ft_get_current(t_tree_nod **curr, int64_t n_hei, t_tree_nod *end)
{
	int		i;
	int		count;
	t_tree_nod	**n_tab;

	count = 0;
	i = 0;
	while (curr[i])
		count = count + ft_count_link_tree(curr[i++]->link_tree, n_hei);
	if (count == 0)
	{
		ft_free_room_tree(*curr);
		return (NULL);
	}
	if (!(n_tab = (t_tree_nod **)ft_memalloc(sizeof(t_tree_nod *) * (count + 1))))
	{
		ft_free_room_tree(*curr);
		return (NULL);
	}
	ft_get_link_tree(curr, n_tab, n_hei, end);
	i = -1;
	while (n_tab[++i])
		n_tab[i]->height = n_hei;
	ft_memdel((void **)&curr);
	return (n_tab);
}

int8_t				ft_calc_dist(t_data *program_data)
{
	t_tree_nod	**curr;
	int64_t		i;

	i = 1;
	set_nod_hei_to_nb(program_data->room_tree, -1);
	program_data->start->height = 0;
	curr = (t_tree_nod **)ft_memalloc(sizeof(t_tree_nod *) * 2);
	if (curr == NULL)
		return (FAILURE);
	curr[0] = program_data->start;
	while (curr)
	{
		curr = ft_get_current(curr, i, program_data->end);
		if (curr == NULL)
			break ;
		i++;
	}
	return (SUCCESS);
}
