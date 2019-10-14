/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:33:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/12 17:21:53 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_print_error(t_state_machine *machine)
{
	ft_free_room_tree(machine->program_data.room_tree);
	ft_putendl_fd("ERROR", STDERR_FILENO);
	return (EXIT_FAILURE);
}

static int8_t	edmond(t_data *program_data)
{
	if ((ft_algorithm(program_data) == FAILURE))
		return (FAILURE);
	if (!(program_data->path_tab =
			ft_path_collector(program_data, program_data->start)))
		return (FAILURE);
	return (SUCCESS);
}

static int8_t	home_made(t_data *program_data)
{
	if (ft_calc_dist(program_data) == FAILURE)
		return (FAILURE);
	if (program_data->end->height == NO_DISTANCE)
		return (FAILURE);
	if (!(program_data->path_tab = ft_get_multi_paths(program_data)))
		return (FAILURE);
	return (SUCCESS);
}

int				main(int argc, char **argv)
{
	t_state_machine	machine;

	ft_bzero((void *)&machine, sizeof(t_state_machine));
	if (lem_parsing(&machine) == FAILURE)
		return (ft_print_error(&machine));
	if (ft_start_to_end(&machine.program_data) == FAILURE)
	{
		if (argc > 1 && ft_strequ(argv[1], "--homemade"))
		{
			if (home_made(&machine.program_data) == FAILURE)
				return (ft_print_error(&machine));
		}
		else
		{
			if (edmond(&machine.program_data) == FAILURE)
				return (ft_print_error(&machine));
		}
		if (ft_ant_in_paths(machine.program_data.path_tab,
				machine.program_data.ant_nb, -1))
			return (FAILURE);
	}
	ft_putchar('\n');
	ft_free_transformed_path(machine.program_data.path_tab);
	ft_free_room_tree(machine.program_data.room_tree);
	return (EXIT_SUCCESS);
}
