/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:53:14 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/08 17:19:09 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_chemg_pwd(t_cd *cd, t_env **lst)
{
	t_env	*node;
	t_env	*node1;

	if (getcwd(cd->buf, sizeof(cd->buf)) == NULL)
		perror("getcwd() error");
	node = ft_sherch_key(*lst, "PWD");
	if (!node)
		return (free(cd->path), 0);
	free(node->val);
	node->val = ft_strdup(cd->buf);
	node1 = ft_sherch_key(*lst, "OLDPWD");
	if (!node1)
		return (free(cd->path), 0);
	free(node1->val);
	node1->val = ft_strdup(cd->buf1);
	return (1);
}

t_env	*utilis_cd(t_cd *cd, t_env **lst, char *option)
{
	if (cd->path)
		cd->ret = chdir(cd->path);
	if (cd->ret == -1)
	{
		ft_putstr2(option, "no such file or directory", 1);
		return (free(cd->path), g_ecode.exit_staus = 1,*lst);
	}
	else
	{
		if (ft_chemg_pwd(cd, lst) == 0)
			return (*lst);
	}
	return (free(cd->path), *lst);
}

t_env	*cd(t_env **lst, char *option)
{
	t_cd	cd;

	g_ecode.exit_staus = 0;
	cd.ret = 0;
	cd.path = NULL;
	getcwd(cd.buf1, sizeof(cd.buf1));
	if (option)
		cd.ret = chdir(option);
	if (!option)
	{
		cd.node = ft_sherch_key(*lst, "HOME");
		if (!cd.node)
		{
			g_ecode.exit_staus = 1;
			return (ft_putstr2("cd", "HOME not set", 3), *lst);
		}
		cd.path = ft_strdup(cd.node->val);
	}
	else if (cd.ret == -1)
	{
		cd.path = ft_strjoin(ft_strdup(cd.buf), ft_strdup("/"));
		cd.path = ft_strjoin(cd.path, ft_strdup(option));
	}
	return (utilis_cd(&cd, lst, option));
}
