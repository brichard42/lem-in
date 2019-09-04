/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:33:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/04 18:08:08 by brichard         ###   ########.fr       */
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
	ft_putendl("ERROR");
	return (EXIT_FAILURE);
}

int			main(void)
{
	t_state_machine	machine;

	ft_bzero((void *)&machine, sizeof(t_state_machine));
	if (get_ants(&machine) == FAILURE)
		return (ft_print_error());
	//if (ft_get_rooms_and_links(&machine, 0) == FAILURE)
		//return (ft_free_spec(machine));
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
	ft_printf("ants = {%d}%42\n", machine.ant_nb);
	return (EXIT_SUCCESS);
}
