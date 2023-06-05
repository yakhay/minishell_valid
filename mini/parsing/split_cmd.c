/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:11:45 by smeftah-          #+#    #+#             */
/*   Updated: 2023/05/12 22:14:10 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn.h"

int	check_is_it_token(char *str)
{
	if (!str)
		return (2);
	if (ft_strcmp1(str, "<<", 2) && ft_strcmp1(str, ">>", 2)
		&& ft_strcmp1(str, "<", 1) && ft_strcmp1(str, ">", 1))
		return (0);
	return (1);
}

int	remp_and_open_files(t_list **l, char *str, t_info *info, int st)
{
	if (!str && check_is_it_token(str) != 0)
		return (1);
	st = 1;
	if ((*l)->file)
		free((*l)->file);
		(*l)->file = skip_quotes(str, &st, info->env);
	if (info->input != -1 && info->output != -3 && info->er == 0)
	{
		if ((*l)-> type == 0 || (*l)->type == 1)
		{
			if (str[0] == '$' && ft_search((*l)->file, ' ') == 0)
				return ((*l)->output = -3, 0);
			if ((*l)->type == 0)
				(*l)->output = open((*l)->file, O_CREAT | O_APPEND
						| O_WRONLY, 0644);
			else
				(*l)->output = open((*l)->file, O_CREAT | O_TRUNC
						| O_WRONLY, 0644);
			if (str[0] == '$' && (*l)->output == -1)
				(*l)->output = -3;
		}
		else
			(*l)->input = open((*l)->file, O_RDONLY);
	}
	return (0);
}

void	check_type_tok(t_list **l, char **str, int *i, t_info *info)
{
	if (ft_strcmp1(str[*i], ">>", 2) == 0)
	{
		(*l)->type = 0;
		if (remp_and_open_files(l, str[(*i) + 1], info, 0) == 0)
			(*i)++;
	}
	else if (ft_strcmp1(str[*i], ">", 1) == 0)
	{
		(*l)->type = 1;
		if (remp_and_open_files(l, str[(*i) + 1], info, 0) == 0)
			(*i)++;
	}
	else
	{
		(*l)->type = 2;
		if (remp_and_open_files(l, str[(*i) + 1], info, 0) == 0)
			(*i)++;
	}
}

void	check_help(t_list **l, char **str, int *i, t_info **info)
{
	if (ft_strcmp1(str[(*i)], "<<", 2) == 0)
	{
		if (str[(*i) + 1] && check_is_it_token(str[(*i) + 1]) == 0)
		{
			(*l)->lim = ft_strdup(str[(*i) + 1]);
			(*i)++;
			if ((*info)->input != -1)
				(*l)->input = -4;
		}
		else
			(*l)->lim = NULL;
		(*l)->file = NULL;
		(*l)->type = 3;
	}
	else
	{
		(*l)->lim = NULL;
		check_type_tok(l, str, i, *info);
	}
}

t_list	*check(char **str, t_info **info)
{
	int		i;
	t_list	*l;
	t_list	*ll;
	int		st;
	int		k;

	ll = ft_lstnew1(0);
	l = ll;
	i = -1;
	k = 2;
	while (str[++i])
	{
		st = 1;
		str[i] = ft_strtrim(str[i], " \t", 1);
		if (ft_search(str[i], '$') == 0)
			l->str = ft_strjoin(l->str, skip_quotes(str[i], &st, (*info)->env));
		else if (check_is_it_token(str[i]) == 0)
			l->str = ft_strjoin(l->str, skip_quotes_noexpand(str[i], &k));
		else
		{
			if (help_check(str, &i, info, &l) == 0)
				break ;
		}
	}
	return (ll);
}
