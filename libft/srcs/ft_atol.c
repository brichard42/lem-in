/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:32:58 by brichard          #+#    #+#             */
/*   Updated: 2019/09/04 16:13:59 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t		ft_atol(const char *str)
{
	long long	neg;
	long long	num;

	neg = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0') * neg;
		if (num > 0 && neg == -1)
			return (0);
		if (num < 0 && neg == 1)
			return (-1);
		++str;
	}
	return (num);
}
