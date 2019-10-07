/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:58:26 by brichard          #+#    #+#             */
/*   Updated: 2019/10/07 16:58:40 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_link_list(t_llist_nod *link_list)
{
	if (link_list != NULL)
	{
		if (link_list->next)
			ft_print_link_list(link_list->next);
		ft_printf("[%s]\n", link_list->linked_room->room_name);
	}
}
