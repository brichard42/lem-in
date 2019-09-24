/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstapp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <brichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:48:09 by brichard          #+#    #+#             */
/*   Updated: 2019/08/27 17:19:24 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstapp(t_list **alst, t_list *lst)
{
	if (!alst || !*alst)
		return ;
	if ((*alst)->next)
		ft_lstapp(&(*alst)->next, lst);
	else
		(*alst)->next = lst;
}
