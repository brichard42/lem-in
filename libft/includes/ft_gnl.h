/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:19:13 by brichard          #+#    #+#             */
/*   Updated: 2019/09/12 11:09:19 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define GNL_BUFF_SIZE 8196

int8_t	ft_gnl(const int fd, char **line);

# define END_OF_FILE	0
# define READ_DONE		1
# define SKIP_NEWLINE	1
# define START			0
# define NO_SKIP		0
# define VALID_FD		0

#endif
