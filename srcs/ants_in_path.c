/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_in_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 00:08:08 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/29 18:43:33 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_reduce_paths(t_nod ***paths)
{
	int i;
	int red;

	i = 0;
	red = paths[0][1]->hei - 1;
	while (paths[i])
		paths[i++][1]->hei -= red;
}

static void	ft_sort_paths(t_nod ***paths)
{
	int		i;
	int		j;
	t_nod	**tmp;

	i = 0;
	j = 0;
	while (paths[j])
		j++;
	while (i < j)
	{
		while (paths[i])
		{
			if (paths[i + 1])
			{
				if (paths[i][1]->hei > paths[i + 1][1]->hei)
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

int			ft_ant_in_paths(t_env *env, t_nod ***paths)
{
	int		i;
	int		*tab_i;
	int		ants;
	int		n_path;

	i = -1;
	n_path = 0;
	while (paths[n_path])
		n_path++;
	ants = (int)env->ants;
	ft_sort_paths(paths);
	if (!(tab_i = (int *)ft_memalloc(sizeof(int) * (n_path + 1))))
		return (1);
	while (ants)
	{
		while (paths[++i])
		{
			if (ants >= paths[i][1]->hei)
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
	ft_send_ants(paths, tab_i, env, n_path);
	ft_memdel((void **)&tab_i);
	return (0);
}
