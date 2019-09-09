/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:09:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/09 17:13:12 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <limits.h>

static int	ft_erro_helper(t_env *env, int reta)
{
	if (reta == -1)
		return (ft_print_error("Error while reading rooms and links."));
	if (!env->start || !env->end)
		return (ft_print_error("Error: Missing Start/End."));
	return (0);
}

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
				return (ft_free_str(str));
		}
		else if (r_l == 0)
		{
			if (ft_stock_room(env, str, &s_e))
				return (ft_free_str(str));
		}
		else if (ft_free_str(str))
			return (ft_print_error("A link is not well formated."));
		ft_strdel(&str);
	}
	return (ft_erro_helper(env, reta));
}

int			ft_get_ants(t_env *env, char *str)
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
