/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:57:27 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/21 15:23:54 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_print_error(char *str)
{
	ft_putendl("\e[93mAn error has occured :\e[31m");
	ft_putendl(str);
	ft_putstr("\e[39m");
	return (1);
}
