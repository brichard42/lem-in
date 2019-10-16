/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:58:30 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/16 17:22:40 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_small_buff(char *buffer, char *str)
{
	ft_strclr(buffer);
	ft_strcpy(buffer, str);
}

void		ft_buffer(char *str, uint8_t ok)
{
	static char buffer[SIZE_OF_BUFF];
	static int	buffer_index = 0;
	int			tmp;

	if (ok == 2)
		ft_bzero((void *)buffer, (sizeof(char) * SIZE_OF_BUFF));
	else
	{
		if (ok == 3)
			buffer_index--;
		tmp = ft_strlen(str);
		if (buffer_index + tmp > SIZE_OF_BUFF - 1)
		{
			write(1, buffer, buffer_index);
			buffer_index = tmp;
			ft_small_buff(buffer, str);
		}
		else
		{
			ft_strcpy(&buffer[buffer_index], str);
			buffer_index += tmp;
			if (ok == 1)
				write(1, buffer, buffer_index);
		}
	}
}
