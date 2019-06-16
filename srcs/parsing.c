/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:09:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/16 17:21:11 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <limits.h>

t_env		*ft_get_ants(char *str)
{
	t_env *env;
	
	get_next_line(0, &str);
	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
			return (NULL);
	if (ft_strlen(str) > 11
			|| (env->ants = ft_atoli(str)) > INT_MAX
			|| env->ants < INT_MIN)
		return (ft_free_env(env));
	return (env);
}
