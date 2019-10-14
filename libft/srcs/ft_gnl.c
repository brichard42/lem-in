/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:17:36 by brichard          #+#    #+#             */
/*   Updated: 2019/10/14 08:06:07 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

static char		*ft_strchr_addr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*(s++) == '\0')
		{
			--s;
			break ;
		}
	}
	return ((char *)s);
}

static char		*get_end_of_line(char *str, int ret_read)
{
	char	*newline_addr;

	newline_addr = ft_strchr_addr(str, '\n');
	if (ret_read == 0 && *newline_addr == '\0' && *str == '\0')
		return (NULL);
	else
		return (newline_addr);
}

static int		read_till_newline(const int fd, t_gnl *data)
{
	char	buff[GNL_BUFF_SIZE + 1];
	int		ret_read;

	while ((ret_read = read(fd, buff, GNL_BUFF_SIZE)) > 0)
	{
		buff[ret_read] = '\0';
		data->str = ft_strjoin(data->str, buff);
		ft_strdel(&data->start);
		data->start = data->str;
		if (data->str == NULL || ft_strchr(buff, '\n') != NULL)
			break ;
	}
	return (data->str == NULL ? FAILURE : ret_read);
}

int8_t			ft_gnl(const int fd, char **line)
{
	static t_gnl	data = {NULL, NULL};
	char			*eol;
	int				ret_read;
	int8_t			ret_gnl;

	ret_gnl = FAILURE;
	if (fd >= VALID_FD && line != NULL)
	{
		ret_read = read_till_newline(fd, &data);
		if (ret_read != FAILURE)
		{
			ret_gnl = END_OF_FILE;
			eol = get_end_of_line(data.str, ret_read);
			if (eol != NULL)
			{
				ret_gnl = READ_DONE;
				if (!(*line = ft_strsub(data.str, START, eol - data.str)))
					ret_gnl = FAILURE;
				data.str = eol + (*eol == '\n' ? SKIP_NEWLINE : NO_SKIP);
			}
		}
	}
	if (ret_gnl == FAILURE || ret_gnl == END_OF_FILE || fd == GNL_CLEAR)
		ft_strdel(&data.start);
	return (ret_gnl);
}
