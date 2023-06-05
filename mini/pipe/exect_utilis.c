/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exect_utilis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:12:18 by smeftah-          #+#    #+#             */
/*   Updated: 2023/05/13 13:38:33 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exect_cmd.h"

char	**dup_lst_to_tbel(t_env	*lst)
{
	char	**env;
	char	*str;
	t_env	*dup;
	int		i;

	i = 0;
	dup = lst;
	while (dup)
	{
		i++;
		dup = dup->next;
	}
	env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (lst)
	{
		str = ft_strjoin1(ft_strdup(lst->key), ft_strdup("="));
		str = ft_strjoin1(str, ft_strdup(lst->val));
		env[i++] = ft_strdup(str);
		free(str);
		str = NULL;
		lst = lst->next;
	}
	env[i] = NULL;
	return (env);
}

void	ft_putstr2(char *str, char *message, int c)
{
	int	i;

	i = 0;
	write(2, "minishell: ", 11);
	if (c == 1)
		write(2, "cd: ", 4);
	if (c == 2)
		write(2, "export: ", 8);
	while (str[i])
		write(2, &str[i++], 1);
	write(2, ": ", 2);
	i = 0;
	while (message[i])
		write(2, &message[i++], 1);
	write (1, "\n", 1);
}

void	ft_write_error(char *cmd)
{
	ft_putstr2(cmd, "command not found", 0);
	exit (127);
}

char	*return_path(t_info *info, t_data *var)
{
	char	**path;
	int		i;
	t_env	*node;

	node = ft_sherch_key(info->env, "PATH");
	if (node == NULL)
		return (ft_putstr2(info->cmd[0], "No such file or directory", 0),
			exit(127), NULL);
	path = ft_split(node->val, ':');
	i = 0;
	while (path && path[i])
	{
		var->str = ft_strjoin_e(path[i], info->cmd[0]);
		if (access(var->str, F_OK & X_OK) == 0)
			return (ft_free0(path), var->str);
		free(var->str);
		i++;
	}
	return (ft_free0(path), ft_write_error(info->cmd[0]), NULL);
}

char	*valider(t_info *info, t_data *var)
{
	DIR		*dir;

	ft_spl_cmd(info);
	if (info->cmd[0] && info->cmd[0][0] == '\0')
		return (ft_write_error(info->cmd[0]), NULL);
	if (info->env == NULL)
		return (ft_putstr2(info->cmd[0], "Permission denied", 0), NULL);
	if (ft_search(info->cmd[0], '/') == 0)
	{
		dir = opendir(info->cmd[0]);
		if (dir)
			return (free(dir), ft_putstr2(info->cmd[0],
					"is a directory", 3), exit (126), NULL);
		var->str = NULL;
		if (access(info->cmd[0], F_OK & X_OK) == 0)
			return (var->str = info->cmd[0], var->str);
		else
			return (ft_putstr2(info->cmd[0],
					"No such file or directory", 3), exit(127), NULL);
	}
	return (return_path(info, var));
}
