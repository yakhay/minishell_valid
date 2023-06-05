/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:48:10 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/30 16:51:59 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exect_cmd.h"

void	ft_spl_cmd(t_info *info)
{
	t_env	*ent;
	char	**str;

	if (!info->cmd)
		exit (0);
	ent = ft_sherch_val(info->env, info->cmd[0]);
	if (!info->cmd[1] && ent)
	{
		str = ft_split1(info->cmd[0], " \t");
		ft_free0(info->cmd);
		info->cmd = str;
	}
}

void	ft_lowr(char **str)
{
	int	i;

	i = 0;
	while (str[0][i])
	{
		if (str[0][i] >= 'A' && str[0][i] <= 'Z')
			str[0][i] += 32;
		i++;
	}
}

int	ft_dup_builtins(char **str)
{
	if (!str)
		return (-1);
	if (ft_strcmp(str[0], "cd") == 0)
		return (1);
	else if (ft_strcmp(str[0], "echo") == 0)
		return (0);
	else if (ft_strcmp(str[0], "pwd") == 0)
		return (0);
	else if (ft_strcmp(str[0], "export") == 0)
	{
		if (!str[1])
			return (0);
		return (1);
	}
	else if (ft_strcmp(str[0], "env") == 0)
		return (0);
	else if (ft_strcmp(str[0], "exit") == 0)
		return (1);
	else if (ft_strcmp(str[0], "unset") == 0)
		return (1);
	return (-1);
}
