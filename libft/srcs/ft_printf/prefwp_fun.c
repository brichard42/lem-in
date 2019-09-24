/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefwp_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:39:25 by brichard          #+#    #+#             */
/*   Updated: 2019/03/18 11:27:42 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			prec(t_parse *res)
{
	if (res->prec == -1 || res->prec <= (int)res->num_size)
		return (1);
	else if (res->prec > (int)res->num_size)
	{
		if (!(res->str = ft_realloc(&res->str, res->prec\
						, res->prec - res->num_size)))
			return (0);
		ft_memset(res->str, '0', res->prec - res->num_size);
		res->num_size = res->prec;
	}
	return (1);
}

int			put_neg(t_parse *res)
{
	if (res->conv != 'x' && res->conv != 'X' && res->conv != 'o')
	{
		if (!(res->str = ft_realloc(&res->str, res->num_size + 1, 1)))
			return (0);
		res->str[0] = '-';
	}
	return (1);
}

int			prefix(t_parse *res)
{
	if (res->neg == 1)
		put_neg(res);
	else if (res->f_hash == 1 && (res->conv == 'x' || res->conv == 'X'))
	{
		if (!(res->str = ft_realloc(&res->str, res->num_size + 2, 2)))
			return (0);
		res->str[0] = '0';
		res->str[1] = (res->conv == 'x' ? 'x' : 'X');
		res->neg = 2;
	}
	else if ((res->f_plus == 1 && res->conv != 'o') \
				|| (res->f_space == 1 && res->conv != 'o') \
				|| (res->conv == 'o'
				&& res->f_hash == 1 && res->str[0] != '0'))
	{
		if (!(res->str = ft_realloc(&res->str, res->num_size + 1, 1)))
			return (0);
		if (res->conv == 'o' && res->f_hash == 1)
			res->str[0] = '0';
		else
			res->str[0] = (res->f_plus == 1 ? '+' : ' ');
	}
	return (1);
}

void		width_pref(t_parse *res)
{
	if (res->neg == 2 && (res->str[0] = '0'))
		res->str[1] = (res->conv == 'x' ? 'x' : 'X');
	else if (res->neg == 1)
		res->str[0] = '-';
	else if (res->f_plus == 1)
		res->str[0] = '+';
	else if (res->f_space == 1)
		res->str[0] = ' ';
}

int			width(t_parse *res)
{
	int		rea;

	if (res->width <= (int)res->str_size)
		return (1);
	rea = (res->f_minus == 1 ? 0 : res->width - res->str_size);
	if (!(res->str = ft_realloc(&res->str, res->width, rea)))
		return (0);
	if (res->f_zero == 1 && res->f_minus == 0 \
			&& (res->prec == -1 || res->conv == 's'))
	{
		ft_memset(res->str, '0', res->width - \
				(res->conv == 's' ? res->str_size : res->num_size));
		width_pref(res);
	}
	else if (res->f_minus == 1)
		ft_memset(res->str + res->str_size, ' ', res->width - res->str_size);
	else
		ft_memset(res->str, ' ', res->width - res->str_size);
	res->str_size = res->width;
	return (1);
}
