/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:27:54 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/17 16:13:15 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*s;

	if (!(s = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (size > 0)
		s[size--] = '\0';
	s[size] = '\0';
	return (s);
}
