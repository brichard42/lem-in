/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:32:27 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/17 17:00:58 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct		s_room
{
	long int		value;
	struct s_pile	*next;
}					t_room;

typedef struct		s_env
{
	long int		ants;
	char			*link_list;
	char			*room_list;
}					t_env;

int					ft_get_rooms_and_links(t_env *env, char *str);
t_env				*ft_get_ants(char *str);
t_env				*ft_free_env(t_env *env);

void				ft_stock_room(t_env *env, char *str);
void				ft_stock_link(t_env *env, char *str, int *i);

#endif
