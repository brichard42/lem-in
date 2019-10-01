/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:12:57 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/01 13:35:29 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree_nod		**ft_free_ret_nod(t_tree_nod **to_f)
{
	ft_memdel((void **)&to_f);
	return (NULL);
}

static void	ft_height_to_num(t_tree_nod *tree, int i)
{
	if (!tree)
		return ;
	tree->height = i;
	if (tree->left)
		ft_height_to_num(tree->left, i);
	if (tree->right)
		ft_height_to_num(tree->right, i);
}

static int		ft_set_links(t_llist_nod *to_put, t_tree_nod **n_tab, int i, int n_height)
{
	t_tree_nod	*current_room;
	t_llist_nod	*next;

	next = to_put->next;
	current_room = to_put->linked_room;
	if (to_put && (current_room->height > n_height || current_room->height == -1))
		n_tab[i++] = current_room;
	if (next)
		i = ft_set_links(next, n_tab, i, n_height);
	return (i);
}

static void		ft_get_links(t_tree_nod **curr, t_tree_nod **n_tab, int n_height, t_tree_nod *end)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (curr[j])
	{
		if (curr[j] != end)
			i = ft_set_links(curr[j]->link_list, n_tab, i, n_height);
		else
			ft_putchar('a');
		j++;
	}
}

static t_tree_nod	**ft_get_current(t_tree_nod **curr, int n_height, t_tree_nod *end)
{
	int		i;
	int		count;
	t_tree_nod	**n_tab;

	count = 0;
	i = 0;
	while (curr[i])
		count = count + ft_count_links(curr[i++]->link_list, n_height);
	if (count == 0)
		return (ft_free_ret_nod(curr));
	if (!(n_tab = (t_tree_nod **)ft_memalloc(sizeof(t_tree_nod *) * (count + 1))))
		return (ft_free_ret_nod(curr));
	ft_get_links(curr, n_tab, n_height, end);
	i = -1;
	while (n_tab[++i])
		n_tab[i]->height = n_height;
	ft_memdel((void **)&curr);
	return (n_tab);
}

int8_t				ft_calc_dist(t_data *program_data)
{
	t_tree_nod	**curr;
	int		i;

	i = 1;
	ft_height_to_num(program_data->room_tree, -1);
	program_data->start->height = 0;
	if (!(curr = (t_tree_nod **)ft_memalloc(sizeof(t_tree_nod *) * 2)))
		return (1);
	curr[0] = program_data->start;
	while (curr)
	{
		if (!(curr = ft_get_current(curr, i, program_data->end)))
			break ;
		i++;
	}
	return (0);
}	
