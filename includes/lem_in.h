/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:07:53 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/16 15:07:57 by tlandema         ###   ########.fr       */
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
enum					e_state
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
typedef struct			s_boleans
{
	uint8_t				is_start;
	uint8_t				is_end;
}						t_boleans;

/*
**	----------Typedef Link Binary_tree Data_struct------------------------------
*/
typedef struct			s_llist_nod
{
	struct s_tree_nod	*linked_room;
	struct s_llist_nod	*next;
}						t_llist_nod;

/*
**	---------Typedef Room Binary_tree Data_struct-------------------------------
*/
typedef struct			s_tree_nod
{
	struct s_tree_nod	*parent;
	struct s_tree_nod	*right;
	struct s_tree_nod	*left;
	struct s_llist_nod	*link_list;
	t_list				*mem_data;
	t_list				*door_data;
	uint8_t				type;
	uint8_t				last_visit;
	int					residue;
	char				*room_name;
	int					height;
}						t_tree_nod;

/*
**	----------Typedef Mem Data_struct-------------------------------------------
*/
typedef struct			s_mem
{
	t_tree_nod			*node;
	int					flow;
}						t_mem;

/*
** ----------Typedef Door Data_struct-------------------------------------------
*/
typedef struct			s_door
{
	int					size;
	int					presence;
	int					flow;
}						t_door;

/*
**	----------Typedef Algo Data_struct------------------------------------------
*/
typedef struct			s_data
{
	t_tree_nod			***path_tab;
	t_tree_nod			*room_tree;
	t_tree_nod			*start;
	t_tree_nod			*end;
	t_list				*tmpath;
	int					ant_nb;
	int					the_flow;
	int					the_cost;
	int					flow;
}						t_data;
/*
**	----------Typedef Bfs Data_struct------------------------------------------
*/
typedef struct			s_bfs
{
	t_llist_nod			*links;
	t_list				*to_check;
	t_list				*checking;
	t_tree_nod			*child;
	t_tree_nod			*parent;
}						t_bfs;

/*
**	----------Typedef State_machine Data_struct---------------------------------
*/
typedef struct			s_state_machine
{
	t_boleans			special_com;
	enum e_state		state;
	t_data				program_data;
}						t_state_machine;

/*
**	---------Typedef Path List Data_struct-------------------------------
*/
typedef struct			s_path
{
	struct s_path		*next;
	t_tree_nod			*node;
	int32_t				size;
}						t_path;

/*
**	----------Typedef State_machine Functions----------------------------------
*/
typedef int8_t			(*t_state_func)(t_state_machine *, char *);

/*
**	Parser
*/
int8_t					lem_parsing(t_state_machine *machine);

int8_t					get_ants(t_state_machine *machine, char *str);
int8_t					get_rooms(t_state_machine *machine, char *str);
int8_t					get_links(t_state_machine *machine, char *str);

uint8_t					check_com(t_state_machine *machine, char *str);

int8_t					ft_room_add(t_state_machine *machine,
								t_tree_nod **room_tree, char *room);
int8_t					ft_link_add(t_llist_nod **l_tree, t_tree_nod *r_tree);

void					del_splited_line(char ***splited_line);
void					ft_buffer(char *str, uint8_t ok);

/*
**	----------Binary_tree-------------------------------------------------------
*/
void					ft_balance_tree(t_tree_nod **tree, char *room);
void					ft_small_balance(t_tree_nod **tree, int bal);
t_tree_nod				*ft_search_room(t_tree_nod *room_tree, char *key);

t_tree_nod				*ft_room_new(char *room_name);

void					ft_free_link_list(t_llist_nod *link_tree);
void					ft_free_room_tree(t_tree_nod *room_tree);

void					ft_print_link_list(t_llist_nod *link_tree);
void					ft_print_room_tree(t_tree_nod *room_tree);

/*
** -----------Algo2-------------------------------------------------------------
*/
int8_t					ft_algorithm(t_data *data);
int8_t					ft_bfs(t_data *data, t_tree_nod *start, int count);
int8_t					ft_add_node_memory(t_list *tmpath, int flow);
int8_t					ft_add_doors(t_tree_nod *start, int flow);
t_tree_nod				***ft_path_collector(t_data *data, t_tree_nod *start,
						int i);
t_tree_nod				*ft_mem_node_collector(t_list *mem);
t_door					*ft_door_data_collector(t_list *data, int flow);
void					ft_simulator(t_data *data, t_tree_nod *start, int flow,
						int ants);
int8_t					ft_push_front(void *content, t_list **start);
void					ft_del_spe(t_list *elem, t_list **start);
void					ft_del_first(t_list **start);
void					ft_del_list(t_list **list);
void					ft_del_list_t(t_list **list);
/*
**	----------Algo--------------------------------------------------------------
*/
int8_t					ft_start_to_end(t_data *data);
int						ft_count_links(t_llist_nod *count, int n_height);
int8_t					ft_calc_dist(t_data *program_data);
t_tree_nod				***ft_get_multi_paths(t_data *program_data, int i);
int8_t					ft_create_path(t_path **path, t_tree_nod *new);
int						ft_get_next_node(t_path *path, t_tree_nod **node,
						t_data *program_data);
int						ft_path_counter(t_path **paths);
void					ft_path_len(t_tree_nod **path);
t_path					**ft_check_paths(t_path **old_paths,
						t_data *program_data, int num, int i);
t_tree_nod				***ft_transform_paths(t_path **path,
						t_data *program_data);
void					ft_aff_paths(t_tree_nod ***the_paths);
int						ft_ant_in_paths(t_tree_nod ***paths, int ants, int i);
int8_t					ft_send_ants(t_tree_nod ***paths, int *tab_i,
						int n_path, int ant_name);
int8_t					ft_buff_one_move(int ant, char *path);
void					options(t_data *data, char **argv);
/*
**	----------Free_function-----------------------------------------------------
*/
t_tree_nod				**ft_free_ret_nod(t_tree_nod **to_f);
void					ft_free_path(t_path **path, int j);
void					ft_free_path_helper(t_path *path, int i);
t_tree_nod				***ft_free_paths_nodes(t_path **paths,
						t_tree_nod **nodes, int i);
int						ft_free_tree_nod_with_ret(t_tree_nod **link_tree,
						int i);
void					ft_free_transformed_path(t_tree_nod ***paths);
int						ft_node_in_path(t_path *path, int i);
#endif
