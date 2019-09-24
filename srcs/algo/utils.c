/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 03:55:20 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/24 15:52:58 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void        ft_aff_last_room(t_path *path)
{
	t_path  *tmp;

	tmp = path->next;
	ft_putstr(tmp->node->room_name);
	ft_putchar(' ');
	ft_putnbr(tmp->node->height);
	ft_putchar(' ');
	while (tmp->next)
		tmp = tmp->next;
	ft_putnbr(tmp->node->height);
	ft_putchar(' ');
	ft_putstr(tmp->node->room_name);
	ft_putchar('\n');
}

int		ft_node_in_path(t_path *path, int i)
{
	if (path->next)
		i = ft_node_in_path(path->next, i + 1);
	return (i);
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

int		ft_create_path(t_path **path, t_tree_nod *new)
{
	if (!*path)
	{
		if (!(*path = (t_path *)ft_memalloc(sizeof(t_path))))
			return (1);
		(*path)->node = new;
		(*path)->size = 1;
	}
	else
	{
		ft_create_path(&(*path)->next, new);
		(*path)->size++;
	}
	return (0);
}

int		ft_path_counter(t_path **paths)
{
	int i;

	i = 0;
	while (paths[i])
		i++;
	return (i);
}
