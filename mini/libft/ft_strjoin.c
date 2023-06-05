/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:42 by smeftah-          #+#    #+#             */
/*   Updated: 2023/05/07 20:11:34 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_e(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	size_t	j;
	char	*s3;

	i = 0;
	j = 0;
	if (!s1)
		return (s2);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	s3 = malloc(sizeof(char) *(lens1 + lens2 + 2));
	if (!s3)
		return (NULL);
	while (j < lens1 && s1[i])
		s3[i++] = s1[j++];
	s3[i++] = '/';
	j = 0;
	while (s2 && j < lens2)
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}
