/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:33:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/18 16:13:45 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_print_error(t_state_machine *machine)
{
	ft_free_room_tree(machine->room_tree);
	ft_putendl_fd("ERROR", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int			main(void)
{
	t_state_machine	machine;

	ft_bzero((void *)&machine, sizeof(t_state_machine));
	if (lem_parsing(&machine) == FAILURE)
		return (ft_print_error(&machine));
	ft_printf("_____AFTER PARSING_____\n");
	ft_print_room_tree(machine.room_tree);
	if (machine.start != NULL)
		ft_printf("start:\t%-20s\n", machine.start->room_name);
	else
		ft_printf("start:\nNONE\n");
	if (machine.end != NULL)
		ft_printf("end:\t%-20s\n", machine.end->room_name);
	else
		ft_printf("end:\tNONE\n");
	ft_printf("ant_nb:\t%-20d\n", machine.ant_nb);
	ft_free_room_tree(machine.room_tree);
	return (EXIT_SUCCESS);
}
/*
**    if (ft_calc_dist(&machine))
**    	return (ft_free_spec(machine));
**    if (machine.end->height == -1)
**    	return (ft_free_spec(machine));
**    if (ft_get_multi_paths(&machine))
**    	return (ft_free_spec(machine));
**    ft_print_tree(machine.tree);
**    if (machine.start)
**    	ft_printf("start = %s\n", machine.start->room_name);
**    if (machine.end)
**    	ft_printf("end = %s\n", machine.end->room_name);
**    ft_aff_paths(machine.paths);
**    if (ft_ant_in_paths(machine.paths, machine.ants, -1))
**    	return (ft_free_spec(machine));
**    ft_free_transformed_path(machine.paths);
*/
