/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:42:41 by brichard          #+#    #+#             */
/*   Updated: 2019/03/13 18:17:24 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double		get_flop(t_parse *res, va_list *ap)
{
	long double lf;

	lf = va_arg(*ap, double);
	if (lf < 0)
	{
		lf *= -1;
		res->neg = 1;
	}
	return (lf);
}

long double		get_l_flop(t_parse *res, va_list *ap)
{
	long double lf;

	lf = va_arg(*ap, long double);
	if (lf < 0)
	{
		lf *= -1;
		res->neg = 1;
	}
	return (lf);
}
