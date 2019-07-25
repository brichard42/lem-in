/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_in_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 00:08:08 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/26 01:11:11 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
}

int			ft_ant_in_paths(t_env *env)
{
	int 	i;
	int		tester;
	int		*tab_i;
	int		ants;
	t_path	**paths;

	i = 0;
	paths = env->paths;
	ants = (int)env->ants;
	ft_sort_paths(paths);
	if (!(tab_i = (int *)ft_memalloc(sizeof(int) * (ft_path_counter(paths) + 1))))
		return (1);
	while (ants)
	{
		tester = 0;
		while (paths[i])
		{
			if (ants >= paths[i]->size)
			{
				tester = 1;
				tab_i[i]++;
				ants--;
			}
			i++;
		}
		if (tester == 0)
		{
			tab_i[0] += ants;
			ants = 0;
		}
		i = 0;
	}
	while (tab_i[i] != 0)
	{
		ft_putnbr(tab_i[i++]);
		ft_putchar(' ');
	}
	return (0);
}
