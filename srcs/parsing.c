/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:09:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/12 19:05:43 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		get_special_com(t_state_machine *machine, char *str)
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

uint8_t		check_com(t_state_machine *machine, char *str)
{
	int8_t	ret_value;

	ret_value = FALSE;
	if (str[0] == COMMENT_SIGN)
	{
		ret_value = TRUE;
		if (str[0] == COMMENT_SIGN && str[1] == COMMENT_SIGN)
			get_special_com(machine, str);
		ft_strdel(&str);
	}
	return (ret_value);
}

uint8_t		link_is_valid(char **splited_line)
{
	size_t nb_of_arg;

	nb_of_arg = 0;
	while (splited_line[nb_of_arg++] != NULL);
	return (nb_of_arg == 3 && ft_strequ(splited_line[0], splited_line[1]) == FALSE);
}
uint8_t		room_is_valid(char **splited_line)
{
	size_t nb_of_arg;

	nb_of_arg = 0;
	while (splited_line[nb_of_arg++] != NULL);
	return (nb_of_arg == 4
			&& ft_strcheck(splited_line[1], ft_isdigit) == TRUE
			&& ft_strcheck(splited_line[2], ft_isdigit) == TRUE);
}

void		del_splited_line(char ***splited_line)
{
	int i = 0;

	while ((*splited_line)[i] != 0)
		ft_strdel(&(*splited_line)[i++]);
	if ((*splited_line) != NULL)
	{
		free((*splited_line));
		(*splited_line) = NULL;
	}
}

int8_t		link_two_rooms(t_state_machine *machine, char **splited_line)
{
	t_tree_nod	*a;
	t_tree_nod	*b;
	int8_t		ret_value;

	ret_value = FAILURE;
	a = ft_search_room(machine->room_tree, splited_line[0]);
	b = ft_search_room(machine->room_tree, splited_line[1]);
	if (a != NULL && b != NULL)
		if (ft_link_add(0, &b->link_tree, splited_line[0], a) == SUCCESS
				&& ft_link_add(0, &a->link_tree, splited_line[1], b) == SUCCESS)
			ret_value = SUCCESS;
	return (ret_value);
}

int8_t		get_links(t_state_machine *machine, char *str)
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

int8_t		put_room_in_tree(t_state_machine *machine, char *str)
{
	char 	**splited_line;
	int8_t	ret_value;

	splited_line = NULL;
	ret_value = FAILURE;
	if (str[0] != 'L')
	{
		splited_line = ft_strsplit(str, WHITE_SPACE);
		if (splited_line != NULL)
		{
			if (room_is_valid(splited_line) == TRUE)
				ret_value = ft_node_add(machine, &machine->room_tree, *splited_line);
			del_splited_line(&splited_line);
		}
	}
	return (ret_value);
}

int8_t		get_rooms(t_state_machine *machine, char *str)
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

int			get_ant_nb(char *str)
{
	int64_t	ant_nb;

	ant_nb = 0;
	if (ft_strlen(str) <= 11 && ft_strcheck(str, ft_isdigit) == TRUE)
		ant_nb = ft_atol(str);
	return (ant_nb > INT_MAX || ant_nb < 0 ? 0 : (int)ant_nb); 
}

int8_t		get_ants(t_state_machine *machine, char *str)
{
	machine->ant_nb = get_ant_nb(str);
	machine->state = ST_ROOM;
	machine->special_com.is_start = FALSE;
	machine->special_com.is_end = FALSE;
	ft_strdel(&str);
	return (machine->ant_nb == 0 ? FAILURE : SUCCESS);
}

int8_t		lem_parsing(t_state_machine *machine)
{
	static t_state_func	state_func[5] = {get_ants, get_rooms,
											get_rooms, get_links, get_links};
	char				*str;

	str = NULL;
	while (ft_gnl(0, &str) > 0 && str != NULL)
	{
		ft_putendl(str);//ADDBUFFER ICI
		if (check_com(machine, str) == FALSE)
			if (state_func[machine->state](machine, str) == FAILURE)
				break ;
	}
	ft_gnl(-42, NULL);
	return (machine->state == ST_LINK_PLUS ? SUCCESS : FAILURE);
}

