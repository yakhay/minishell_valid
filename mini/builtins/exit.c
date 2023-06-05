/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:02:51 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/10 17:44:37 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	cheak_valid_arg(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (str[2])
	{
		if (j == 0 && (str[i][j] == '-' || str[i][j] == '+'))
			j++;
		while (str[i][j] && (str[i][j] >= '0' && str[i][j] <= '9'))
			j++;
	}
	if (j == ft_strlen(str[i]))
		return (-3);
	i = 1;
	j = 0;
	while (str[i][j])
	{
		if (j == 0 && (str[i][j] == '-' || str[i][j] == '+'))
			j++;
		if (!(str[i][j] >= '0' && str[i][j] <= '9'))
			return (-2);
		j++;
	}
	return (0);
}

void	ft_printf_err(char *str, char *ptr)
{
	write(2, "exit\n", 5);
	write(2, "exit:", 5);
	ft_putstr_fd(ptr, 2);
	ft_putstr_fd(str, 2);
}

void	ft_exit(char **str, int i)
{
	int	c;

	if (str[1] == NULL)
	{
		if (i == 0)
			printf("exit\n");
		exit(g_ecode.exit_staus);
	}
	if (cheak_valid_arg(str) == -1)
		return ;
	else if (cheak_valid_arg(str) == -3)
	{
		ft_printf_err(": too many arguments\n", str[1]);
		g_ecode.exit_staus = 1;
		return ;
	}
	else if (cheak_valid_arg(str) == -2)
	{
		ft_printf_err(": numeric argument required\n", str[1]);
		exit (255);
	}
	c = ft_atoi(str[1]);
	write(2, "exit\n", 5);
	exit(c);
}
