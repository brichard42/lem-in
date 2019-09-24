/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:23:11 by brichard          #+#    #+#             */
/*   Updated: 2019/03/13 18:16:08 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			f_parsing(t_parse *res, char *tmp)
{
	if (*tmp == '-')
		return (p_minu(res));
	else if (*tmp == '+')
		return (p_plus(res));
	else if (*tmp == ' ')
		return (p_spac(res));
	else if (*tmp == '#')
		return (p_hash(res));
	else if (*tmp == '0')
		return (p_zero(res));
	return (0);
}

void		w_parsing(va_list *ap, t_parse *res, char **tmp)
{
	res->width = 0;
	if (**tmp == '*')
	{
		++(*tmp);
		wild_card(res, ap);
		if (ft_isdigit(**tmp))
		{
			res->width = 0;
			w_parsing(ap, res, tmp);
		}
	}
	else
	{
		while (ft_isdigit(**tmp))
		{
			res->width = res->width * 10 + (**tmp - '0');
			++(*tmp);
		}
	}
}

void		p_parsing(va_list *ap, t_parse *res, char **tmp)
{
	if (**tmp == '.')
	{
		res->prec = 0;
		++(*tmp);
		if (**tmp == '*')
		{
			wild_card(res, ap);
			++(*tmp);
		}
		while (ft_isdigit(**tmp))
		{
			res->prec = res->prec * 10 + (**tmp - '0');
			++(*tmp);
		}
	}
	else if (**tmp == '*')
	{
		wild_card(res, ap);
		++(*tmp);
	}
}

void		l_parsing(t_parse *res, char **tmp)
{
	if (**tmp == 'h')
	{
		if (*((*tmp) + 1) == 'h' && (++(*tmp)))
			res->len = 1;
		else
			res->len = 2;
		++(*tmp);
	}
	else if (**tmp == 'l')
	{
		if (*((*tmp) + 1) == 'l' && (++(*tmp)))
			res->len = 4;
		else
			res->len = 3;
		++(*tmp);
	}
	else if (**tmp == 'L' && (++(*tmp)))
		res->len = 5;
}

int			parsing(va_list *ap, t_parse *res, char **tmp)
{
	while (f_parsing(res, *tmp))
		++*tmp;
	w_parsing(ap, res, tmp);
	p_parsing(ap, res, tmp);
	l_parsing(res, tmp);
	res->conv = **tmp;
	return (check_conv(**tmp));
}
