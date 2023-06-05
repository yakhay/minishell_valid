/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:36:57 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/07 18:22:46 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_printf_env(t_env *list, int i)
{
	t_env	*node;
	t_env	*ptr;

	ptr = list;
	node = list;
	while (list)
	{
		node = ptr;
		while (node)
		{
			if (i == node->index && node->val != NULL)
				printf("%s=%s\n", node->key, node->val);
			node = node->next;
		}
		list = list->next;
		i++;
	}
}

void	ft_env(t_env *list, char **str)
{
	if (str[1])
	{
		ft_putstr2("env", " No such file or directory", 3);
		g_ecode.exit_staus = 127;
		return ;
	}
	g_ecode.exit_staus = 0;
	ft_printf_env(list, 0);
}
