/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:33:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/17 16:29:52 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	char	*str;
	t_env	*env;

	str = NULL;
	if (!(env = ft_get_ants(str)))
		return (1);
	if (ft_get_rooms_and_links(env, str))
		return (1);
	ft_putendl(env->room_list);
	ft_putendl(env->link_list);
	return (0);
}
