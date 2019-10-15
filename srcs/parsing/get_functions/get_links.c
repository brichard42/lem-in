/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:13:42 by brichard          #+#    #+#             */
/*   Updated: 2019/10/15 17:19:31 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static uint8_t	link_is_valid(char **splited_line)
{
	size_t nbarg;

	nbarg = 0;
	while (splited_line[nbarg] != NULL)
		nbarg++;
	return (nbarg == 2);
}

static int8_t	link_two_rooms(t_state_machine *machine, char **splited_line)
{
	t_tree_nod	*a;
	t_tree_nod	*b;

	if (ft_strequ(splited_line[0], splited_line[1]) == TRUE)
		return (SUCCESS);
	a = ft_search_room(machine->program_data.room_tree, splited_line[0]);
	b = ft_search_room(machine->program_data.room_tree, splited_line[1]);
	return (a != NULL && b != NULL
			&& ft_link_add(&b->link_list, a) == SUCCESS
			&& ft_link_add(&a->link_list, b) == SUCCESS ? SUCCESS : FAILURE);
}

int8_t			get_links(t_state_machine *machine, char *str)
{
	char	**splited_line;
	int8_t	ret_value;

	ret_value = FAILURE;
	if (ft_strchr(str, WHITE_SPACE) == NULL)
	{
		splited_line = ft_strsplit(str, LINK_SEPARATOR);
		if (splited_line != NULL)
		{
			if (link_is_valid(splited_line) == TRUE)
				ret_value = link_two_rooms(machine, splited_line);
			del_splited_line(&splited_line);
		}
	}
	if (machine->state == ST_LINK_PLUS)
		ft_strdel(&str);
	return (ret_value);
}
