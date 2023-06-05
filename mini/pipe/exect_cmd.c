/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exect_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:12:18 by smeftah-          #+#    #+#             */
/*   Updated: 2023/05/13 16:40:09 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exect_cmd.h"

void	function1(int sig)
{
	(void)sig;
	g_ecode.exit_staus = 1;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	main_util(t_data *var, t_info *s, int i)
{
	var->pid = -1;
	var->size = ft_lstsize1(s) - 1;
	if (var->size > 1)
		var->pipp = malloc((var->size - 1) * sizeof(int *));
	var->i = 0;
	while (var->i < var->size - 1)
		var->pipp[var->i++] = malloc(2 * sizeof(int));
	var->pid = fork_and_pip(var, s);
	if (var->pid == -1)
		ft_putstr2("fork", "Resource temporarily unavailable\n", 3);
	ft_exec(var);
	waitpid(var->pid, &var->j, 0);
	while (wait(NULL) != -1)
		;
	var->ev = s->env;
	if (var->pid != -1 && var->pid != 0)
	{
		g_ecode.exit_staus = WEXITSTATUS(var->j);
		if (WIFSIGNALED(var->j))
			g_ecode.exit_staus = WTERMSIG(var->j) + 128;
	}
	while (var->size - 1 > i)
		free(var->pipp[i++]);
	if (var->size > 1)
		free(var->pipp);
}

int	main_utils2(t_data *var, t_info **s)
{
	tcsetattr(0, TCSANOW, &g_ecode.new_attr);
	signal(SIGINT, function1);
	signal(SIGQUIT, SIG_IGN);
	var->line = readline("mn$>> ");
	if (var->line && !var->line[0])
		return (free(var->line), 0);
	if (!var->line)
		write(2, "exit\n", 5);
	tcsetattr(0, TCSANOW, &g_ecode.old_attr);
	signal(SIGINT, SIG_IGN);
	add_history(var->line);
	if (!var->line)
		exit (1);
	var->line = ft_strtrim_lib(var->line, "\n");
	var->line_space = add_space(var->line);
	if (!var->line_space)
		return (free(var->line), 0);
	*s = ft_main_error(var->line, var->line_space, var->ev, &var->k);
	if (var->k == 0)
		return (free(var->line_space), 0);
	if (here_doc(s) == -1)
		return (ft_free(s, var->line_space, NULL), 0);
	if (ft_check_red_error(**s) == 258)
		return (ft_free(s, var->line_space, NULL), 0);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_data	var;
	t_info	*s;

	(void)ac;
	if (av [1])
		return (ft_putstr2(av[1],
				"No such file or directory", 3), exit (127), 0);
	s = NULL;
	g_ecode.last_cmd = ft_strdup(av[0]);
	tcgetattr(0, &g_ecode.old_attr);
	tcgetattr(0, &g_ecode.new_attr);
	g_ecode.new_attr.c_lflag &= ~ECHOCTL;
	var.ev = fill_struct(env);
	while (1)
	{
		var.k = 1;
		if (main_utils2(&var, &s) == 0)
			continue ;
		if (s->next)
			main_util(&var, s, 0);
		free(g_ecode.last_cmd);
		g_ecode.last_cmd = ft_strdup(var.line_space);
		free(var.line_space);
		ft_free(&s, NULL, NULL);
	}
}
