/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:56:20 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/09 14:16:32 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn.h"

int	ft_lstsize1(t_info *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

char	*skip_q_witout_ex_help(t_help l, char *s, int *s_q, int *i)
{
	while (l.str[(*i)])
	{
		if (l.str[(*i)] == 39)
		{
			*s_q = 1;
			(*i)++;
			while (l.str[(*i)] && l.str[(*i)] != 39)
				s[l.k++] = l.str[(*i)++];
			(*i)++;
		}
		else if (l.str[*i] == '"')
		{
			*s_q = 1;
			(*i)++;
			while (l.str[(*i)] && l.str[(*i)] != '"')
				s[l.k++] = l.str[(*i)++];
			(*i)++;
		}
		else
		{
			while (l.str[(*i)] && l.str[(*i)] != 39 && l.str[(*i)] != '"')
				s[l.k++] = l.str[(*i)++];
		}
	}
	return (s[l.k] = '\0', s);
}

char	*skip_quotes_noexpand(char *str, int *s_q)
{
	int		i;
	int		k;
	char	*s;
	t_help	t;

	i = 0;
	k = 0;
	*s_q = 0;
	if (!str)
		return (NULL);
	s = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	t.str = str;
	t.k = k;
	return (skip_q_witout_ex_help(t, s, s_q, &i));
}

int	skip_q_help(char *str, int *i, int k, int *st)
{
	char	c;

	c = str[(*i)];
	if (c == 39 || c == '"')
	{
		(*i)++;
		while (str[(*i)] && str[(*i)] != c)
		{
			if (c == 39)
				*st = 0;
			k++;
			(*i)++;
		}
		(*i)++;
	}
	else
	{
		while (str[(*i)] && str[(*i)] != 39 && str[(*i)] != '"')
		{
			*st = 2;
			k++;
			(*i)++;
		}
	}
	return (k);
}

char	*skip_quotes(char *str, int *st, t_env *env)
{
	int		i;
	char	*s;
	int		k;
	char	*ss;

	ss = NULL;
	i = 0;
	if (!str || *st == 0)
		return (str);
	while (str[i])
	{
		k = 0;
		*st = 1;
		k = skip_q_help(str, &i, k, st);
		if (*st != 2)
			s = ft_substr(str, i - k - 1, k);
		else
			s = ft_substr(str, i - k, k);
		if ((str[i] == '"' || str[i] == 39) && str[i -1] == '$')
			s[--k] = '\0';
		s = ft_expand(s, env, *st);
		ss = ft_strjoin1(ss, s);
	}
	return (ss);
}
