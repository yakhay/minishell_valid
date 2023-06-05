/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:43:05 by smeftah-          #+#    #+#             */
/*   Updated: 2023/05/09 18:36:34 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	if (!s || start < 0)
		return (NULL);
	if (start <= ft_strlen(s))
		l = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		start = 0;
	if (len < l)
		l = len;
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, l + 1);
	return (str);
}
