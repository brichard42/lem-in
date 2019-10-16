/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:35:01 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/14 05:50:30 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_del_list_t(t_list **list)
{
	while (*list)
	{
		ft_memdel((void **)&(*list)->content);
		ft_del_first(list);
	}
}

void	ft_del_list(t_list **list)
{
	while (*list)
		ft_del_first(list);
}

void	ft_del_spe(t_list *elem, t_list **start)
{
	t_list	*parse;

	if (elem && start && *start)
	{
		elem->content = NULL;
		if (*start == elem)
		{
			*start = (*start)->next;
			ft_memdel((void**)&elem);
		}
		else
		{
			parse = *start;
			while (parse->next != elem)
				parse = parse->next;
			parse->next = elem->next;
			elem->next = NULL;
			ft_memdel((void**)&elem);
		}
	}
}

void	ft_del_first(t_list **start)
{
	t_list	*elem;

	if (start && *start)
	{
		elem = *start;
		elem->content = NULL;
		*start = (*start)->next;
		ft_memdel((void **)&elem);
	}
}
