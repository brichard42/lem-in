/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:05:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/27 10:41:18 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_stock_ret(char **tab, int i)
{
	ft_tabdel(ft_count_tab(tab), &tab);
	if (i == 1)
		return (ft_print_error("A room is not well formated."));
	else if (!i)
		return (ft_print_error("A link is not well formated."));
	else if (i == 2)
		return (ft_print_error("Room in the given link does not exist."));
	else
		return (1);

}

int			ft_stock_link(t_env *env, char *str)
{
	char	**tab;
	t_nod	*a;
	t_nod	*b;

	if (str[0] == '#')
		return (0);
	if (ft_strchr(str, ' ') || !(tab = ft_strsplit(str, '-')))
		return (ft_print_error("A link is not well formated."));
	if (ft_count_tab(tab) != 2)
		return (ft_stock_ret(tab, 1));
	if (!(a = ft_search_room(env->tree, tab[0]))
			|| !(b = ft_search_room(env->tree, tab[1])))
		return (ft_stock_ret(tab, 2));
	if (ft_link_add(NULL, &b->links, tab[0], env->tree))
		return (1);
	if (ft_link_add(NULL, &a->links, tab[1], env->tree))
		return (1);
	ft_tabdel(ft_count_tab(tab), &tab);
	return (0);
}

int			ft_stock_room(t_env *env, char *str, char *s_e)
{
	char **tab;

	tab = NULL;
	if (str[0] == '#')
	{
		if (str[1] == '#')
		{
			if (ft_strequ("start", &str[2]))
				*s_e = 's';
			else if (ft_strequ("end", &str[2]))
				*s_e = 'e';
		}
		return (0);
	}
	if (str[0] == 'L' || !(tab = ft_strsplit(str, ' ')))
		return (ft_print_error("A room is not well formated."));
	if (ft_count_tab(tab) != 3
			|| !ft_str_is_digit(tab[1]) || !ft_str_is_digit(tab[2]))
		return (ft_stock_ret(tab, 0));
	else if (ft_node_add(env, &env->tree, tab[0], *s_e))
		return (ft_stock_ret(tab, 0));
	if (*s_e != '\0')
		*s_e = '\0';
	ft_tabdel(ft_count_tab(tab), &tab);
	return (0);
}
