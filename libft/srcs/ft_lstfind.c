/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:38:48 by brichard          #+#    #+#             */
/*   Updated: 2019/06/13 14:00:16 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, void *data)
{
	if (data == (lst->content))
		return (lst);
	else if (lst->next)
		return (ft_lstfind(lst->next, data));
	return (NULL);
}
