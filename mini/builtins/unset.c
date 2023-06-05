/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:42:25 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/13 16:13:35 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	print_export(t_env *list, t_env *node)
{
	node = ft_export_sort(&list);
	while (node)
	{
		if (node->val != NULL)
			printf("declare -x %s=\"%s\"\n", node->key, node->val);
		else if (node->key != NULL)
			printf("declare -x %s\n", node->key);
		node = node->next;
	}
}

void	ft_freee(t_env *node)
{
	free(node->key);
	free(node->val);
}

void	uset_head(void)
{
	g_ecode.exit_staus = 1;
	ft_putstr2("unset", "not a valid identifier", 3);
}

void	ft_muly_unset(char *key, t_cd	un)
{
	while (un.node)
	{
		if (un.node->next
			&& ft_strcmp(un.node->next->key, key) == 0)
		{
			ft_freee(un.node->next);
			un.del = un.node->next;
			un.node->next = un.node->next->next;
			free(un.del);
		}
		un.node = un.node->next;
	}
}

t_env	*ft_unset(t_env **list, char **key)
{
	t_cd	un;
	t_env	*lst;

	un.i = 0;
	lst = *list;
	un.node = *list;
	while (key[++un.i] && un.node)
	{
		un.node = *list;
		if (!ft_strcmp("_", (*list)->key))
			continue ;
		if (ft_sheack_error(key[un.i], 0) == -1)
			return (ft_putstr2("unset", ": not a valid identifier", 4)
				, g_ecode.exit_staus = 1,*list);
		else if (ft_strcmp((*list)->key, key[un.i]) == 0)
		{
			*list = (*list)->next;
			ft_freee(un.node);
			free(un.node);
		}
		else
			ft_muly_unset(key[un.i], un);
	}
	return (g_ecode.exit_staus = 0, lst);
}
