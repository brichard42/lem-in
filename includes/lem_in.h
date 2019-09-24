/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:28:22 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/24 15:27:52 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# include <stdint.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/*
**	----------All Project's Defines---------------------------------------------
*/
# include "define.h"

/*
**	----------Enum of States for the State Machine------------------------------
*/
enum				e_state
{
	ST_ANTS,
	ST_ROOM,
	ST_ROOM_PLUS,
	ST_LINK,
	ST_LINK_PLUS
};

/*
**	----------Typedef Booleans for Special Comments on Parsing------------------
*/
typedef struct		s_boleans
{
	uint8_t				is_start;
	uint8_t				is_end;
}					t_boleans;

/*
**	----------Typedef Link Binary_tree Data_struct------------------------------
*/
typedef struct		s_ltree_nod
{
	char				*link_name;
	struct s_ltree_nod	*right;
	struct s_ltree_nod	*left;
	struct s_ltree_nod	*parent;
	struct s_tree_nod	*linked_room;
}					t_ltree_nod;


/*
**	---------Typedef Room Binary_tree Data_struct-------------------------------
*/
typedef struct		s_tree_nod
{
	char				*room_name;
	struct s_tree_nod	*right;
	struct s_tree_nod	*left;
	struct s_ltree_nod	*link_tree;
	int64_t				height;
	uint64_t			mark;
}						t_tree_nod;

/*
**	----------Typedef Algo Data_struct------------------------------------------
*/
typedef struct		s_data
{
	t_tree_nod			***path_tab;
	t_tree_nod			*room_tree;
	t_tree_nod			*start;
	t_tree_nod			*end;
	int64_t				ant_nb;
}					t_data;

/*
**	----------Typedef State_machine Data_struct---------------------------------
*/
typedef struct		s_state_machine
{
	t_data				program_data;
	enum e_state		state;
	t_boleans			special_com;
}					t_state_machine;

/*
**	---------Typedef Path List Data_struct-------------------------------
*/
typedef struct		s_path
{
	t_tree_nod		*node;
	struct s_path	*next;
	size_t			size;
}					t_path;

/*
**	----------Typedef State_machine Functions----------------------------------
*/
typedef int8_t		(*t_state_func)(t_state_machine *, char *);

/*
**	Parser
*/
int8_t				lem_parsing(t_state_machine *machine);

int8_t				get_ants(t_state_machine *machine, char *str);
int8_t				get_rooms(t_state_machine *machine, char *str);
int8_t				get_links(t_state_machine *machine, char *str);

uint8_t				check_com(t_state_machine *machine, char *str);

int8_t				ft_room_add(t_state_machine *machine,
								t_tree_nod **room_tree, char *room);
int8_t				ft_link_add(t_ltree_nod *parent, t_ltree_nod **l_tree,
									char *link_name, t_tree_nod *r_tree);

void				del_splited_line(char ***splited_line);

/*
**	----------Binary_tree-------------------------------------------------------
*/
void				ft_balance_tree(t_tree_nod **tree, char *room);
void				ft_small_balance(t_tree_nod **tree, int bal);
t_tree_nod			*ft_search_room(t_tree_nod *room_tree, char *key);

void				ft_free_link_tree(t_ltree_nod *link_tree);
void				ft_free_room_tree(t_tree_nod *room_tree);

void				ft_print_link_tree(t_ltree_nod *link_tree);
void				ft_print_room_tree(t_tree_nod *room_tree);

/*
**	----------Algo--------------------------------------------------------------
*/
int					ft_count_links(t_ltree_nod *count, int n_height);
int8_t				ft_calc_dist(t_data *program_data);
int8_t				ft_solver(t_data *program_data);
t_tree_nod			***ft_get_multi_paths(t_data *program_data);

/*
**	----------Free_function-----------------------------------------------------
*/
t_tree_nod			**ft_free_ret_nod(t_tree_nod **to_f);
void				ft_free_path(t_path **path, int j);
void				ft_free_path_helper(t_path *path, int i);

#endif
