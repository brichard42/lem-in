/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:32:27 by tlandema          #+#    #+#             */
/*   Updated: 2019/07/03 12:28:47 by brichard         ###   ########.fr       */
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

typedef struct		s_env
{
	long int		ants;
	t_nod			*start;
	t_nod			*end;
	t_nod			*tree;
}					t_env;

void				ft_print_tree(t_nod *tree);
int					ft_get_rooms_and_links(t_env *env, char *str, int r_l);
int					ft_get_ants(t_env *env, char *str);

int					ft_node_add(t_env *env, t_nod **tree, char *room, char s_e);
t_nod				*ft_node_new(char *room);

int						ft_link_add(t_link *parent, t_link **l_tree,\
													char *name, t_nod *r_tree);

t_nod				*ft_search_room(t_nod *tree, char *key);
t_link				*ft_search_link(t_link *tree, char *key);

void				ft_balance_tree(t_nod **tree, char *room);
void				ft_small_balance(t_nod **tree, int bal);

void				ft_free_tree(t_nod *tree);

int					ft_stock_room(t_env *env, char *str, char *s_e);
int					ft_stock_link(t_env *env, char *str);

int					ft_print_error(char *str);

#endif
