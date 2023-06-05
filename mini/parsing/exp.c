/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:34:52 by smeftah-          #+#    #+#             */
/*   Updated: 2023/05/10 15:16:35 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn.h"

char	*ft_expand_utils(char *str, int *i, int *count)
{
	char	*cut;

	while (str[*i] && str[*i] != '$')
		(*i)++;
	if (str[*i] && ft_isalnum(str[(*i) + 1]) == 0 && str[(*i) + 1] != '"'
		&& str[(*i) + 1] != 39)
		return (fpart_exp(str, i, count));
	(*i)++;
		*count = *i;
	while (str[*count] && ft_isalnum(str[*count]) == 1)
		(*count)++;
	if (str[*count] == '_')
	{
		(*count)++;
		while (ft_isalnum(str[(*count)]) == 1 || str[*count] == '_')
			(*count)++;
		if (str[*count] == '_')
		(*count)++;
	}
	if (!str[*count])
		(*count)++;
		cut = ft_substr(str, *i, *count - (*i));
	return (cut);
}

char	*ft_expand_help(t_help *l, char *ll)
{
	char	*help;

	l->cut = ft_substr(l->str, 0, l->i - 1);
	l->str = some_modif(l->str, ll, l->i, l->k);
	l->k = ft_strlen(ll);
	help = ft_substr(l->str, l->i - 1, l->k);
	l->cut = ft_strjoin1(l->cut, help);
	if (!l->str[l->k -1] || !l->str[l->k])
	{
		free(l->cut);
		return (l->cut = NULL, ft_strdup(l->str));
	}
	if (ft_search(l->str + l->k, '$') == 1)
		return (ft_strjoin1(l->cut, ft_strdup(l->str + l->k + l->i -1)));
	return (free(l->cut), l->cut = NULL, NULL);
}

char	*ft_expand_help0(t_help *ll, char *help)
{
	char	*ret;

	ret = NULL;
	if (ll->k != 0 && !ll->str[ll->k - 1])
	{
		ret = ft_strdup(ll->cut);
		return (free(help), free(ll->cut), ll->cut = NULL, ret);
	}
	else if (!ll->str[ll->k])
		return (free(ll->cut), free(help), ft_strdup(ll->str));
	if (ll->str[ll->i] == '$')
	{
		ll->i ++;
		ll->k = ll->i;
		return (NULL);
	}
	free(help);
	help = ft_substr(ll->str, ll->k, ft_strlen(ll->str) - ll->k);
	if (ll->str && (!ll->str[ll->i]
			|| (ll->k != 0 && !ll->str[ll->k - 1]) || !ll->str[ll->k]
			|| !ll->cut[0] || ft_isalnum(ll->str[ll->i]) == 1))
		return (ft_strjoin1(ll->cut, help));
	return (free(help), NULL);
}

char	*ft_expand_help2(t_help *ll, char *l, char *help)
{
	if (l && l[0])
	{
		help = ft_expand_help(ll, l);
		if (help)
			return (help);
		return (NULL);
	}
	if (ll->cut)
		free(ll->cut);
	ll->cut = ft_substr(ll->str, 0, ll->i -1);
	if ((ll->k == 0 || !ll->str[ll->k - 1]) || !ll->str[ll->k]
		|| ft_search(ll->str + ll->k, '$') == 1 || ll->str[ll->i] == '$')
		return (ft_expand_help0(ll, help));
	free(help);
	help = ll->str;
	if (ll->k < ll->i)
		ll->str = ft_strdup(ll->str + ll->i - 1);
	else
		ll->str = ft_strdup(ll->str + ll->k);
	free(help);
	ll->str = ft_strjoin1(ft_strdup(ll->cut), ll->str);
	ll->k = ll->i - 1;
	ll->i--;
	return (free(ll->cut), ll->cut = NULL, NULL);
}

char	*ft_expand(char *str, t_env *env, int st)
{
	char	*l;
	t_help	ll;
	char	*help;

	l = NULL;
	ll = ft_init_t_help();
	ll.str = ft_strdup(str);
	if (ft_search(str, '$') == 1)
		return (free(ll.str), str);
	if (st == 0)
		return (free(ll.str), str);
	free(str);
	help = NULL;
	while (ft_search(ll.str + ll.k, '$') == 0)
	{
		l = ft_check_env(ft_expand_utils(ll.str, &ll.i, &ll.k), env);
		help = ft_expand_help2(&ll, l, help);
		free(l);
		if (help)
			return (free(ll.str), help);
		if (ll.k >= ft_strlen(ll.str) || !ll.str[ll.i] || !ll.str[ll.i + 1])
			break ;
	}
	return (free(ll.cut), ll.str);
}
