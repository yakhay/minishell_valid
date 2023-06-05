/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:48:57 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/07 14:07:29 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <stdio.h>

void	printf_arg(char **cmd, int i)
{
	int	j;

	j = i;
	while (cmd[j])
	{
		printf("%s", cmd[j++]);
		if (cmd[j])
			printf(" ");
	}
	if (i == 1)
		printf("\n");
}

int	ft_echo(char **cmd)
{
	int	i;
	int	j;

	i = 1;
	while (cmd[i])
	{
		j = 1;
		if (cmd[i][0] == '-' && cmd[i][j] == 'n')
		{
			while (cmd[i][j] == 'n')
				j++;
			if (cmd[i][j] == '\0' && cmd[i + 1] == NULL)
				return (0);
			if (cmd[i][j] != '\0')
				return (printf_arg(cmd, i), 0);
		}
		else
			return (printf_arg(cmd, i), 0);
		i++;
	}
	printf("\n");
	return (g_ecode.exit_staus = 0, 0);
}
