/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_in_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 00:08:08 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/26 03:36:55 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_reduce_paths(t_path **paths)
{
	int i;
	int red;

	i = 0;
	red = paths[0]->size - 1;
	while (paths[i])
	{
		paths[i++]->size -= red;
	}
}

static void	ft_sort_paths(t_path **paths)
{
	int		i;
	int		j;
	t_path	*tmp;

	i = 0;
	j = ft_path_counter(paths);
	while (i < j)
	{
		while (paths[i])
		{
			if (paths[i + 1])
			{
				if (paths[i]->size > paths[i + 1]->size)
				{
					tmp = paths[i];
					paths[i] = paths[i + 1];
					paths[i + 1] = tmp;
				}
			}
			i++;
		}
		i = 0;
		j--;
	}
	ft_reduce_paths(paths);
}

/*static void	ft_aff_ants(t_paths **paths, int *tab_i, t_env *env, int n_path)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (tab_i[0])
	{
		while (paths[j])
		{
			ft_putchar('L');
			ft_putnbr(i);
			ft_putchar('-');
//			ft_put_room_name(
		}
		j = 0;
	}
}*/

int			ft_ant_in_paths(t_env *env, t_path **paths)
{
	int		i;
	int		*tab_i;
	int		ants;
	int		n_path;

	i = -1;
	ants = (int)env->ants;
	ft_sort_paths(paths);
	n_path = ft_path_counter(paths);
	if (!(tab_i = (int *)ft_memalloc(sizeof(int) * (n_path + 1))))
		return (1);
	while (ants)
	{
		while (paths[++i])
		{
			if (ants >= paths[i]->size)
			{
				tab_i[i]++;
				ants--;
			}
		}
		i = -1;
	}
	while (tab_i[++i])
	{
		ft_putnbr(tab_i[i]);
		ft_putchar('\n');
	}
//	ft_aff_ants(paths, tab_i, env, n_path);
	return (0);
}
