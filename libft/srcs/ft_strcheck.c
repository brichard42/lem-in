/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:23:49 by brichard          #+#    #+#             */
/*   Updated: 2019/09/12 18:00:57 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcheck(char *s, int (*check)(int))
{
	while (*s != '\0')
	{
		if (check((int)*s) == FALSE)
			return (FALSE);
		s++;
	}
	return (TRUE);
}