/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:03:37 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/14 11:50:54 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_check_option(char *str)
{
	static int option = 0;
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 'v')
		{
			if (option == 0)
				option = 1;
		}
	}
	return (option);
}

void		options(t_data *data, char **argv)
{
	int	i;
	int	ret;

	i = -1;
	while (argv[++i])
		if (argv[i][0] == '-')
			ret = ft_check_option(&argv[i][0]);
	if (ret == 1)
	{
		ft_printf("- The Edmond-Karp algorithm performed in ");
		ft_printf("%d different residual graph.\n", data->flow - 1);
		ft_printf("- It chose to use the graph number %d.\n", data->the_flow);
		ft_printf("- It printed %d lines to solve it.\n", data->the_cost);
	}
}
