/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:33:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/20 14:08:41 by tlandema         ###   ########.fr       */
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
	int		i;

	str = NULL;
	ft_bzero(&env, sizeof(t_env));
	if (ft_get_ants(&env, str))
		return (1);
	if (ft_get_rooms_and_links(&env, str, 0))
		return (ft_free_spec(env));
	if (ft_calc_dist(&env))
		return (ft_free_spec(env));
	if (ft_get_multi_paths(&env))
		return (ft_free_spec(env));
	ft_print_tree(env.tree);// a enlever
	if (env.start) // same
		ft_printf("start = %s\n", env.start->room); // same
	if (env.end) //same 
		ft_printf("end = %s\n", env.end->room); //same
	ft_free_tree(env.tree);
	i = -1;
	ft_free_path(env.the_paths);
	ft_memdel((void **)&env.the_paths);
	return (0);
}
