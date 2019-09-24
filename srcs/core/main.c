/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:33:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/24 11:28:39 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_print_error(t_state_machine *machine)
{
	ft_free_room_tree(machine->program_data.room_tree);
	ft_putendl_fd("ERROR", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int			main(void)
{
	t_state_machine	machine;

	ft_bzero((void *)&machine, sizeof(t_state_machine));
	if (lem_parsing(&machine) == FAILURE)
		return (ft_print_error(&machine));
	//ft_printf("\n\n___________________AFTER PARSING_______________________\n\n");
	//ft_print_room_tree(machine.program_data.room_tree);
	//if (machine.program_data.start != NULL)
		//ft_printf("start:\t%-20s\n", machine.program_data.start->room_name);
	//else
		//ft_printf("start:\nNONE\n");
	//if (machine.program_data.end != NULL)
		//ft_printf("end:\t%-20s\n", machine.program_data.end->room_name);
	//else
		//ft_printf("end:\tNONE\n");
	//ft_printf("ant_nb:\t%-20d\n", machine.program_data.ant_nb);
    if (ft_calc_dist(&machine.program_data) == FAILURE)
    	return (FAILURE);
    if (machine.program_data.end->height == NO_DISTANCE)
    	return (ft_print_error(&machine));
					//ft_printf("\n\n_______________________AFTER CALC_DIST___________________\n\n");
					//ft_print_room_tree(machine.program_data.room_tree);
					//if (machine.program_data.start != NULL)
						//ft_printf("start:\t%-20s\n", machine.program_data.start->room_name);
					//else
						//ft_printf("start:\nNONE\n");
					//if (machine.program_data.end != NULL)
						//ft_printf("end:\t%-20s\n", machine.program_data.end->room_name);
					//else
						//ft_printf("end:\tNONE\n");
					//ft_printf("ant_nb:\t%-20d\n", machine.program_data.ant_nb);
	ft_free_room_tree(machine.program_data.room_tree);
	return (EXIT_SUCCESS);
}
// Attention lors des free sur arbre, seul le pointeur est passe est non pas l adresse => ne remets pas a null
/*
**    if (ft_get_multi_paths(&machine))
**    	return (ft_free_spec(machine));
**    ft_print_tree(machine.program_data.tree);
**    if (machine.program_data.start)
**    	ft_printf("start = %s\n", machine.program_data.start->room_name);
**    if (machine.program_data.end)
**    	ft_printf("end = %s\n", machine.program_data.end->room_name);
**    ft_aff_paths(machine.program_data.paths);
**    if (ft_ant_in_paths(machine.program_data.paths, machine.program_data.ants, -1))
**    	return (ft_free_spec(machine));
**    ft_free_transformed_path(machine.program_data.paths);
*/
