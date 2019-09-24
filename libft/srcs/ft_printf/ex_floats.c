/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:41:12 by brichard          #+#    #+#             */
/*   Updated: 2019/03/13 18:17:11 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ex_flop(t_parse *res, va_list *ap)
{
	long double		lf;

	if (res->prec == -1)
		res->prec = 6;
	get_lflop(res, ap, &lf);
	if (!(res->str = (ft_ftoa_u(lf, res->prec))))
		return (0);
	res->num_size = ft_strlen(res->str);
	if (!(prefix(res)))
		return (0);
	res->str_size = ft_strlen(res->str);
	if (!(width(res)))
		return (0);
	return (1);
}
