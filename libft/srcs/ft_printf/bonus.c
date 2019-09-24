/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:38:49 by brichard          #+#    #+#             */
/*   Updated: 2019/03/13 18:16:08 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wild_card(t_parse *res, va_list *ap)
{
	if (res->prec == -1)
	{
		if ((res->width = va_arg(*ap, int)) < 0)
		{
			res->width = -res->width;
			res->f_minus = 1;
		}
	}
	else
	{
		if ((res->prec = va_arg(*ap, int)) < 0)
			res->prec = -1;
	}
}

int		bonus_f_cap(t_parse *res, va_list *ap)
{
	res->len = 5;
	res->conv += 32;
	if (!(ex_flop(res, ap)))
		return (0);
	return (1);
}

int		bonus_d_cap(t_parse *res, va_list *ap)
{
	if (res->len == 3)
		res->len = 4;
	else
		res->len = 3;
	res->conv += 32;
	if (!(ex_ints(res, ap)))
		return (0);
	return (1);
}

int		bonus_o_cap(t_parse *res, va_list *ap)
{
	if (res->len == 3)
		res->len = 4;
	else
		res->len = 3;
	res->conv += 32;
	if (!(ex_octo(res, ap)))
		return (0);
	return (1);
}

int		bonus_u_cap(t_parse *res, va_list *ap)
{
	if (res->len == 3)
		res->len = 4;
	else
		res->len = 3;
	res->conv += 32;
	if (!(ex_unsi(res, ap)))
		return (0);
	return (1);
}
