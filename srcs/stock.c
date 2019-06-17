/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:05:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/17 17:00:34 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_stock_link(t_env *env, char *str, int *i)
{
	if (*i == 0)
		*i = 1;
	if (!str || !*str)
		return ;
	env->link_list = ft_str_join(env->link_list, str);
}

void	ft_stock_room(t_env *env, char *str)
{
	char **tab;

	if (str[0] == '#')
		return ;
	if (!(tab = ft_strsplit(str, ' ')))
		return ;
	if (ft_count_tab(tab) != 3)
		return (ft_tabdel(ft_count_tab(tab), &tab));
	if (!ft_str_is_digit(tab[1]) || !ft_str_is_digit(tab[2]) || tab[3] != NULL)
		return (ft_tabdel(ft_count_tab(tab), &tab));
	else
		env->room_list = ft_str_join(env->room_list, str);
}
