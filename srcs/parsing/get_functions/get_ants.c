/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:17:41 by brichard          #+#    #+#             */
/*   Updated: 2019/09/17 18:31:28 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_ant_nb(char *str)
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
