/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_with_ret_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:35:59 by brichard          #+#    #+#             */
/*   Updated: 2019/10/14 10:54:46 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree_nod	**ft_free_ret_nod(t_tree_nod **to_f)
{
	ft_memdel((void **)&to_f);
	return (NULL);
}

int			ft_free_tree_nod_with_ret(t_tree_nod **link_tree, int i)
{
	ft_memdel((void **)&link_tree);
	return (i);
}
