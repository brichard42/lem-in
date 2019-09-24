/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 02:32:22 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/08 22:52:06 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_aff_last_room(t_path *path)
{
	t_path	*tmp;

	tmp = path->next;
	ft_putstr(tmp->node->room);
	ft_putchar(' ');
	ft_putnbr(tmp->node->hei);
	ft_putchar(' ');
	while (tmp->next)
		tmp = tmp->next;
	ft_putnbr(tmp->node->hei);
	ft_putchar(' ');
	ft_putstr(tmp->node->room);
	ft_putchar('\n');
}

int		ft_amount_of_path(t_link *end_l, t_link *start_l)
{
	int	n_el;
	int	n_sl;

	n_el = ft_count_links(end_l, -1);
	n_sl = ft_count_links(start_l, -1);
	if (n_sl > n_el)
		return (n_el);
	else
		return (n_sl);
}
