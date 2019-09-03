/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:57:27 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/03 16:26:13 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_print_error(char *str)
{
	ft_putendl("\e[93mAn error has occured :\e[31m");
	if (str)
		ft_putendl(str);
	ft_putstr("\e[39m");
	return (FAILURE);
}
