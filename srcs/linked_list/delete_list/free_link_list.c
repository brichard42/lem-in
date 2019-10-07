/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_link_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:00:34 by brichard          #+#    #+#             */
/*   Updated: 2019/10/07 17:00:35 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_link_list(t_llist_nod *link_list)
{
	if (link_list != NULL)
	{
		if (link_list->next)
			ft_free_link_list(link_list->next);
		ft_memdel((void **)&link_list);
	}
}
