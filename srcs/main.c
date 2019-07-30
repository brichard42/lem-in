/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:33:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/30 18:50:02 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include "../libft/includes/ft_printf.h"

static int	ft_free_spec(t_env env)
{
	ft_free_tree(env.tree);
	return (1);
}

int			main(void)
{
	char	*str;
	t_env	env;

	str = NULL;
	ft_bzero(&env, sizeof(t_env));
	if (ft_get_ants(&env, str))
		return (ft_free_str(str));
	if (ft_get_rooms_and_links(&env, str, 0))
		return (ft_free_spec(env));
	if (ft_calc_dist(&env))
		return (ft_free_spec(env));
	if (env.end->hei == -1)
		return (ft_free_spec(env));
	if (ft_get_multi_paths(&env))
		return (ft_free_spec(env));
//	ft_print_tree(env.tree);
//	if (env.start)
//		ft_printf("start = %s\n", env.start->room);
//	if (env.end)
//		ft_printf("end = %s\n", env.end->room);
//	ft_aff_paths(env.paths);
	if (ft_ant_in_paths(env.paths, env.ants, -1))
		return (ft_free_spec(env));
	ft_free_tree(env.tree);
	ft_free_transformed_path(env.paths);
	return (0);
}
