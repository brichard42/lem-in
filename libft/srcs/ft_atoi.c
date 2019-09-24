/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 22:05:05 by brichard          #+#    #+#             */
/*   Updated: 2019/05/13 18:02:48 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
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
	return ((int)num);
}
