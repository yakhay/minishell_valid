/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeftah- <smeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:17:18 by smeftah-          #+#    #+#             */
/*   Updated: 2022/10/23 20:36:42 by smeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		l;

	i = 0;
	l = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			l = i;
		i++;
	}
	if (l == -1)
		return (NULL);
	return ((char *)s + l);
}
