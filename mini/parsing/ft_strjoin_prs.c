/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_prs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:10:59 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/09 21:37:19 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn.h"

int	ft_strcmp1(char *s, char *s1, int len)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s1[i] || i < len)
	{
		if (s[i] != s1[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_str(char *s1, char *s2, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
		i = 1;
	}
	if (!s1 || !s2)
		return (NULL);
	if (!s2[0])
		return (free(s2), s1);
	str = malloc((ft_strl(s1) + ft_strl(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_str(s1, s2, str);
	free(s1);
	free(s2);
	return (s1 = NULL, s2 = NULL, str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s2)
	{
		s2 = malloc(1);
		s2[0] = '\0';
	}
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i++] = '\n';
	while (s2[j])
		str[i++] = s2[j++];
	return (str[i] = '\0', free(s1), free(s2), str);
}
