/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_sender.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:46:50 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/29 18:46:26 by tlandema         ###   ########.fr       */
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

static void	ft_sender(int name, t_nod **path, t_nod *end, int p_size)
{
	int i;

	(void)name;
	(void)end;
	(void)p_size;
	i = 0;
	while (path[i])
		i++;
}

void		ft_send_ants(t_nod ***paths, int *tab_i, t_env *env, int n_path)
{
	int		ant_name;
	int		i;
	int		*sizes;

	ant_name = 1;
	i = 0;
	tab_i[n_path] = -1;
	if (!(sizes = ft_path_to_neg(paths, n_path)))
		return ; /*free*/
	while (i++ <= n_path)
	{
		break ;
		while (tab_i[i] > -1)
		{
			if (tab_i[i] > 0)
				tab_i[i]--;
			ft_sender(ant_name++, paths[i], env->end, sizes[i]);
			i++;
		}
	}
}
