/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:13:15 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/10 15:15:41 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn.h"

char	*some_modif(char *str, char *l, int i, int count)
{
	char	*ret;
	int		k;
	int		j;

	k = 0;
	ret = malloc(sizeof(char) * (i + ft_strlen(l)
				+ (ft_strlen(str) - count) + 2));
	if (!ret)
		return (NULL);
	j = 0;
	while (k < i -1)
		ret[k++] = str[j++];
	i = 0;
	while (i < ft_strlen(l))
		ret[k++] = l[i++];
	if (!str[count - 1])
	count --;
	while (str[count])
	{
		ret[k++] = str[count++];
	}
	ret[k] = '\0';
	return (free(str), ret);
}

char	*fpart_exp(char *str, int *i, int *count)
{
	char	*cut;

	(*count = (*i));
	if (str[*count] == '$' && (str[(*count) + 1] == '?'
			|| str[(*count) + 1] == '_'))
		(*count) += 2;
	else
	{
		if (str[*count] == '$')
			(*count)++;
		while (str[*count] && str[*count] != '$'
			&& str[*count] != ' ' && str[*count] != 39 && str[*count] != '"')
		(*count)++;
	}
	cut = ft_substr(str, *i, (*count) - (*i));
	(*i)++;
	return (cut);
}

int	rem_h(char *s, char q, t_help *l)
{
	l->i++;
	l->k++;
	while (s[l->i] && s[l->i] != q)
	{
		l->k++;
		l->i++;
	}
	if (!s[l->i])
		return (1);
	return (0);
}

int	remp_help(char *s, char *c, t_help *l, char q)
{
	if (rem_h(s, q, l) == 1)
		return (1);
	if (!s[l->i + 1] || ft_search(c, s[l->i + 1]) == 0
		|| s[l->i + 1] == ' ' || s[l->i + 1] == '\t')
	{
		l->k++;
		l->i++;
		if (s[l->i] == ' ' || s[l->i] == '\t')
			return (1);
	}
	else
	{
		l->i++;
		l->k++;
		if (s[l->i] == '"' || s[l->i] == 39)
			return (0);
		while (s[l->i] && s[l->i] != q && ft_search(c, s[l->i]))
		{
			l->i++;
			l->k++;
		}
		if (ft_search(c, s[l->i]) == 0 || !s[l->i])
			return (2);
	}
	return (1);
}

int	remp_help0(char *s, char *c, t_help *l)
{
	while (s[l->i] && ft_search(c, s[l->i]) && s[l->i] != '"' && s[l->i] != 39)
	{
		l->k++;
		l->i++;
	}
	if (!s[l->i] || ft_search(c, s[l->i]) == 0)
		return (1);
	return (0);
}
