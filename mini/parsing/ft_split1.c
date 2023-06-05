/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:52:55 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/08 16:19:18 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn.h"

void	remp_help1(char *s, char *c, t_help *l, int d)
{
	while (s[l->i])
	{
		if (s[l->i] == '"')
		{
			d = remp_help(s, c, l, '"');
			if (d == 0)
				continue ;
			else if (d == 2)
				break ;
		}
		else if (s[l->i] == 39)
		{
			d = remp_help(s, c, l, 39);
			if (d == 0)
				continue ;
			else if (d == 2)
				break ;
		}
		else
		{
			if (remp_help0(s, c, l) == 1)
				break ;
		}
	}
}

static char	*remp(char *s, char *c, int *i)
{
	char	*str;
	t_help	l;
	int		r;

	r = 0;
	if (s[*i] == '\n' && (s[(*i) + 1] == '\n' || !s[(*i) + 1]))
	{
		(*i)++;
		return (ft_strdup(""));
	}
	while (ft_search(c, s[*i]) == 0)
		(*i)++;
	l.i = *i;
	l.k = 0;
	remp_help1(s, c, &l, r);
	r = l.i - l.k;
	str = ft_substr(s, r, l.k);
	*i = l.i;
	return (str);
}

int	calcul_help(char *s, char *c, char q, t_help *t)
{
	while (s[t->i] && s[t->i] != q)
		t->i++;
	if (!s[t->i])
		t->k++;
	else if (l(s, t->i, 4, c) == 1)
	{
		t->i++;
		if (ft_search(c, s[t->i]) == 0 || !s[t->i])
			t->k++;
		return (0);
	}
	else
	{
		t->i++;
		if (s[t->i] == '"' || s[t->i] == 39)
			return (0);
		while (s[t->i] && s[t->i] != q && s[t->i] != ' '
			&& s[t->i] != '\t' && ft_search(c, s[t->i + 1]))
			t->i++;
		if (!s[t->i] || ft_search(c, s[t->i]) == 0)
			t->k++;
		if (s[t->i] == '"' || s[t->i] == 39)
			return (0);
	}
	return (1);
}

static int	calcul(char *s, char *c)
{
	t_help	t;

	t = ft_init_t_help();
	while (s[t.i])
	{
		if (s[t.i] == '"')
		{
			t.i++;
			if (calcul_help(s, c, '"', &t) == 0)
				continue ;
		}
		else if (s[t.i] == 39)
		{
			t.i++;
			if (calcul_help(s, c, 39, &t) == 0)
				continue ;
		}
		if (s[t.i] && ft_search(c, s[t.i])
			&& (ft_search(c, s[t.i + 1]) == 0 || s[t.i + 1] == '\0'))
			t.k++;
		if (!s[t.i])
			break ;
		t.i++;
	}
	return (t.k);
}

char	**ft_split1(char *s, char *c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	j = calcul(s, c);
	j = empty_arg(s, j);
	str = (char **)malloc(sizeof(char *) * (j + 1));
	if (!str)
		return (NULL);
	while (k < j)
	{
		str[k] = remp(s, c, &i);
		if (str[k++])
			continue ;
		while (--k >= 0)
			free(str[k]);
		free(str);
		return (NULL);
	}
	return (str[k] = NULL, str);
}
