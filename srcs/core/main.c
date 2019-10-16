/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:33:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/16 18:08:52 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_print_error(t_state_machine *machine)
{
	ft_free_transformed_path(machine->program_data.path_tab);
	ft_free_room_tree(machine->program_data.room_tree);
	write(STDERR_FILENO, "ERROR\n", 6);
	return (EXIT_FAILURE);
}

static int8_t	edmond(t_data *program_data)
{
	if ((ft_algorithm(program_data) == FAILURE))
		return (FAILURE);
	if (!(program_data->path_tab =
			ft_path_collector(program_data, program_data->start, 0)))
		return (FAILURE);
	return (SUCCESS);
}

static int8_t	home_made(t_data *program_data)
{
	if (ft_calc_dist(program_data) == FAILURE)
		return (FAILURE);
	if (program_data->end->height == NO_DISTANCE)
		return (FAILURE);
	if (!(program_data->path_tab = ft_get_multi_paths(program_data, -1)))
		return (FAILURE);
	return (SUCCESS);
}

static int8_t	choose_the_algo(t_data *program_data, int argc, char *arg1)
{
	if (ft_start_to_end(program_data) == FAILURE)
	{
		if (argc > 1 && ft_strequ(arg1, "--homemade"))
		{
			if (home_made(program_data) == FAILURE)
				return (FAILURE);
		}
		else
		{
			if (edmond(program_data) == FAILURE)
				return (FAILURE);
		}
		ft_buffer("\n", 0);
		if (ft_ant_in_paths(program_data->path_tab,
				program_data->ant_nb, -1) == FAILURE)
			return (FAILURE);
		ft_buffer("\0", 1);
	}
	return (SUCCESS);
}

int				main(int argc, char **argv)
{
	t_state_machine	machine;

	ft_bzero((void *)&machine, sizeof(t_state_machine));
	ft_buffer(NULL, 2);
	if (lem_parsing(&machine) == FAILURE)
		return (ft_print_error(&machine));
	if (choose_the_algo(&machine.program_data, argc, argv[1]))
		return (ft_print_error(&machine));
	options(&machine.program_data, argv);
	ft_free_transformed_path(machine.program_data.path_tab);
	ft_free_room_tree(machine.program_data.room_tree);
	return (EXIT_SUCCESS);
}
