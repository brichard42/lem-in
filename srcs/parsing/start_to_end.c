/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_to_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 01:16:29 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/12 01:24:51 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int8_t	ft_print_all_in_one(int ants, char *end_name)
{
	int i;

	i = 1;
	while (i <= ants)
		ft_aff_one_move(i++, end_name);
	return (SUCCESS);
}

int8_t	ft_start_to_end(t_data *data)
{
	t_llist_nod	*start_links;
	char		*end_name;

	start_links = data->start->link_list;
	end_name = data->end->room_name;
	while (start_links)
	{
		if (ft_strequ(start_links->linked_room->room_name, end_name))
			return (ft_print_all_in_one(data->ant_nb, end_name));
		start_links = start_links->next;
	}
	return (FAILURE);
}
