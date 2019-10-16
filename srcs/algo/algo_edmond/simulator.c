/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 02:39:59 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/10 03:55:42 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_price_collector(t_door *door_data)
{
	if (door_data && door_data->presence != 0)
		return (door_data->size + door_data->presence - 1);
	return (0);
}

t_tree_nod	*ft_best_door(t_tree_nod *start, int flow)
{
	t_tree_nod	*best_door;
	t_door		*d_data;
	t_llist_nod	*link;
	int			min;

	min = -1;
	link = start->link_list;
	while (link)
	{
		d_data = ft_door_data_collector((link->linked_room)->door_data, flow);
		if (d_data && (min < 0 || d_data->size + d_data->presence < min))
		{
			best_door = link->linked_room;
			min = d_data->size + d_data->presence;
		}
		link = link->next;
	}
	return (best_door);
}

void		ft_simulator(t_data *data, t_tree_nod *start, int flow, int ants)
{
	t_llist_nod	*link;
	t_tree_nod	*door;
	t_door		*door_data;
	int			price;
	int			price_max;

	while (ants--)
	{
		door = ft_best_door(start, flow);
		ft_door_data_collector(door->door_data, flow)->presence += 1;
	}
	price_max = 0;
	link = start->link_list;
	while (link)
	{
		door_data = ft_door_data_collector(link->linked_room->door_data, flow);
		price = ft_price_collector(door_data);
		price_max = (price && price > price_max) ? price : price_max;
		link = link->next;
	}
	if (!data->the_cost || price_max < data->the_cost)
	{
		data->the_flow = flow;
		data->the_cost = price_max;
	}
}
