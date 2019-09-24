/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_in_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 00:08:08 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/24 14:44:08 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_reduce_paths(t_tree_nod ***paths)
{
	int i;
	int red;

	i = 0;
	red = paths[0][1]->height - 1;
	while (paths[i])
	{
		//ft_putnbr(paths[i][1]->height);
		//ft_putchar(' ');
		paths[i++][1]->height -= red;
		//ft_putnbr(paths[i - 1][1]->height);
		//ft_putchar('\n');
	}
}

static void	ft_swap_paths(t_tree_nod ***a, t_tree_nod ***b)
{
	t_tree_nod	**tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_sort_paths(t_tree_nod ***paths)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (paths[j])
		j++;
	while (i < j)
	{
		while (paths[i])
		{
			if (paths[i + 1])
				if (paths[i][1]->height > paths[i + 1][1]->height)
					ft_swap_paths(&paths[i], &paths[i + 1]);
			i++;
		}
		i = 0;
		j--;
	}
	ft_reduce_paths(paths);
}

static int	ft_free_tab_i(int *tab_i)
{
	ft_memdel((void **)&tab_i);
	return (1);
}

int			ft_ant_in_paths(t_tree_nod ***paths, int ants, int i)
{
	int		*tab_i;
	int		n_path;
	int		min;

	n_path = 0;
	while (paths[n_path])
		n_path++;
	//if (paths == NULL || paths[0] == NULL)
	//	return (1);
	ft_sort_paths(paths);
	min = paths[0][1]->height;
	if (!(tab_i = (int *)ft_memalloc(sizeof(int) * (n_path + 1))))
		return (1);
	i = -1;
	while (ants)
	{
		while (ants && ++i < n_path)
		{
			if (paths[i][1]->height <= min)
			{
				tab_i[i]++;
				ants--;
				paths[i][1]->height++;
			}
		}
		min++;
		i = -1;
	}
	if (ft_send_ants(paths, tab_i, n_path, 1))
		return (ft_free_tab_i(tab_i));
	ft_memdel((void **)&tab_i);
	return (0);
}
