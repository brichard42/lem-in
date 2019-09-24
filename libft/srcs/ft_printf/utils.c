/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:41:51 by brichard          #+#    #+#             */
/*   Updated: 2019/03/13 18:17:24 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_conv(char c)
{
	return (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X'
			|| c == 'c' || c == 'f' || c == 's' || c == 'p' || c == '%'
			|| c == 'F' || c == 'D' || c == 'O' || c == 'U' || c == 'b');
}

void	ini_res(t_parse *res)
{
	res->f_minus = 0;
	res->f_plus = 0;
	res->f_space = 0;
	res->f_zero = 0;
	res->f_hash = 0;
	res->width = -1;
	res->prec = -1;
	res->len = 0;
	res->conv = '0';
	res->str = NULL;
	res->str_size = 0;
	res->num_size = 0;
	res->neg = 0;
}

void	skip_param(const char **s)
{
	while (**s && !(check_conv(**s)))
		++(*s);
	++*s;
}
