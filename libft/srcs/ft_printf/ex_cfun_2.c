/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cfun_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:35:14 by brichard          #+#    #+#             */
/*   Updated: 2019/03/13 18:31:31 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ex_unsi(t_parse *res, va_list *ap)
{
	unsigned long long	nb;

	res->f_space = 0;
	res->f_plus = 0;
	get_length(res, ap, &nb);
	if (nb == 0 && res->prec == 0)
		res->str = ft_strdup("");
	else if (!(res->str = ft_ulltoa_ubase(nb, \
					(res->conv == 'b' ? "01" : "0123456789"))))
		return (0);
	res->num_size = ft_strlen(res->str);
	if (!(prec(res)))
		return (0);
	if (!(prefix(res)))
		return (0);
	res->str_size = ft_strlen(res->str);
	if (!(width(res)))
		return (0);
	return (1);
}

int		ex_hexa(t_parse *res, va_list *ap)
{
	t_ullong	nb;

	get_length(res, ap, &nb);
	if (nb == 0 && res->conv != 'p')
		res->f_hash = 0;
	if (res->conv == 'p')
		res->conv = 'x';
	else if (res->conv == 'P')
		res->conv = 'X';
	if (nb == 0 && res->prec == 0)
		res->str = ft_strdup("");
	else if (!(res->str = ft_ulltoa_ubase(nb, (res->conv == 'x' ? H_BASE_LOW
						: H_BASE_CAP))))
		return (0);
	res->num_size = ft_strlen(res->str);
	if (!(prec(res)))
		return (0);
	if (!(prefix(res)))
		return (0);
	res->str_size = ft_strlen(res->str);
	if (!(width(res)))
		return (0);
	return (1);
}

int		ex_point(t_parse *res, va_list *ap)
{
	res->f_hash = 1;
	if (!(ex_hexa(res, ap)))
		return (0);
	return (1);
}
