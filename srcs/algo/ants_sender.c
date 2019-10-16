/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_sender.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:46:50 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/16 17:14:51 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int8_t	ft_free_sizes_ret_i(int *sizes, int8_t ret)
{
	ft_memdel((void **)&sizes);
	return (ret);
}

static int		*ft_path_to_neg(t_tree_nod ***paths, int n_path)
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
			paths[i][j++]->height = -1;
		sizes[i] = j;
	}
	return (sizes);
}

static int8_t	ft_sender(int name, t_tree_nod **path, int p_size)
{
	int i;

	i = p_size;
	while (--i > 1)
	{
		if (path[i] && path[i]->height != -1)
		{
			if (ft_buff_one_move(path[i]->height,
					path[i]->room_name) == FAILURE)
				return (FAILURE);
			if (path[i + 1])
				path[i + 1]->height = path[i]->height;
			path[i]->height = -1;
		}
	}
	if (name != -1)
	{
		if (ft_buff_one_move(name, path[i]->room_name) == FAILURE)
			return (FAILURE);
		if (path[2])
			path[2]->height = name;
	}
	return (SUCCESS);
}

static int		ft_empty_paths(t_tree_nod ***paths, int *sizes)
{
	int i;
	int j;
	int a;

	a = SUCCESS;
	i = 0;
	while (paths[i])
	{
		j = sizes[i];
		while (--j > 1)
		{
			if (paths[i][j]->height != -1)
			{
				a = 2;
				if (ft_buff_one_move(paths[i][j]->height,
						paths[i][j]->room_name) == FAILURE)
					return (FAILURE);
				if (paths[i][j + 1])
					paths[i][j + 1]->height = paths[i][j]->height;
				paths[i][j]->height = -1;
			}
		}
		i++;
	}
	return (a);
}

int8_t			ft_send_ants(t_tree_nod ***paths, int *tab_i, int n_path,
				int ant_name)
{
	int	i;
	int	*sizes;

	if (!(sizes = ft_path_to_neg(paths, n_path)))
		return (FAILURE);
	i = -1;
	while (++i <= n_path)
		while (tab_i[i] > 0)
		{
			while (tab_i[i] != 0)
			{
				if (ft_sender(ant_name++, paths[i], sizes[i]) == FAILURE)
					return (FAILURE);
				if (!tab_i[i + 1])
					if (ft_empty_paths(&paths[i + 1], &sizes[i + 1]) == FAILURE)
						return (FAILURE);
				--tab_i[i++];
			}
			ft_buffer("\n", 3);
			i = 0;
		}
	while ((i = ft_empty_paths(paths, sizes)) != FAILURE && i != SUCCESS)
		ft_buffer("\n", 3);
	return (ft_free_sizes_ret_i(sizes, i));
}
