/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:13:15 by smeftah-          #+#    #+#             */
/*   Updated: 2023/05/12 18:49:55 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn.h"

int	syntax(char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		if (line[i] == '|')
		{
			j = i + 1;
			while (line[j] && (line[j] == ' '
					|| line[j] == '\t' || line[j] == '|'))
			{
				if (line[j] == '|')
				{
					ft_error("Error: syntax error near unexpected token `|` \n",
						0, 258, 0);
					return (0);
				}
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	help_check(char **str, int *i, t_info **info, t_list **l)
{
	int static	j;

	check_help(l, str, i, info);
	if ((*l)->input != -2)
		(*info)->input = (*l)->input;
	if ((*l)->output != -2)
		(*info)->output = (*l)->output;
	ft_lstadd_back1(l, ft_lstnew1(++j));
	if (!str[*i])
		return (0);
	(*l) = (*l)->next;
	(*l)->str = ft_strdup((*l)->prev->str);
	return (1);
}

int	found_nbr_utile(char *line, int *i, char c)
{
	(*i)++;
	while (line[(*i)] && line[(*i)] != c)
		(*i)++;
	if (!line[(*i)])
		return (1);
	else
		(*i)++;
	return (0);
}

int	found_nbr_qo(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '"')
		{
			if (found_nbr_utile(line, &i, '"') == 1)
				return (1);
		}
		else if (line[i] == 39)
		{
			if (found_nbr_utile(line, &i, 39) == 1)
				return (1);
		}
		else
			i++;
	}
	return (0);
}

int	ft_check_red_error(t_info t)
{
	int		i;
	t_info	*l;
	t_list	*tmp;
	char	*message;

	i = 0;
	l = &t;
	message = "Error: syntax error near unexpected token \n";
	while (l)
	{
		tmp = l->tok;
		while (tmp && tmp->type >= 0)
		{
			if ((tmp->type == 3 && !tmp->lim)
				|| (tmp->type >= 0 && tmp->type < 3 && !tmp->file)
				|| l->er != 0)
				return (ft_error(message, 0, 258, 0), 258);
			tmp = tmp->next;
		}
		l = l->next;
	}
	return (0);
}
