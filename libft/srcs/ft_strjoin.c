/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:18:46 by brichard          #+#    #+#             */
/*   Updated: 2019/09/11 14:30:07 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 != NULL)
	{
		i = 0;
		j = 0;
		while (s1[i])
			s3[j++] = s1[i++];
		i = 0;
		while (s2[i])
			s3[j++] = s2[i++];
	}
	return (s3);
}
