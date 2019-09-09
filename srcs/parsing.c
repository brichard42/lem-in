/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:09:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/09 17:51:47 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int8_t		get_links(t_state_machine *machine, char *str)
{
	(void)machine;
	ft_strdel(&str);
	return (FAILURE);
}

int8_t		get_rooms(t_state_machine *machine, char *str)
{
	(void)machine;
	ft_strdel(&str);
	return (FAILURE);
}

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
	ft_strdel(&str);
	return (machine->ant_nb == 0 ? FAILURE : SUCCESS);
}

int8_t		lem_parsing(t_state_machine *machine)
{
	static t_state_func	state_func[3] = {get_ants, get_rooms, get_links};
	char				*str;

	str = NULL;
	while (get_next_line(0, &str, '\n') > 0 && str != NULL)
	{
		ft_putendl(str);
		if (check_com(machine, str) == FALSE)
			if (state_func[machine->state](machine, str) == FAILURE)
				break ;
	}
	//while (get_next_line(0, &str, '\n') > 0) // AJOUTER OPTION CLEAN AU GNL ET L'APPELER AVEC
	//	ft_strdel(&str);
	ft_printf("ants = {%d} | is_start = %d | is_end = %d\n", machine->ant_nb, machine->special_com.is_start, machine->special_com.is_end);
	return (machine->state == ST_LINKS ? SUCCESS : FAILURE);
}
