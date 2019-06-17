/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:09:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/17 16:57:12 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <limits.h>

int			ft_get_rooms_and_links(t_env *env, char *str)
{
	int i;

	i = 0;
	while (get_next_line(0, &str))
	{
		if (ft_strchr(str, '-') && (i == 0 || i == 1))
			ft_stock_link(env, str, &i);
		else if (i == 0)
			ft_stock_room(env, str, &i);
		else
			return (0);
		ft_strdel(&str);
	}
	return (0);
}

t_env		*ft_get_ants(char *str)
{
	t_env *env;
	
	if (get_next_line(0, &str) == -1)
		return (NULL);
	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
			return (NULL);
	if (ft_strlen(str) > 11
			|| (env->ants = ft_atoli(str)) > INT_MAX
			|| env->ants < 0)
		return (ft_free_env(env));
	ft_strdel(&str);
	return (env);
}
