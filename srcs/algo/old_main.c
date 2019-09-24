/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:33:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/24 14:54:11 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include "../libft/includes/ft_printf.h"

static int	ft_free_spec(t_data program_data, int ok)
{
	ft_free_tree(program_data.tree);
	if (ok)
		ft_putendl("There is no path to the end.");
	return (1);
}

int			main(void)
{
	t_data	program_data;

	ft_bzero(&program_data, sizeof(t_data));
	if (ft_parser(&program_data))
		return (1);
	ft_putchar('\n');
	if (ft_calc_dist(&program_data))
		return (ft_free_spec(program_data, 0));
	if (program_data.end->height == -1)
		return (ft_free_spec(program_data, 1));
//	ft_print_tree(program_data.tree);
//	if (program_data.start)
//		ft_printf("start = %s\n", program_data.start->room_name);
//	if (program_data.end)
//		ft_printf("end = %s\n", program_data.end->room_name);
//	ft_aff_paths(program_data.paths);
	if (ft_solver(&program_data))
		return (ft_free_spec(program_data, 0));
	if (ft_ant_in_paths(program_data.paths, program_data.ants, -1))
		return (ft_free_spec(program_data, 0));
	ft_free_transformed_path(program_data.paths);
	ft_free_tree(program_data.tree);
	return (0);
}


/*
void				ft_print_tree(t_tree_nod *tree); // TO TEJ
void				ft_aff_paths(t_tree_nod ***the_paths); // TO TEJ
int					ft_get_path(t_data *program_data);
int					ft_get_multi_paths(t_data *program_data);
int					ft_node_in_path(t_path *path, int i);

int					ft_create_path(t_path **path, t_tree_nod *new);



int					ft_path_counter(t_path **paths);
void				ft_height_to_num(t_tree_nod *tree, int i);
int					ft_count_links(t_ltree_nod *count, int n_height);
int					ft_get_next_tree_node(t_path *path, t_tree_nod **node, t_data *program_data);
t_path				**ft_check_paths(t_path **old_paths, t_data *program_data, int num);
t_tree_nod			***ft_transform_paths(t_path **paths, t_data *program_data);

int					ft_ant_in_paths(t_tree_nod ***paths, int ants, int i);
int					ft_send_ants(t_tree_nod ***paths, int *tab_i, int n_path,\
	   				int ant_name);
void				ft_aff_one_move(int ant, char *path);

t_ltree_nod				*ft_search_link(t_ltree_nod *tree, char *key);

t_tree_nod				**ft_free_ret_nod(t_tree_nod **to_f);
void				ft_free_tree(t_tree_nod *tree);
void				ft_free_transformed_path(t_tree_nod ***paths);
void				ft_free_path(t_path **path, int j);
int					ft_free_paths_nodes(t_path **paths, t_tree_nod **nodes);
int					ft_free_str(char *str);
int					ft_ret_i_del_links(t_tree_nod **links, int i);
*/
