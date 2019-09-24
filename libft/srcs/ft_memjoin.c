/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:13:32 by brichard          #+#    #+#             */
/*   Updated: 2019/09/11 11:50:22 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(const void *s1, const void *s2, size_t size1, size_t size2)
{
	void	*s3;
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s3 = ft_memalloc(size1 + size2 + 1);
	if (s3 != NULL)
	{
		i = 0;
		while (i < size1)
		{
			((char *)s3)[i] = ((char *)s1)[i];
			++i;
		}
		i = 0;
		while (i < size2)
		{
			((char *)s3)[size1] = ((char *)s2)[i];
			++size1;
			++i;
		}
	}
	return ((void *)s3);
}
