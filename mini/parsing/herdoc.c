/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:23:16 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/12 18:48:21 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn.h"

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		exit(5);
	}
}

void	ft_free0(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free (str[i++]);
	free(str);
}

void	here_doc_help(t_info *info, t_list *tmp, int *fd)
{
	char	*lim;
	char	*l;
	char	*ar;
	int		s_q;
	char	*line;

	while (1)
	{
		line = readline(">");
		if (!line)
			exit(1);
		l = ft_strjoin1(line, ft_strdup("\n"));
		lim = ft_strjoin1(skip_quotes_noexpand(tmp->lim, &s_q), ft_strdup("\n"));
		if (!l || ft_strncmp(l, lim, ft_strlen(l)) == 0)
			return (free(lim), free(l));
		if (s_q == 0)
			ar = ft_expand(l, info->env, 1);
		else
			ar = l;
		free(lim);
		write(fd[1], ar, ft_strlen(ar));
		free(ar);
	}
}

int	here_doc_help2(t_info *info, t_list *tmp, int file)
{
	int	id;
	int	st;

	pipe(info->fd);
	id = fork();
	if (id == 0)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, sig_handler);
		close(info->fd[0]);
		here_doc_help(info, tmp, info->fd);
		close(info->fd[1]);
		exit(1);
	}
	waitpid(id, &st, 0);
	if (WEXITSTATUS(st) == 5)
		return (-1);
	if (file == -4)
		info->input = info->fd[0];
	close(info->fd[1]);
	return (0);
}

int	here_doc(t_info **ll)
{
	t_info	*info;
	t_list	*tmp;
	int		file;

	info = *ll;
	while (info -> next)
	{
		tmp = info->tok;
		file = info->input;
		while (tmp ->next)
		{
			if (tmp->type == 3 && tmp->lim != NULL)
			{
				if (here_doc_help2(info, tmp, file) == -1)
					return (g_ecode.exit_staus = 1, -1);
			}
			tmp = tmp->next;
		}
		info = info->next;
	}
	return (0);
}
