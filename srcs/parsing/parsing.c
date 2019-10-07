/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:09:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/07 11:05:47 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	return (machine->state != ST_LINK_PLUS
			|| machine->program_data.end == NULL
			|| machine->program_data.start == NULL ? FAILURE : SUCCESS);
}
