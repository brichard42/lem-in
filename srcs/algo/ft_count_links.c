/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:20:57 by brichard          #+#    #+#             */
/*   Updated: 2019/10/12 01:42:22 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_count_links(t_llist_nod *count, int n_height)
{
	int			i;
	t_llist_nod	*next;

	i = 0;
	if (!count)
		return (0);
	i++;
	next = count->next;
	if (next)
		i = i + ft_count_links(next, n_height);
	return (i);
}
