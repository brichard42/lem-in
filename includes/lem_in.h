/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:32:27 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/22 17:31:41 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# define ERROR 1
# define SUCCESS 0
# define LEFT 'l'
# define RIGHT 'r'

typedef struct		s_nod
{
	char			*room;
	int				hei;
	struct s_nod	*right;
	struct s_nod	*left;
}					t_nod;

typedef struct		s_room
{
	long int		value;
	struct s_pile	*next;
}					t_room;

typedef struct		s_link
{
	char			*name;
	struct s_link	*next;
	struct s_link	**tab_lnk;
}					t_link;

typedef struct		s_env
{
	long int		ants;
	t_nod			*start;
	t_nod			*end;
	t_nod			*tree;
	t_link			*links;
}					t_env;

void				ft_print_tree(t_nod *tree);
int					ft_get_rooms_and_links(t_env *env, char *str, int r_l);
int					ft_get_ants(t_env *env, char *str);

int					ft_node_add(t_env *env, t_nod **tree, char *room, char s_e);
t_nod				*ft_node_new(char *room);
t_nod				*ft_search_node(t_nod *tree, char *key);

void				ft_balance_tree(t_nod **tree, char *room);
void				ft_small_balance(t_nod **tree, int bal);

void				ft_free_tree(t_nod *tree);

int					ft_stock_room(t_env *env, char *str, char *s_e);
int					ft_stock_link(t_env *env, char *str);

int					ft_print_error(char *str);

#endif
