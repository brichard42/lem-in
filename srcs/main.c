/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:33:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/12 18:53:07 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_free_tree(t_tree_nod *room_tree)
{
	if (room_tree != NULL)
	{
		if (room_tree->left)
			ft_free_tree(room_tree->left);
		if (room_tree->right)
			ft_free_tree(room_tree->right);
//		ft_free_link(room_tree->links);
		ft_strdel(&room_tree->room);
		ft_memdel((void **)&room_tree);
	}
}

void	ft_print_links(t_link *begin)
{
	if (begin == NULL)
		return ;
	if (begin->right)
		ft_print_links(begin->right);
	if (begin->left)
		ft_print_links(begin->left);
	ft_printf("[%s]\n", begin->name);
}

void	ft_print_room_tree(t_tree_nod *room_tree) // TO DELETE
{
	if (room_tree->right)
		ft_print_room_tree(room_tree->right);
	if (room_tree->left)
		ft_print_room_tree(room_tree->left);
	ft_printf("|\t%-30s\t|\tHeight in Tree: %d\t|\n", room_tree->room, room_tree->height);
	ft_print_links(room_tree->link_tree);
}

static int	ft_print_error(t_state_machine *machine)
{
	ft_free_tree(machine->room_tree);
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
		ft_printf("start: %s\n", machine.start->room);
	else
		ft_printf("start: NONE\n");
	if (machine.end != NULL)
		ft_printf("end: %s\n", machine.end->room);
	else
		ft_printf("end: NONE\n");
	ft_printf("ant_nb: %d\n", machine.ant_nb);
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
//	ft_free_transformed_path(machine.paths);
	ft_free_tree(machine.room_tree);
	return (EXIT_SUCCESS);
}
