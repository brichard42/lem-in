/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:49:11 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/23 16:26:30 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_delink(t_link **new, t_link *link, t_nod *to_del)
{
	if (link->l_room && link->l_room != to_del)
		ft_link_add(NULL, new, link->l_room->room, link->l_room);
	if (link->left)
		ft_delink(new, link->left, to_del);
	if (link->right)
		ft_delink(new, link->right, to_del);
	return (1);
}

static int	ft_smalletor(t_nod **paths, t_env *env)
{
	int		i;
	t_link	*new;

	new = NULL;
	i = 1;
	while (paths[i])
	{
		if (ft_count_links(paths[i]->links, -1) > 2 && paths[i]
			&& paths[i - 1] && paths[i] != env->end && paths[i - 1] != env->start)
		{
//			ft_putchar('\n');
//			ft_putstr(paths[i - 1]->room);
//			ft_print_links(paths[i]->links);
			ft_delink(&new, paths[i]->links, paths[i - 1]);
//			ft_putchar('\n');
			paths[i]->links = new;
//			ft_print_links(paths[i]->links);
//			ft_putchar('\n');
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_delete_links(t_nod ****pathss, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (pathss[i])
	{
		j = 0;
		while (pathss[i][j])
		{
			if (ft_smalletor(pathss[i][j], env))
				return ;
			j++;
		}
		i++;
	}
}
