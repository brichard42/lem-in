/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:29 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/17 16:57:48 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_join(char *str1, char *str2)
{
	char	*str3;

	if (str1 == NULL || !*str1)
		return (ft_strdup(str2));
	str3 = ft_strnew(sizeof(ft_strlen(str1) + ft_strlen(str2) + 1));
	ft_strcat(str3, str1);
	ft_strcat(str3, "\n");
	ft_strcat(str3, str2);
	return (str3);
}
