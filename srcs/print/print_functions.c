/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:01:28 by brichard          #+#    #+#             */
/*   Updated: 2019/10/02 14:57:19 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void        ft_aff_last_room(t_path *path)
{
	t_path  *tmp;

	tmp = path->next;
	ft_putstr(tmp->node->room_name);
	ft_putchar(' ');
//	ft_putnbr(tmp->node->height);
	ft_putchar(' ');
	while (tmp->next)
		tmp = tmp->next;
//	ft_putnbr(tmp->node->height);
	ft_putchar(' ');
	ft_putstr(tmp->node->room_name);
	ft_putchar('\n');
}

void	ft_aff_one_move(int ant, char *path)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(path);
	ft_putchar(' ');
}

void	ft_aff_paths(t_tree_nod ***the_paths) //remove me for 5 function in file
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
