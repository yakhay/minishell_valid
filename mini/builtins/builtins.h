/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:56:11 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/12 23:42:44 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../pipe/exect_cmd.h"
# include "../parsing/mn.h"
# include <readline/readline.h>

typedef struct s_cd
{
	char	buf[10000];
	char	buf1[1000];
	t_env	*node;
	int		ret;
	char	*path;
	t_env	*del;
	int		i;
}		t_cd;

typedef struct s_export
{
	t_env	*tmp;
	t_env	*nod;
	char	*ptr;
	int		i;
	int		count;
	int		j;
}		t_export;

typedef struct struc
{
	int		c;
	t_env	*head;
	t_env	*env;
	char	*str;
	char	*ptr;
}		t_struc;

t_env	*cd(t_env **lst, char *option);
t_env	*ft_export_sort(t_env **en);
int		ft_num_alpha(char c, int j);
int		ft_echo(char **cmd);
int		ft_sheack_error(char *str, int c);
void	pwd(void);
t_env	*ft_export_sort(t_env **en);
int		ft_strcmp(const char *s1, const char *s2);
t_env	*ft_export(t_env *list, char **str);
t_env	*fill_struct(char **env);
int		ft_searsh(char *str, char c);
t_env	*ft_unset(t_env **list, char **key);
t_env	*ft_sherch_key(t_env *lst, char *key);
t_env	*builtins(t_env **lst, char **str, int i);
void	ft_exit(char **str, int i);
void	ft_env(t_env *list, char **str);
char	*ft_strjoin_and_free(char *s1, char *s2);
t_env	*ft_sherch_val(t_env *lst, char *val);
void	print_export(t_env *list, t_env *node);

#endif
