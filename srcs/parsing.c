/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:09:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/27 11:36:59 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <limits.h>

int			ft_get_rooms_and_links(t_env *env, char *str, int r_l)
{
	char	s_e;
	char	*ret;
	int		reta;

	s_e = '\0';
	while ((reta = get_next_line(0, &str)) > 0 || str)
	{ 
		if ((ret = ft_strchr(str, '-')) && !ft_strchr(ret + 1, '-'))
		{
			r_l = 1;
			if (ft_stock_link(env, str))
				return (1);
		}
		else if (r_l == 0)
		{
			if (ft_stock_room(env, str, &s_e))
				return (1);
		}
		else
			return (ft_print_error("A link is not well formated."));
		ft_strdel(&str);
	}
	if (reta == -1)
		return (ft_print_error("Error while reading rooms and links."));
	return (0);
}

int		ft_get_ants(t_env *env, char *str)
{
	long int	ants;

	ants = 0;
	if (get_next_line(0, &str) == -1 || !str)
		return (ft_print_error("Can't read the amount of ants."));
	if (ft_strlen(str) > 11 || !ft_str_is_digit(str)
		|| (ants = ft_atoli(str)) > INT_MAX || ants <= 0)
	{
		ft_strdel(&str);
		return (ft_print_error("Wrong input or invalid amount of ants."));
	}
	env->ants = (int)ants;
	ft_strdel(&str);
	return (0);
}
