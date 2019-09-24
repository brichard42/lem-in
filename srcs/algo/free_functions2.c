/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:16:56 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/24 14:35:42 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_free_str(char *str)
{
	ft_strdel(&str);
	return (1);
}

int		ft_ret_i_del_links(t_tree_nod **link_tree, int i)
{
	ft_memdel((void **)&link_tree);
	return (i);
}

t_tree_nod		***ft_free_paths_nodes(t_path **paths, t_tree_nod **nodes)
{
	if (paths)
		ft_free_path(paths, 0);
	ft_memdel((void **)&nodes);
	return (NULL);
}

void	ft_free_transformed_path(t_tree_nod ***paths)
{
	int	i;
	int j;

	j = 0;
	i = -1;
	if (paths)
	{
		while (paths[++i])
		{
			j = 0;
			while (paths[i][j])
				j++;
			ft_memdel((void **)&paths[i][j - 1]->room_name);
			ft_memdel((void **)&paths[i][j - 1]);
			ft_memdel((void **)&paths[i]);
		}
		ft_memdel((void **)&paths);
	}
}
