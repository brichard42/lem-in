/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_transformed_path.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:31:44 by brichard          #+#    #+#             */
/*   Updated: 2019/09/25 13:32:27 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
