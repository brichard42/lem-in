/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_sender.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:46:50 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/09 05:50:43 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	*ft_path_to_neg(t_nod ***paths, int n_path)
{
	int i;
	int j;
	int	*sizes;

	i = -1;
	if (!(sizes = (int *)ft_memalloc(sizeof(int) * (n_path + 1))))
		return (0);
	while (paths[++i])
	{
		j = 0;
		while (paths[i][j])
			paths[i][j++]->hei = -1;
		sizes[i] = j;
	}
	return (sizes);
}

static void	ft_sender(int name, t_nod **path, int p_size)
{
	int i;

	i = p_size;
	while (--i > 1)
	{
		if (path[i] && path[i]->hei != -1)
		{
			ft_aff_one_move(path[i]->hei, path[i]->room);
			if (path[i + 1])
				path[i + 1]->hei = path[i]->hei;
			path[i]->hei = -1;
		}
	}
	if (name != -1)
	{
		ft_aff_one_move(name, path[i]->room);
		if (path[2])
			path[2]->hei = name;
	}
}

static int	ft_empty_paths(t_nod ***paths, int *sizes)
{
	int i;
	int j;
	int a;

	a = 0;
	i = 0;
	while (paths[i])
	{
		j = sizes[i];
		while (--j > 1)
		{
			if (paths[i][j]->hei != -1)
			{
				a = 1;
				ft_aff_one_move(paths[i][j]->hei, paths[i][j]->room);
				if (paths[i][j + 1])
					paths[i][j + 1]->hei = paths[i][j]->hei;
				paths[i][j]->hei = -1;
			}
		}
		i++;
	}
	return (a);
}

int			ft_send_ants(t_nod ***paths, int *tab_i, int n_path, int ant_name)
{
	int	i;
	int	*sizes;

	i = -1;
	if (!(sizes = ft_path_to_neg(paths, n_path)))
		return (1);
	//while (sizes[++i])
	//{
//		ft_putnbr(sizes[i]);
//		ft_putchar (' ');
//	}
//	ft_putchar('\n');
	i = -1;
	while (++i <= n_path)
	{
		while (tab_i[i] > 0)
		{
			while (tab_i[i] != 0)
			{
				ft_sender(ant_name++, paths[i], sizes[i]);
				if (!tab_i[i + 1])
					ft_empty_paths(&paths[i + 1], &sizes[i + 1]);
				--tab_i[i++];
			}
			ft_putchar('\n');
			i = 0;
		}
	}
	while (ft_empty_paths(paths, sizes))
		ft_putchar('\n');
	ft_memdel((void **)&sizes);
	return (0);
}
