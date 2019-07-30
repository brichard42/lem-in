/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:16:56 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/30 18:59:22 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_free_str(char *str)
{
	ft_strdel(&str);
	return (1);
}

int		ft_ret_i_del_links(t_nod **links, int i)
{
	ft_memdel((void **)&links);
	return (i);
}

int		ft_free_paths_nodes(t_path **paths, t_nod **nodes)
{
	if (paths)
		ft_free_path(paths);
	ft_memdel((void **)&nodes);
	return (1);
}

void	ft_free_transformed_path(t_nod ***paths)
{
	int	i;
	int j;

	j = 0;
	i = -1;
	if (paths)
	{
		while (paths[++i])
		{
			while (paths[i][j])
				j++;
			ft_memdel((void **)&paths[i][j - 1]->room);
			ft_memdel((void **)&paths[i][j - 1]);
			ft_memdel((void **)&paths[i]);
		}
		ft_memdel((void **)&paths);
	}
}
