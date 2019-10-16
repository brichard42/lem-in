/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:58:30 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/16 14:58:50 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_buffer(char *str, uint8_t ok)
{
	static char buffer[SIZE_OF_BUFF];
	static int	buffer_index = 0;
	int			tmp;

	if (ok == 2)
		ft_bzero((void *)buffer, (sizeof(char) * SIZE_OF_BUFF));
	else
	{
		tmp = ft_strlen(str);
		if (buffer_index + tmp > SIZE_OF_BUFF - 1)
		{
			write(1, buffer, buffer_index);
			buffer_index = tmp;
			ft_strclr(buffer);
			ft_strcpy(buffer, str);
		}
		else
		{
			ft_strcpy(&buffer[buffer_index], str);
			buffer_index += tmp;
			if (ok)
				write(1, buffer, buffer_index);
		}
	}
}
