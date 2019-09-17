/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:33:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/17 13:42:15 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_link_tree(t_ltree_nod *link_tree)
{
	if (link_tree != NULL)
	{
		if (link_tree->right)
			ft_free_link_tree(link_tree->right);
		if (link_tree->left)
			ft_free_link_tree(link_tree->left);
		ft_strdel(&link_tree->link_name);
		ft_memdel((void **)&link_tree);
	}
}

void		ft_free_room_tree(t_tree_nod *room_tree)
{
	if (room_tree != NULL)
	{
		if (room_tree->left)
			ft_free_room_tree(room_tree->left);
		if (room_tree->right)
			ft_free_room_tree(room_tree->right);
		ft_free_link_tree(room_tree->link_tree);
		ft_strdel(&room_tree->room_name);
		ft_memdel((void **)&room_tree);
	}
}

void	ft_print_link_tree(t_ltree_nod *link_tree)
{
	if (link_tree != NULL)
	{
		if (link_tree->right)
			ft_print_link_tree(link_tree->right);
		if (link_tree->left)
			ft_print_link_tree(link_tree->left);
		ft_printf("[%s]\n", link_tree->link_name);
	}
}

void	ft_print_room_tree(t_tree_nod *room_tree) // TO DELETE
{
	if (room_tree->right)
		ft_print_room_tree(room_tree->right);
	if (room_tree->left)
		ft_print_room_tree(room_tree->left);
	ft_printf("|\t%-30s\t|\tHeight in Tree: %d\t|\n", room_tree->room_name, room_tree->height);
	ft_print_link_tree(room_tree->link_tree);
}

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
	//NEED TO CHECK IF THERES AT LEAST ONE LINK
//	if (ft_calc_dist(&machine))
//		return (ft_free_spec(machine));
//	if (machine.end->height == -1)
//		return (ft_free_spec(machine));
//	if (ft_get_multi_paths(&machine))
//		return (ft_free_spec(machine));
//	ft_print_tree(machine.tree);
//	if (machine.start)
//		ft_printf("start = %s\n", machine.start->room_name);
//	if (machine.end)
//		ft_printf("end = %s\n", machine.end->room_name);
//	ft_aff_paths(machine.paths);
//	if (ft_ant_in_paths(machine.paths, machine.ants, -1))
//		return (ft_free_spec(machine));
//	ft_free_transformed_path(machine.paths);
	ft_free_room_tree(machine.room_tree);
	return (EXIT_SUCCESS);
}
