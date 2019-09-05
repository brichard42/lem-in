/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:09:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/05 15:48:52 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
int			get_ant_nb(char *str)
{
	int64_t	ant_nb;

	ant_nb = 0;
	if (ft_strlen(str) <= 11 && ft_strcheck(str, ft_isdigit) == TRUE)
		ant_nb = ft_atol(str);
	return (ant_nb > INT_MAX || ant_nb < 0 ? 0 : (int)ant_nb); 
}

int8_t		get_ants(t_state_machine *machine)
{
	char	*str;

	str = NULL;
	if (get_next_line(0, &str, '\n') > 0 && str != NULL)
		machine->ant_nb = get_ant_nb(str);
	ft_strdel(&str);
	return (machine->ant_nb == 0 ? FAILURE : SUCCESS);
}
*/

int8_t		get_rooms(t_state_machine *machine, char *str)
{
	(void)machine;
	(void)str;
	return (FAILURE);
}

int8_t		get_links(t_state_machine *machine, char *str)
{
	(void)machine;
	(void)str;
	return (FAILURE);
}

uint8_t		check_com(t_state_machine *machine, char *str)
{
	(void)machine;
	if (str[0] == COMMENT_SIGN && str[1] == COMMENT_SIGN)
		//get_special_com(machine, str);// CODER CA POTO
		ft_putendl("c'est un com spec");
	return (FALSE);
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
	if (check_com(machine, str) == FALSE)
	{
		machine->ant_nb = get_ant_nb(str);
		machine->state = ST_ROOM;
	}
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
		if (state_func[machine->state](machine, str) == FAILURE)
			break ;
	}
	ft_printf("ants = {%d}\n", machine->ant_nb);
	return (machine->state == ST_LINKS ? SUCCESS : FAILURE);
}
