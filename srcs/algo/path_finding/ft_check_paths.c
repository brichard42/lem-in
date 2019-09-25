/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:49:26 by brichard          #+#    #+#             */
/*   Updated: 2019/09/25 13:49:51 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path			**ft_check_paths(t_path **old_paths, t_data *program_data, int num)
{
	t_path	**new_paths;
	t_path	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new_paths = (t_path **)ft_memalloc(sizeof(t_path *) * num + 1)))
		return (NULL);
	while (old_paths[i])
	{
		tmp = old_paths[i];
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->node == program_data->start)
			new_paths[j++] = old_paths[i];
		else
			ft_free_path_helper(old_paths[i], 0);
		i++;
	}
	if (i == j)
	{
		ft_memdel((void **)&new_paths);
		return (old_paths);
	}
	ft_memdel((void **)&old_paths);
	return (new_paths);
}
