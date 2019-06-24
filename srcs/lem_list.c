/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 11:08:34 by brichard          #+#    #+#             */
/*   Updated: 2019/06/24 13:15:52 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	ps_del(char *name)
{
	ft_strdel(&name);
}

void	ft_linkdelone(t_link **alst, void (*del)(char*))
{
	if (!del || !alst || !*alst)
		return ;
	del((*alst)->name);
	ft_memdel((void**)alst);
}

void	ft_linkdel(t_link **alst, void (*del)(char*))
{
	if (!alst || !*alst || !del)
		return ;
	if ((*alst)->next)
		ft_linkdel(&((*alst)->next), del);
	ft_linkdelone(alst, del);
}

void	ft_linkadd(t_link **alst, t_link *new)
{
	if (!alst || !new)
		return ;
	if (*alst)
		(*alst)->prev = new;
	new->next = *alst;
	new->prev = NULL;
	*alst = new;
}

t_link	*ft_linknew(char const *name, t_nod *l_room)
{
	t_link	*new;

	new = NULL;
	if (!(new = (t_link*)ft_memalloc(sizeof(t_link))))
		return (NULL);
	if (name && l_room)
	{
		if (!(new->name = ft_strdup(name)))
		{
			free(new);
			return (NULL);
		}
		new->l_room = l_room;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
