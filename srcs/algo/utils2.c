/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 02:32:22 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/24 15:18:23 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_aff_last_room(t_path *path)
{
	t_path	*tmp;

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
