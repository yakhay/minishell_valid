/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builins_utilis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:25:29 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/12 23:54:48 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while ((s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_num_alpha(char c, int j)
{
	if (c == '_' || c == '\\')
		return (0);
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (0);
	if (j > 0 && (c >= '0' && c <= '9'))
		return (0);
	return (-1);
}

int	ft_sheack_error(char *str, int code_exp)
{
	int	j;

	if (ft_num_alpha(str[0], 0) == -1)
		return (-1);
	j = 1;
	while (str[j])
	{
		if (code_exp == 1 && str[j] == '=')
			return (0);
		if (str[j] == '+' && str[j + 1] == '=')
			return (0);
		if (ft_num_alpha(str[j], j) == -1)
			return (-1);
			j++;
	}
	return (0);
}

t_env	*ft_export_sort(t_env **en)
{
	t_struc	data;

	data.head = *en;
	while (data.head)
	{
		data.env = data.head->next;
		while (data.env)
		{
			if (ft_strcmp(data.head->key, data.env->key) > 0)
			{
				data.str = data.head->key;
				data.head->key = data.env->key;
				data.env->key = data.str;
				data.ptr = data.head->val;
				data.head->val = data.env->val;
				data.env->val = data.ptr;
				data.c = data.head->index;
				data.head->index = data.env->index;
				data.env->index = data.c;
			}
			data.env = data.env->next;
		}
		data.head = data.head->next;
	}
	return (*en);
}

t_env	*ft_sherch_key(t_env *lst, char *key)
{
	while (lst)
	{
		if (ft_strcmp(key, lst->key) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
