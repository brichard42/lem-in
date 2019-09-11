/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:33:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/11 14:05:40 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//static int	ft_free_spec(t_state_machine machine)
//{
//	ft_free_tree(machine.tree);
//	return (EXIT_FAILURE);
//}

static int	ft_print_error(void)
{
	ft_putendl_fd("ERROR", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int			main(void)
{
	t_state_machine	machine;

	ft_bzero((void *)&machine, sizeof(t_state_machine));
	if (lem_parsing(&machine) == FAILURE)
		return (ft_print_error());
	//NEED TO CHECK IF THERES AT LEAST ONE LINK
//	if (ft_calc_dist(&machine))
//		return (ft_free_spec(machine));
//	if (machine.end->height == -1)
//		return (ft_free_spec(machine));
//	if (ft_get_multi_paths(&machine))
//		return (ft_free_spec(machine));
//	ft_print_tree(machine.tree);
//	if (machine.start)
//		ft_printf("start = %s\n", machine.start->room);
//	if (machine.end)
//		ft_printf("end = %s\n", machine.end->room);
//	ft_aff_paths(machine.paths);
//	if (ft_ant_in_paths(machine.paths, machine.ants, -1))
//		return (ft_free_spec(machine));
//	ft_free_tree(machine.tree);
//	ft_free_transformed_path(machine.paths);
	return (EXIT_SUCCESS);
}
