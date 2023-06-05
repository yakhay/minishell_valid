/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:12:18 by smeftah-          #+#    #+#             */
/*   Updated: 2023/05/12 22:29:30 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exect_cmd.h"

void	ft_exec(t_data	*var)
{
	int	i;

	i = 0;
	while (i < var->size - 1)
	{
		close(var->pipp[i][0]);
		close(var->pipp[i][1]);
		i++;
	}
}

void	cheak_open_fill(t_info *info)
{
	if (info->output == -3)
	{
		write(2, "minishell: ambiguous redirect\n", 31);
		exit(1);
	}
	if (info->input == -1 || info->output == -1)
	{
		write(2, "minishell: No such file or directory \n", 39);
		exit(1);
	}
}

void	mult_pip(t_data *var, t_info *info, int c)
{
	cheak_open_fill(info);
	if (c == 1 && valider(info, var) == NULL)
		exit(1);
	if (var->size == 1)
	{
		if (info->input >= 0)
			dup2(info->input, 0);
		if (info->output >= 0)
			dup2(info->output, 1);
	}
	else if (var->size > 1)
	{
		if (info->input >= 0)
			dup2(info->input, 0);
		else if (info->input < 0 && info->index > 0)
			dup2(var->pipp[info->index - 1][0], 0);
		if (info->output >= 0)
			dup2(info->output, 1);
		else if (info->output < 0 && info->index < var->size - 1)
			dup2(var->pipp[info->index][1], 1);
	}
	ft_exec(var);
}

void	run_cmd_in_pros(t_data *var, t_info *info)
{
	char	**env;
	int		j;

	j = ft_dup_builtins(info->cmd);
	if (j != -1)
	{
		mult_pip(var, info, 0);
		builtins(&info->env, info->cmd, info->index);
		exit(0);
	}
	else
	{
		env = dup_lst_to_tbel(info->env);
		mult_pip(var, info, 1);
		execve(var->str, info->cmd, env);
		perror("error");
		exit (1);
	}
}

int	fork_and_pip(t_data *var, t_info *info)
{
	int	c;

	var->i = 0;
	while (var->size - 1 > var->i)
		if (pipe(var->pipp[var->i++]) == -1)
			return (var->pid);
	var->i = 0;
	if (var->size == 1 && ft_dup_builtins(info->cmd) == 1)
		return (builtins(&info->env, info->cmd, info->index), 0);
	while (var->i < var->size)
	{
		if (info->cmd && ft_strcmp(info->cmd[0], "exit") == 0 && var->size == 1)
			return (ft_exit(info->cmd, 1), 0);
		c = fork();
		if (c == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			run_cmd_in_pros(var, info);
		}
		info = info->next;
		var->i++;
	}
	return (c);
}
