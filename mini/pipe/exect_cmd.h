/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exect_cmd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:32:50 by yakhay            #+#    #+#             */
/*   Updated: 2023/06/03 15:21:44 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECT_CMD_H
# define EXECT_CMD_H

# include "../libft/libft.h"
# include "../builtins/builtins.h"
# include <readline/readline.h>
# include <readline/history.h>
# include "../parsing/mn.h"
# include <fcntl.h>
# include <dirent.h>

typedef struct data
{
	int		i;
	int		size;
	char	*str;
	char	**env;
	int		**pipp;
	char	*line;
	char	*line_space;
	int		k;
	int		pid;
	int		j;
	t_env	*ev;
}		t_data;
void	rl_replace_line(const char *text, int clear_undo);
void	ft_write_error(char *cmd);
void	mult_pip(t_data *var, t_info *info, int c);
void	ft_exec(t_data	*var);
void	cheak_open_fill(t_info *info);
void	run_cmd_in_pros(t_data *var, t_info *info);
int		fork_and_pip(t_data *var, t_info *info);
char	*valider(t_info *info, t_data *var);
int		ft_dup_builtins(char **str);
void	ft_putstr2(char *str, char *message, int c);
char	**dup_lst_to_tbel(t_env	*lst);
void	ft_spl_cmd(t_info *info);

#endif
