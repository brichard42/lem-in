/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:21:14 by brichard          #+#    #+#             */
/*   Updated: 2019/03/13 18:15:33 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_length(t_parse *res, va_list *ap, t_ullong *nb)
{
	if (res->len == 4)
		*nb = get_ll_hex_oct(res, ap);
	else if (res->len == 1)
		*nb = get_hh_hex_oct(res, ap);
	else if (res->len == 2)
		*nb = get_h_hex_oct(res, ap);
	else if (res->len == 3)
		*nb = get_l_hex_oct(res, ap);
	else
		*nb = get_hex_oct(res, ap);
}

void	get_lint(t_parse *res, va_list *ap, long long *nb)
{
	if (res->len == 4)
		*nb = get_ll_int(res, ap);
	else if (res->len == 1)
		*nb = get_hh_int(res, ap);
	else if (res->len == 2)
		*nb = get_h_int(res, ap);
	else if (res->len == 3)
		*nb = get_l_int(res, ap);
	else
		*nb = get_int(res, ap);
}

void	get_lflop(t_parse *res, va_list *ap, long double *lf)
{
	if (res->len == 5)
		*lf = get_l_flop(res, ap);
	else
		*lf = get_flop(res, ap);
}
