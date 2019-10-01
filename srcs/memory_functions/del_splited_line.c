/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_splited_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:19:36 by brichard          #+#    #+#             */
/*   Updated: 2019/10/01 11:22:40 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		del_splited_line(char ***splited_line)
{
	int i;

	i = 0;
	while ((*splited_line)[i] != 0)
		ft_strdel(&(*splited_line)[i++]);
	if ((*splited_line) != NULL)
	{
		free((*splited_line));
		(*splited_line) = NULL;
	}
}
