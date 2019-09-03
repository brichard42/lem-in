/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:09:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/03 18:54:35 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
static int	ft_erro_helper(t_env *env, int reta)
{
	if (reta == -1)
		return (ft_print_error("Error while reading rooms and links."));
	if (!env->start || !env->end)
		return (ft_print_error("Error: Missing Start/End."));
	return (0);
}
*/

int		get_ants_nb(char *str)
{
	int64_t	ants;

	ants = 0;
	if (ft_strlen(str) <= 11 && ft_strcheck(str, ft_isdigit) == TRUE)
		ants = ft_atol(str);
	return (ants > INT_MAX || ants < 0 ? 0 : (int)ants); 
}

uint8_t		ft_get_ants(t_env *env)
{
	char	*str;

	str = NULL;
	if (get_next_line(0, &str, '\n') != FAILURE && str != NULL)
		env->ants = get_ants_nb(str);
	ft_strdel(&str);
	return (env->ants == 0 ? FAILURE : SUCCESS);
}

/*
int			ft_get_rooms_and_links(t_env *env, char *str, int r_l)
{
	char	s_e;
	char	*ret;
	int		reta;

	s_e = '\0';
	while ((reta = get_next_line(0, &str, '\n')) > 0 || str)
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
*/
