/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:02:48 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/10 18:11:28 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_searsh(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i - 1);
		i++;
	}
	return (-1);
}

void	ft_init_struct(t_env **local_env, char *env, int k)
{
	int		j;
	int		count;
	char	*str;

	str = NULL;
	j = ft_searsh(env, '=');
	if (j != -1)
	{
		str = malloc((j + 2) * sizeof(char));
		count = 0;
		while (env[count] != '=')
		{
			str[count] = env[count];
			count++;
		}
		str[count] = '\0';
		ft_lstadd_back(local_env, ft_lstnew(str, ft_strdup(env + j + 2), k));
	}
	else
		ft_lstadd_back(local_env, ft_lstnew(str, NULL, k));
}

t_env	*fill_struct(char **env)
{
	t_env	*local_env;
	char	*envdef[2];
	int		i;

	local_env = NULL;
	i = 0;
	if (env[0] == NULL)
	{
		envdef[0] = "_=/usr/bin/env";
		envdef[1] = NULL;
		env = envdef;
	}
	while (env[i])
	{
		ft_init_struct(&local_env, env[i], i);
		i++;
	}
	return (local_env);
}
