/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:09:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/04 18:20:15 by brichard         ###   ########.fr       */
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


int			get_ant_nb(char *str)
{
	int64_t	ant_nb;

	ant_nb = 0;
	if (ft_strlen(str) <= 11 && ft_strcheck(str, ft_isdigit) == TRUE)
		ant_nb = ft_atol(str);
	return (ant_nb > INT_MAX || ant_nb < 0 ? 0 : (int)ant_nb); 
}

int8_t		get_ant(t_state_machine *machine)
{
	static int8_t was_called = FALSE;

	if (was_called == FALSE)
	{
		machine->ant_nb = get_ant_nb(str);
		was_called = TRUE;
		ft_strdel(&str);
	}
	machine->state = ST_STR;
	return (machine->ant_nb == 0 ? FAILURE : SUCCESS);
}

int8_t		check_com(t_state_machine *machine)
{
	if (machine->str[0] == COMMENT_SIGN && machine->str[1] == COMMENT_SIGN)
		get_special_com(machine);// CODER CA POTO
	else
		machine->state += 1;

}

int8_t		gnl_str(t_state_machine *machine)
{
	if (get_next_line(0, &machine->str, '\n') > 0 && machine->str != NULL)
		machine->state = ST_COMMENT;
	else
		machine->state = ST_END;
	return (machine->state != ST_END ? SUCCESS : FAILURE);
}

int8_t		parsing(t_state_machine *machine)
{
	static t_state_func	state_func[6] = {&gnl_str, &check_com, &get_ant_nb, &get_rooms, &get_links, &parsing_end};

	while (machine->state != ST_END)
		if (state_func[machine->state](machine) == FAILURE)
			machine->state = ST_END;
}

/*
int			ft_get_rooms_and_links(t_env *env, char *str, int r_l)
{
	char	*ret;
	char	*str;
	char	s_e;

	str = NULL;
	s_e = '\0';
	while (get_next_line(0, &str, '\n') > 0 || str != NULL)
	{
		if ((ret = ft_strchr(str, '-')) && !ft_strchr(ret + 1, '-'))
		{
			r_l = 1;
			if (ft_stock_link(env, str))
				return (ft_free_str(str));
		}
		else if (r_l == 0)
		{
			if (ft_stock_room(env, str, &s_e))
				return (ft_free_str(str));
		}
		else if (ft_free_str(str))
			return (ft_print_error("A link is not well formated."));
		ft_strdel(&str);
	}
	return (FAILURE);
}
*/
