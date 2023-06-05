/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:57:45 by smeftah-          #+#    #+#             */
/*   Updated: 2023/05/12 22:02:40 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn.h"

int	nspace_to_allocate(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '"')
		{
			i++;
			while (line[i] && line[i] != '"')
				i++;
		}
		else if (line[i] == 39)
		{
			i++;
			while (line[i] && line[i] != 39)
				i++;
		}
		check_nspace_to_allocate_util(line, &i, &j);
	}
	return (j);
}

int	add_space_help(char *line, int i, int j)
{
	int	d;

	d = j;
	if (line[(i)] == '"')
	{
		d++;
		(i)++;
		while (line[i] && line[(i)] != '"')
		{
			d++;
			(i)++;
		}
	}
	else if (line[i] == 39)
	{
		d++;
		(i)++;
		while (line[i] && line[(i)] != 39)
		{
			d++;
			(i)++;
		}
	}
	return (d);
}

int	l(char *line, int i, int s, char *c)
{
	if (s == 0)
	{
		if (line[i] == '|' || line[i] == '>' || line[i] == '<')
			return (1);
	}
	else if (s == 2)
	{
		if ((line[i] == '|' || line[i] == '>' || line[i] == '<')
			&& line[i - 1] != ' ')
			return (1);
	}
	else if (s == 1)
	{
		if ((line[i - 1] == '>' && line[i] == '>')
			|| (line[i - 1] == '<' && line[i] == '<'))
			return (1);
	}
	else
	{
		if (!line[i + 1] || ft_search(c, line[i + 1]) == 0
			|| line[i + 1] == ' ' || line[i + 1] == '\t')
			return (1);
	}
	return (0);
}

char	*add_space_help2(char *ret, t_help t, int j, int d)
{
	while (t.str[t.i])
	{
		d = add_space_help(t.str, t.i, j);
		while (j < d)
			ret[j++] = t.str[t.i++];
		if (t.i != 0 && l(t.str, t.i, 0, 0) && ret[j - 1] != ' ')
		{
			ret[j++] = 32;
			ret[j++] = t.str[t.i++];
			if (l(t.str, t.i, 1, 0))
				ret[j++] = t.str[t.i++];
			if (t.str[t.i] && t.str[t.i] != ' ')
				ret[j++] = 32;
		}
		else if (l(t.str, t.i, 0, 0) && t.str[t.i + 1] && t.str[t.i + 1] != ' ')
		{
			ret[j++] = t.str[t.i++];
			if (l(t.str, t.i, 1, 0))
				ret[j++] = t.str[t.i++];
			ret[j++] = 32;
		}
		else if (t.str[t.i])
			ret[j++] = t.str[t.i++];
	}
	return (ret[j] = '\0', ret);
}

char	*add_space(char	*line)
{
	int		i;
	char	*ret;
	t_help	t;
	int		d;
	int		j;

	i = 0;
	j = 0;
	d = 0;
	if (!line)
		return (NULL);
	if (syntax(line) == 0)
		return (NULL);
	ret = malloc(sizeof(char) * ft_strlen(line) + nspace_to_allocate(line) + 1);
	if (!ret)
		ft_error(0, 0, 1, 0);
	t.str = line;
	t.i = i;
	ret = add_space_help2(ret, t, j, d);
	return (ret);
}
