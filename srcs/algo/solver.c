/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 03:07:53 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/24 15:19:09 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_amount_of_path(t_ltree_nod *end_l, t_ltree_nod *start_l)
{
	int	n_el;
	int	n_sl;

	n_el = ft_count_links(end_l, -1);
	n_sl = ft_count_links(start_l, -1);
	if (n_sl > n_el)
		return (n_el);
	else
		return (n_sl);
}

static int		ft_get_the_num(t_tree_nod ***paths, int red)
{
	int count;
	int count2;
	int i;
	int j;

	i = 0;
	count = 0;
	count2 = 0;
	while (paths[i])
	{
		j = 0;
		while (paths[i][j])
		{
			count++;
			j++;
		}
		count -= red;
		count2++;
		i++;
	}
	if (count2 == 0)
		return (0);
	return (count / count2);
}

static int		ft_get_small_path_size(t_tree_nod ***a, t_tree_nod ***b)
{
	int i;
	int j;
	int min;

	i = 0;
	min = INT_MAX;
	while (a[i])
	{
		j = 0;
		while (a[i] && a[i][j])
			j++;
		if (j < min)
			min = j;
		i++;
	}
	i = 0;
	while (b[i])
	{
		j = 0;
		while (b[i] && b[i][j])
			j++;
		if (j < min)
			min = j;
		i++;
	}
	return (min);
}

static int		ft_out_of_2(t_data *program_data, t_tree_nod ***a, t_tree_nod ***b)
{
	int c_a;
	int c_b;
	int red;
	int most_effective;

	if (!b)
		return (0);
	red = ft_get_small_path_size(a, b);
	c_a = ft_get_the_num(a, red);
	c_b = ft_get_the_num(b, red);
	//ft_putnbr(c_a);
	//ft_putchar(' ');
	//ft_putnbr(c_b);
	//ft_putchar('\n');
	most_effective = c_a >= c_b ? c_a : c_b;
	if (program_data->ant_nb < most_effective)
		return (1);
	else
		return (0);
}

static t_tree_nod	***ft_best_path(t_tree_nod ****pathss, t_data *program_data)
{
	int i;
	int j;

	i = 0;
	while (pathss[i])
	{
		j = 0;
		while (pathss[j])
		{
			if (i == j)
				j++;
			if (!pathss[j])
				return (pathss[i]);
//			ft_putnbr(j);
			if (ft_out_of_2(program_data, pathss[i], pathss[j]))
				j++;
			else
				break ;
		}
		if (!pathss[j])
			return (pathss[i]);
		i++;
	}
	return (pathss[0]);
}

int8_t				ft_solver(t_data *program_data)
{
	t_tree_nod	****pathss;
	int		n_path;
	int		i;

	i = -1;
	n_path = ft_amount_of_path(program_data->end->link_tree, program_data->start->link_tree);
	if (!(pathss = (t_tree_nod ****)ft_memalloc(sizeof(t_tree_nod ***) * (n_path + 1))))
		return (FAILURE);
	while (++i < n_path) //careful 1 = n_path
	{
		pathss[i] = ft_get_multi_paths(program_data);
		ft_delete_links(pathss, program_data);
	}
	if (!(program_data->paths = ft_best_path(pathss, program_data)))
		return (FAILURE);
	//ft_putstr(program_data->paths[0][1]->room_name);
	i = -1;
	while (pathss[++i])
		if (pathss[i] != program_data->paths)
			ft_free_transformed_path(pathss[i]);
	ft_memdel((void **)&pathss);
	return (SUCCESS);
}
