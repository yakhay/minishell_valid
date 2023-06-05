/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:11:19 by smeftah-          #+#    #+#             */
/*   Updated: 2023/05/12 18:48:38 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn.h"

int	check_position(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
			i++;
	}
	return (-1);
}

char	*ft_strrchr(char *s, char c)
{
	int	i;
	int	l;

	i = 0;
	l = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c)
			l = i;
		i++;
	}
	if (l == -1)
		return (NULL);
	return ((char *)s + l);
}

int	ft_error(char *s, char *value, int status, int ex)
{
	if (s)
		ft_putstr_fd(s, 2);
	if (value)
		ft_putstr_fd(value, 2);
	g_ecode.exit_staus = status;
	if (ex == 1)
		exit(status);
	return (0);
}

char	*ft_check_env(char *str, t_env *env)
{
	int		i;
	int		len;

	if (!env)
		return (NULL);
	i = 0;
	if (str[0] && str[1] && str[1] == '?' && str[0] == '$')
		return (free(str), ft_itoa(g_ecode.exit_staus));
	if (!str[0] || (str[0] == '$' && str[1] != '_'))
		return (str);
	else if (str[0] >= '0' && str[0] <= '9')
		return (free(str), ft_strdup(str + 1));
		len = ft_strlen(str);
	while (env)
	{
		if (str[0] == '$' && str[1] == '_')
			return (free(str), ft_last_word(g_ecode.last_cmd));
		else if (ft_strcmp1(env->key, str, ft_strlen(env->key)) == 0)
			return (free(str), ft_strdup(env->val));
		env = env->next;
	}
	return (free(str), str = NULL, NULL);
}

int	ft_search(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}
