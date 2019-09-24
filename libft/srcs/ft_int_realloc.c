/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:39:52 by brichard          #+#    #+#             */
/*   Updated: 2019/05/19 17:41:46 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_realloc(int **tab, size_t *size, int new)
{
	int		*tmp;
	size_t	s_tmp;

	s_tmp = *size;
	tmp = *tab;
	if (!(*tab = ft_memalloc(sizeof(int) * (s_tmp + 1))))
		return (0);
	(*tab)[s_tmp] = new;
	--s_tmp;
	while ((int)s_tmp >= 0)
	{
		(*tab)[s_tmp] = tmp[s_tmp];
		--s_tmp;
	}
	ft_memdel((void **)&tmp);
	++*size;
	return (1);
}
