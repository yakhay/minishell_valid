/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:19:15 by smeftah-          #+#    #+#             */
/*   Updated: 2023/05/09 23:51:50 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (-1);
}

static size_t	partone(char *str, char *s)
{
	size_t	i;

	i = 0;
	while (str[i] && check(s, str[i]) != -1)
		i++;
	return (i);
}

static size_t	partf(char *str, char *s)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && check(s, str[i]) != -1)
		i--;
	return (i);
}

char	*ft_strtrim(char *s1, char *set, int st)
{
	int		i;
	int		k;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = partone(s1, set);
	if (i == ft_strlen(s1))
		return (free(s1), ft_strdup(""));
	k = partf(s1, set);
	str = ft_substr(s1, i, (k - i) + 1);
	if (st == 1)
	{
		free(s1);
		s1 = NULL;
	}
	return (str);
}
