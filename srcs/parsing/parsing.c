/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:09:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/16 17:47:05 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int8_t		lem_parsing(t_state_machine *machine)
{
	static t_state_func	state_func[5] = {get_ants, get_rooms,
											get_rooms, get_links, get_links};
	char				*str;
	int8_t				ret;

	str = NULL;
	while (ft_gnl(0, &str) > 0 && str != NULL)
	{
		if (check_com(machine, str) == FALSE)
			if ((ret = state_func[machine->state](machine, str)) == FAILURE)
				break ;
		ft_buffer(str, 0);
		ft_buffer("\n", 0);
		ft_strdel(&str);
	}
	if (ret == FAILURE)
		ft_strdel(&str);
	ft_gnl(-42, NULL);
	return (machine->state != ST_LINK_PLUS
			|| machine->program_data.end == NULL
			|| machine->program_data.start == NULL ? FAILURE : SUCCESS);
}
