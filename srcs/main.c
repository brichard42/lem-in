/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:33:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/22 13:47:57 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	char	*str;
	t_env	env;

	str = NULL;
	ft_bzero(&env, sizeof(t_env));
	if (ft_get_ants(&env, str))
		return (1);
	if (ft_get_rooms_and_links(&env, str, 0))
		return (1);
	//FAIRE UNE FONCTION DE CHECK DES INFOS
	ft_print_tree(env.tree);
	ft_free_tree(env.tree);
	return (0);
}
