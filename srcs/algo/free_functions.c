/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:01:38 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/24 15:02:09 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_path_helper(t_path *path, int i)
{
	if (!path)
		return ;
	if (path->next)
		ft_free_path_helper(path->next, 1);
	if (!i)
	{
		ft_memdel((void **)&path->node->room_name);
		ft_memdel((void **)&path->node);
	}
	ft_memdel((void **)&path);
}

void		ft_free_path(t_path **path, int j)
{
	int	i;

	i = -1;
	if (path)
		while (path[++i])
			ft_free_path_helper(path[i], j);
	ft_memdel((void **)&path);
}
