/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:33:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/23 15:52:32 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include "../libft/includes/ft_printf.h"

static int	ft_free_spec(t_env env, int ok)
{
	ft_free_tree(env.tree);
	if (ok)
		ft_putendl("There is no path to the end.");
	return (1);
}

int			main(void)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	if (ft_parser(&env))
		return (1);
	ft_putchar('\n');
	if (ft_calc_dist(&env))
		return (ft_free_spec(env, 0));
	if (env.end->hei == -1)
		return (ft_free_spec(env, 1));
//	ft_print_tree(env.tree);
//	if (env.start)
//		ft_printf("start = %s\n", env.start->room);
//	if (env.end)
//		ft_printf("end = %s\n", env.end->room);
//	ft_aff_paths(env.paths);
	if (ft_solver(&env))
		return (ft_free_spec(env, 0));
	if (ft_ant_in_paths(env.paths, env.ants, -1))
		return (ft_free_spec(env, 0));
	ft_free_transformed_path(env.paths);
	ft_free_tree(env.tree);
	return (0);
}
