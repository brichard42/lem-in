/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:32:27 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/16 17:21:08 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct		s_pile
{
	long int		value;
	struct s_pile	*next;
}					t_pile;

typedef struct		s_env
{
	long int		ants;
}					t_env;

t_env				*ft_get_ants(char *str);
t_env				*ft_free_env(t_env *env);

#endif
