/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:35:01 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/14 05:38:29 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_push_front(void *content, t_list **start)
{
	t_list	*node;

	node = (t_list *)ft_memalloc(sizeof(t_list));
	node->content = content;
	if (*start)
		node->next = *start;
	*start = node;
}
