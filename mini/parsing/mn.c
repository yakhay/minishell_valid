/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:08:37 by smeftah-          #+#    #+#             */
/*   Updated: 2023/05/12 22:05:46 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn.h"
#include "signal.h"
#include <stdio.h>
#include <errno.h>
#include "fcntl.h"

void	check_nspace_to_allocate_util(char *line, int *i, int *j)
{
	if (*i != 0 && (line[(*i)] == '|' || line[(*i)] == '>' || line[(*i)] == '<')
		&& line[(*i) - 1] != ' ')
	{
		(*j)++;
		(*i)++;
		if ((line[(*i) - 1] == '>' && line[(*i)] == '>')
			|| (line[(*i) - 1] == '<' && line[(*i)] == '<'))
			(*i)++;
		if (line[(*i)] != ' ')
			(*j)++;
	}
	else if ((line[(*i)] == '|' || line[(*i)] == '>' || line[(*i)] == '<')
		&& line[(*i) + 1] && line[(*i) + 1] != ' ')
	{
		(*i)++;
		if ((line[(*i) - 1] == '>' && line[(*i)] == '>')
			|| (line[(*i) - 1] == '<' && line[(*i)] == '<'))
			(*i)++;
		(*j)++;
	}
	else
		(*i)++;
}

int	check_error(char **sh)
{
	int	i;

	i = 0 ;
	while (sh[i])
	{
		if (check_is_it_token(sh[i]) == 1)
		{
			if (check_is_it_token(sh[i + 1]) == 1)
				return (-1);
			else if (check_is_it_token(sh[i + 1]) == 2)
				return (-2);
		}
		i++;
	}
	return (0);
}

t_info	*check_sinfo(char **str, t_env *env)
{
	int		i;
	t_info	*l;
	char	**sh;
	t_info	*ret;

	i = -1;
	if (!str)
		return (NULL);
	l = ft_initialize(0);
	ret = l;
	while (str[++i])
	{
		l->index = i;
		l->env = env;
		sh = ft_split1(str[i], " \t");
		if (!sh)
			ft_error(NULL, NULL, 1, 0);
		l->er = check_error(sh);
		l->tok = check(sh, &l);
		l->cmd = ft_split1(ft_lstlast(l->tok)->str, "\n");
		ft_lstadd_back_sinfo(&l, ft_initialize(i));
		ft_free0(sh);
		l = l->next;
	}
	return (ft_free0(str), ret);
}

int	check_valid_r1(char **r1)
{
	int		i;
	char	*str;

	i = 0;
	if (!r1)
		return (-1);
	while (r1[i])
	{
		str = ft_strtrim(r1[i], " \t", 0);
		if (str && !str[0])
		{
			free(str);
			return (-1);
		}
		free(str);
		i++;
	}
	return (0);
}

t_info	*ft_main_error(char *line, char *line_space, t_env *env, int *k)
{
	char	**r1;

	if (found_nbr_qo(line) == 1)
	{
		ft_error("Error: unclosed quotes\n", 0, 1, 0);
		*k = 0;
		return (free(line), NULL);
	}
	line = ft_strtrim(line, " \t", 1);
	if (line[0] == '\0')
		return (free(line), line = NULL, *k = 0, NULL);
	r1 = ft_split1(line_space, "|");
	if (r1 && ((line && line[0] && (line[0] == '|'
					|| line[ft_strlen(line) - 1] == '|'))
			|| check_valid_r1(r1) == -1))
	{
		ft_error("Error: syntax error near unexpected token `|` \n", 0, 258, 0);
		ft_free0(r1);
		*k = 0;
		return (free(line), line = NULL, NULL);
	}
	return (free(line), check_sinfo(r1, env));
}
