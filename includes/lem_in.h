/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:32:27 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/19 10:05:06 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# define ERROR 1
# define SUCCESS 0
# define LEFT 'l'
# define RIGHT 'r'

#include <stdio.h>//to TEJ
typedef struct		s_nod
{
	char			*room;
	int				hei;
	struct s_link	*links;
	struct s_nod	*right;
	struct s_nod	*left;
}					t_nod;

typedef struct		s_link
{
	char			*name;
	t_nod			*l_room;
	struct s_link	*parent;
	struct s_link	*right;
	struct s_link	*left;
}					t_link;

typedef struct		s_path
{
	char			*name;
	struct s_path	*next;
	struct s_path	*prev;
}					t_path;

typedef struct		s_env
{
	long int		ants;
	t_path			**the_paths;
	t_nod			*start;
	t_nod			*end;
	t_nod			*tree;
}					t_env;

void				ft_print_tree(t_nod *tree);
int					ft_get_rooms_and_links(t_env *env, char *str, int r_l);
int					ft_get_ants(t_env *env, char *str);
int					ft_get_path(t_env *env);
int					ft_get_multi_paths(t_env *env);

int					ft_node_add(t_env *env, t_nod **tree, char *room, char s_e);
t_nod				*ft_node_new(char *room);

int					ft_link_add(t_link *parent, t_link **l_tree,\
													char *name, t_nod *r_tree);

void				ft_hei_to_neg(t_nod *tree);
int					ft_calc_dist(t_env *env);
int					ft_count_links(t_link *count, int n_hei);

t_nod				*ft_search_room(t_nod *tree, char *key);
t_link				*ft_search_link(t_link *tree, char *key);

void				ft_balance_tree(t_nod **tree, char *room);
void				ft_small_balance(t_nod **tree, int bal);

void				ft_free_tree(t_nod *tree);
t_nod				**ft_free_ret_nod(t_nod **to_f);
void				ft_free_path(t_path *path);

int					ft_stock_room(t_env *env, char *str, char *s_e);
int					ft_stock_link(t_env *env, char *str);

int					ft_print_error(char *str);

#endif
