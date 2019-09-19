/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:16:18 by brichard          #+#    #+#             */
/*   Updated: 2019/09/19 16:40:08 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static uint8_t	room_is_valid(char **splited_line)
{
	size_t nb_of_arg;

	nb_of_arg = 0;
	while (splited_line[nb_of_arg] != NULL)
		nb_of_arg++;
	return (nb_of_arg == 3
			&& ft_strcheck(splited_line[1], ft_isdigit) == TRUE
			&& ft_strcheck(splited_line[2], ft_isdigit) == TRUE);
}

static int8_t	put_room_in_tree(t_state_machine *machine, char *str)
{
	char	**splited_line;
	int8_t	ret_value;

	splited_line = NULL;
	ret_value = FAILURE;
	if (str[0] != 'L')
	{
		splited_line = ft_strsplit(str, WHITE_SPACE);
		if (splited_line != NULL)
		{
			if (room_is_valid(splited_line) == TRUE)
				ret_value = ft_room_add(machine, &machine->program_data.room_tree
															, *splited_line);
			del_splited_line(&splited_line);
		}
	}
	return (ret_value);
}

int8_t			get_rooms(t_state_machine *machine, char *str)
{
	int8_t	return_value;

	return_value = FAILURE;
	if (ft_strchr(str, '-') == NULL)
	{
		return_value = put_room_in_tree(machine, str);
		if (return_value == SUCCESS)
			machine->state = ST_ROOM_PLUS;
	}
	else if (machine->state == ST_ROOM_PLUS)
	{
		machine->state = ST_LINK;
		return_value = get_links(machine, str);
		if (return_value == SUCCESS)
			machine->state = ST_LINK_PLUS;
	}
	ft_strdel(&str);
	return (return_value);
}
