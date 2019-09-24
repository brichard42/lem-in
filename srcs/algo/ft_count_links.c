/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:20:57 by brichard          #+#    #+#             */
/*   Updated: 2019/09/24 15:21:09 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_count_links(t_ltree_nod *count, int n_height)
{
	int		i;
	t_ltree_nod	*left;
	t_ltree_nod	*right;

	i = 0;
	if (!count)
		return (0);
	else
		i++;
	right = count->right;
	left = count->left;
	if (left)
		i = i + ft_count_links(left, n_height);
	if (right)
		i = i + ft_count_links(right, n_height);
	return (i);
}
