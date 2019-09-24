/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:17:36 by brichard          #+#    #+#             */
/*   Updated: 2019/09/11 17:53:54 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

static char		*get_end_of_line(char *str, int ret_read)
{
	char	*newline_addr;

	newline_addr = ft_strchr(str, '\n');
	if (ret_read == 0 && newline_addr == NULL && ft_strlen(str) == 0)
		return (NULL);
	else
		return (newline_addr == NULL ? ft_strchr(str, '\0') : newline_addr);
}

static int		read_till_newline(const int fd, char **str)
{
	char	buff[GNL_BUFF_SIZE + 1];
	char	*old_str;
	int		ret_read;

	while ((ret_read = read(fd, buff, GNL_BUFF_SIZE)) > 0)
	{
		buff[ret_read] = '\0';
		old_str = *str;
		*str = ft_strjoin(*str, buff);
		ft_strdel(&old_str);
		if (*str == NULL)
			break ;
		if (ft_strchr(buff, '\n') != NULL)
			break ;
	}
	return (*str == NULL ? FAILURE : ret_read);
}

int8_t			ft_gnl(const int fd, char **line)
{
	static char	*str = NULL;
	char		*eol;
	int			ret_read;
	int8_t		ret_gnl;

	ret_gnl = FAILURE;
	if (fd >= VALID_FD && line != NULL)
	{
		ret_read = read_till_newline(fd, &str);
		if (ret_read != FAILURE)
		{
			ret_gnl = END_OF_FILE;
			eol = get_end_of_line(str, ret_read);
			if (eol != NULL)
			{
				ret_gnl = READ_DONE;
				if ((*line = ft_strsub(str, START, eol - str)) == NULL)
					ret_gnl = FAILURE;
				ft_strcpy(str, eol + (*eol == '\n' ? SKIP_NEWLINE : NO_SKIP));
			}
		}
	}
	if (ret_gnl == FAILURE || ret_gnl == END_OF_FILE || fd == GNL_CLEAR)
		ft_strdel(&str);
	return (ret_gnl);
}
