/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:32:27 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/20 11:22:20 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct		s_nod
{
	char			*room;
	int				hei;
	char			s_e;
	struct	s_nod	*right;
	struct	s_nod	*left;
}					t_nod;

typedef struct		s_room
{
	long int		value;
	struct s_pile	*next;
}					t_room;

typedef struct		s_env
{
	long int		ants;
	t_nod			*tree;
}					t_env;

void				ft_print_tree(t_nod *tree);
int					ft_get_rooms_and_links(t_env *env, char *str);
int					ft_get_ants(t_env *env, char *str);

int					ft_node_add(t_nod **tree, char *room, char s_e);
t_nod				*ft_node_new(char *room, char s_e);

void				ft_balance_tree(t_nod **tree, char *room);
void				ft_small_balance(t_nod **tree, int bal);

void				ft_free_tree(t_nod *tree);

int					ft_stock_room(t_env *env, char *str, char *s_e);
void				ft_stock_link(t_env *env, char *str);

#endif
