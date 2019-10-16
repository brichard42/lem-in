/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:12:02 by brichard          #+#    #+#             */
/*   Updated: 2019/10/16 17:46:48 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		get_special_com(t_state_machine *machine, char *str)
{
	size_t	size;

	size = ft_strlen(str);
	if (size == SIZE_START && ft_strequ("##start", str) == TRUE)
	{
		machine->special_com.is_start = TRUE;
		machine->special_com.is_end = FALSE;
	}
	else if (size == SIZE_END && ft_strequ("##end", str) == TRUE)
	{
		machine->special_com.is_start = FALSE;
		machine->special_com.is_end = TRUE;
	}
}

uint8_t			check_com(t_state_machine *machine, char *str)
{
	int8_t	ret_value;

	ret_value = FALSE;
	if (str[0] == COMMENT_SIGN)
	{
		ret_value = TRUE;
		if (str[0] == COMMENT_SIGN && str[1] == COMMENT_SIGN)
			get_special_com(machine, str);
	}
	return (ret_value);
}
