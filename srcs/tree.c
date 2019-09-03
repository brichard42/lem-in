/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:04:30 by tlandema          #+#    #+#             */
/*   Updated: 2019/09/03 15:13:11 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include "../libft/includes/ft_printf.h"

t_nod	*ft_node_new(char *room)
{
	t_nod *new;

	if (!(new = (t_nod *)ft_memalloc(sizeof(t_nod))))
		return (NULL);
	if (!(new->room = ft_strdup(room)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	return (new);
}

void	ft_print_links(t_link *begin)
{
	if (!begin)
		return ;
	if (begin->right)
		ft_print_links(begin->right);
	if (begin->left)
		ft_print_links(begin->left);
	ft_printf("[%s]\n", begin->name);
}

void	ft_print_tree(t_nod *tree) // TO DELETE
{
	if (tree->right)
		ft_print_tree(tree->right);
	if (tree->left)
		ft_print_tree(tree->left);
	ft_printf("|%s\t|\t\t%d\t|\n", tree->room, tree->height);
	ft_print_links(tree->links);
}

int		ft_node_add(t_env *env, t_nod **tree, char *room, char s_e)
{
	if (!*tree)
	{
		if (!(*tree = ft_node_new(room)))
			return (1);
		if (s_e == 'e')
			env->end = *tree;
		else if (s_e == 's')
			env->start = *tree;
		return (0);
	}
	else if (ft_strcmp(room, (*tree)->room) < 0)
	{
		if (ft_node_add(env, &(*tree)->left, room, s_e))
			return (1);
	}
	else if (ft_strcmp(room, (*tree)->room) > 0)
	{
		if (ft_node_add(env, &(*tree)->right, room, s_e))
			return (1);
	}
	ft_balance_tree(tree, room);
	return (0);
}
