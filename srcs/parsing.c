/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:09:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/18 15:15:50 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <limits.h>

int			ft_get_rooms_and_links(t_env *env, char *str)
{
	int		i;
	char	s_e;

	i = 0;
	s_e = '\0';
	while (get_next_line(0, &str))
	{
		if (ft_strchr(str, '-'))
		{
			i = 1;
		}
		else if (i == 0)
			ft_stock_room(env, str, &s_e); //BALANCE TREE SINON CASSER CERVEAU
		else
			return (0);
		ft_strdel(&str);
	}
	return (0);
}

int		ft_get_ants(t_env *env, char *str)
{
	long int	ants;

	ants = 0;
	if (get_next_line(0, &str) == -1)
		return (1);
	if (ft_strlen(str) > 11 || (ants = ft_atoli(str)) > INT_MAX || ants < 0)
	{
		ft_strdel(&str);
		return (1);
	}
	env->ants = (int)ants;
	ft_strdel(&str);
	return (0);
}
