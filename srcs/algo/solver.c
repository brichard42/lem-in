/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 03:07:53 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/24 12:52:07 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <limits.h>

static int		ft_get_the_num(t_nod ***paths, int red)
{
	int count;
	int count2;
	int i;
	int j;

	i = 0;
	count = 0;
	count2 = 0;
	while (paths[i])
	{
		j = 0;
		while (paths[i][j])
		{
			count++;
			j++;
		}
		count -= red;
		count2++;
		i++;
	}
	if (count2 == 0)
		return (0);
	return (count / count2);
}

static int		ft_get_small_path_size(t_nod ***a, t_nod ***b)
{
	int i;
	int j;
	int min;

	i = 0;
	min = INT_MAX;
	while (a[i])
	{
		j = 0;
		while (a[i] && a[i][j])
			j++;
		if (j < min)
			min = j;
		i++;
	}
	i = 0;
	while (b[i])
	{
		j = 0;
		while (b[i] && b[i][j])
			j++;
		if (j < min)
			min = j;
		i++;
	}
	return (min);
}

static int		ft_out_of_2(t_env *env, t_nod ***a, t_nod ***b)
{
	int c_a;
	int c_b;
	int red;
	int most_effective;

	if (!b)
		return (0);
	red = ft_get_small_path_size(a, b);
	c_a = ft_get_the_num(a, red);
	c_b = ft_get_the_num(b, red);
	//ft_putnbr(c_a);
	//ft_putchar(' ');
	//ft_putnbr(c_b);
	//ft_putchar('\n');
	most_effective = c_a >= c_b ? c_a : c_b;
	if (env->ants < most_effective)
		return (1);
	else
		return (0);
}

static t_nod	***ft_best_path(t_nod ****pathss, t_env *env)
{
	int i;
	int j;

	i = 0;
	while (pathss[i])
	{
		j = 0;
		while (pathss[j])
		{
			if (i == j)
				j++;
			if (!pathss[j])
				return (pathss[i]);
//			ft_putnbr(j);
			if (ft_out_of_2(env, pathss[i], pathss[j]))
				j++;
			else
				break ;
		}
		if (!pathss[j])
			return (pathss[i]);
		i++;
	}
	return (pathss[0]);
}

int				ft_solver(t_env *env)
{
	t_nod	****pathss;
	int		n_path;
	int		i;

	i = -1;
	n_path = ft_amount_of_path(env->end->links, env->start->links);
	if (!(pathss = (t_nod ****)ft_memalloc(sizeof(t_nod ***) * (n_path + 1))))
		return (1);
	while (++i < n_path) //careful 1 = n_path
	{
		pathss[i] = ft_get_multi_paths(env);
		ft_delete_links(pathss, env);
	}
	if (!(env->paths = ft_best_path(pathss, env)))
		return (1);
	//ft_putstr(env->paths[0][1]->room);
	i = -1;
	while (pathss[++i])
		if (pathss[i] != env->paths)
			ft_free_transformed_path(pathss[i]);
	ft_memdel((void **)&pathss);
	return (0);
}
