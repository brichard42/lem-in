/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:01:28 by brichard          #+#    #+#             */
/*   Updated: 2019/10/15 16:27:27 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int8_t	ft_buff_one_move(int ant, char *path)
{
	char *ant_str;

	if (!(ant_str = ft_lltoa(ant)))
		return (FAILURE);
	ft_buffer("L", 0);
	ft_buffer(ant_str, 0);
	ft_buffer("-", 0);
	ft_buffer(path, 0);
	ft_buffer(" ", 0);
	ft_strdel(&ant_str);
	return (SUCCESS);
}

void	ft_aff_paths(t_tree_nod ***the_paths)
{
	int i;
	int	j;

	i = -1;
	if (!the_paths)
		return ;
	while (the_paths[++i])
	{
		j = -1;
		ft_putendl("THE PATH");
		while (the_paths[i][++j])
			ft_putendl(the_paths[i][j]->room_name);
		ft_putendl("C'ETAIT THE PATH");
	}
}
