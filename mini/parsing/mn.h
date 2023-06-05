/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:08:38 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/12 18:50:18 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MN_H
# define MN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <termios.h>
# include <stdlib.h>
# include<unistd.h>
# include <stdio.h>
# include <errno.h>
# include <signal.h>
# include "../libft/libft.h"

typedef struct s_list
{
	char			*str;
	int				input;
	int				output;
	int				type;
	char			*file;
	char			*lim;
	int				i;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_info
{
	int				index;
	int				fd[2];
	char			**cmd;
	int				input;
	int				output;
	t_list			*tok;
	t_env			*env;
	char			**envv;
	int				er;
	int				exit_staus;
	struct termios	old_attr;
	struct termios	new_attr;
	char			*last_cmd;
	struct s_info	*next;
	struct s_info	*prev;
}	t_info;
t_info	g_ecode;

typedef struct s_help
{
	char	*str;
	char	*cut;
	int		i;
	int		k;
}	t_help;

char	**ft_split1(char *s, char *c);
void	ft_lstadd_back1(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew1(int content);
void	ft_lstadd_back_sinfo(t_info **lst, t_info *new);
int		ft_strcmp1(char *s, char *s1, int len);
char	*ft_check_env(char *str, t_env *env);
int		ft_search(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*some_modif(char *str, char *l, int i, int count);
char	*ft_expand(char *str, t_env *env, int st);
char	*skip_quotes(char *str, int *st, t_env *env);
int		check_position(char *str, char c);
char	*skip_quotes_noexpand(char *str, int *s_q);
void	ft_free(t_info **l, char *s, char *s2);
int		ft_error(char *s, char *value, int status, int ex);
char	*add_space(char	*line);
void	check_nspace_to_allocate_util(char *line, int *i, int *j);
t_list	*check(char **str, t_info **info);
int		check_bef_error_red(t_info t);
int		ft_check_red_error(t_info t);
int		found_nbr_qo(char *line);
int		check_bef_error_red0(t_list *t);
int		check_is_it_token(char *str);
t_help	ft_init_t_help(void);
t_env	*fill_struct(char **env);
void	ft_free0(char **str);
char	*ft_strjoin1(char *s1, char *s2);
int		ft_lstsize1(t_info *lst);
t_info	*ft_main_error(char *line, char *line_space, t_env *env, int *k);
int		check_valid_r1(char **r1);
t_info	*check_sinfo(char **str, t_env *env);
int		check_error(char **sh);
t_info	*ft_initialize(int i);
void	ft_free0(char **str);
void	check_nspace_to_allocate_util(char *line, int *i, int *j);
int		here_doc(t_info **ll);
int		here_doc_help2(t_info *info, t_list *tmp, int file);
void	here_doc_help(t_info *info, t_list *tmp, int *fd);
int		l(char *line, int i, int s, char *c);
int		help_check(char **str, int *i, t_info **info, t_list **l);
char	*fpart_exp(char *str, int *i, int *count);
char	*some_modif(char *str, char *l, int i, int count);
void	check_help(t_list **l, char **str, int *i, t_info **info);
int		remp_help0(char *s, char *c, t_help *l);
int		remp_help(char *s, char *c, t_help *l, char q);
int		empty_arg(char *str, int j);
t_info	*ft_initialize(int i);
char	*ft_last_word(char	*str);
int		syntax(char *line);

#endif
