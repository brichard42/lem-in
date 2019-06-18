/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:05:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/18 15:07:44 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_stock_ret(char **tab)
{
	ft_tabdel(ft_count_tab(tab), &tab);
	return (1);
}

int			ft_stock_room(t_env *env, char *str, char *s_e)
{
	char **tab;

	tab = NULL;
	if (str[0] == '#' && str[1] == '#')
	{
		if (ft_strequ("start", &str[2]))
			*s_e = 's';
		else if (ft_strequ("end", &str[2]))
			*s_e = 'e';
		else
			*s_e = '\0';
	}
	if (!(tab = ft_strsplit(str, ' ')))
		return (1);
	if (ft_count_tab(tab) != 3
			|| !ft_str_is_digit(tab[1]) || !ft_str_is_digit(tab[2]))
		return (ft_stock_ret(tab));
	else if (ft_node_add(&env->tree, tab[0], *s_e))
		return (ft_stock_ret(tab));
	ft_tabdel(ft_count_tab(tab), &tab);
	return (0);
}
