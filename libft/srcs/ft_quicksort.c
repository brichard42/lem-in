/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 16:39:14 by brichard          #+#    #+#             */
/*   Updated: 2019/05/19 17:40:54 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *tab, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[high];
	i = (low - 1);
	j = low;
	while (j < high)
	{
		if (tab[j] <= pivot)
		{
			++i;
			swap(&tab[i], &tab[j]);
		}
		++j;
	}
	swap(&tab[i + 1], &tab[high]);
	return (i + 1);
}

void		ft_quicksort(int *tab, int low, int high)
{
	int	p_i;

	if (low < high)
	{
		p_i = partition(tab, low, high);
		ft_quicksort(tab, low, p_i - 1);
		ft_quicksort(tab, p_i + 1, high);
	}
}
