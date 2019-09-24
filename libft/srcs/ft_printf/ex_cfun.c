/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cfun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:28:40 by brichard          #+#    #+#             */
/*   Updated: 2019/03/13 18:17:34 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ex_stri(t_parse *res, va_list *ap)
{
	char	*arg;

	if ((arg = va_arg(*ap, char *)))
		res->str_size = ft_strlen(arg);
	else
		res->str_size = 6;
	if (res->str_size > res->prec && res->prec != -1)
		res->str_size = res->prec;
	if (!(res->str = (arg == 0 ? ft_strndup("(null)", res->str_size)
						: ft_strndup(arg, res->str_size))))
		return (0);
	if (!(width(res)))
		return (0);
	return (1);
}

int		ex_char(t_parse *res, va_list *ap)
{
	char	arg;
	char	fill;

	arg = (res->conv == '%' ? '%' : (char)va_arg(*ap, int));
	res->str_size = (res->width < 1 ? 1 : res->width);
	if (!(res->str = ft_realloc(&res->str, res->str_size, 0)))
		return (0);
	if (res->width > 1)
		if (!(res->str = ft_realloc(&res->str, res->width, 0)))
			return (0);
	fill = (res->f_zero == 1 && res->f_minus == 0 ? '0' : ' ');
	res->str = ft_memset((void *)res->str, fill, res->str_size);
	if (res->f_minus == 1)
		*res->str = arg;
	else
		res->str[res->str_size - 1] = arg;
	return (1);
}

int		ex_ints(t_parse *res, va_list *ap)
{
	unsigned long long	nb;

	get_lint(res, ap, (long long*)&nb);
	if (!(res->str = (ft_ulltoa_ubase(nb, "0123456789"))))
		return (0);
	if (nb == 0 && res->prec != -1)
		res->str = ft_strdup("");
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

int		ex_octo(t_parse *res, va_list *ap)
{
	t_ullong	nb;

	get_length(res, ap, &nb);
	if (nb == 0)
	{
		if (res->prec == 0)
			res->str = ft_strdup("");
		else
		{
			res->f_hash = 0;
			res->str = ft_strdup("0");
		}
	}
	else if (!(res->str = ft_ulltoa_ubase(nb, "01234567")))
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
