/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeftah- <smeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:33:27 by smeftah-          #+#    #+#             */
/*   Updated: 2022/10/27 12:40:32 by smeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	if (count > 0 && size > ((SIZE_MAX) / count))
		return (NULL);
	s = (char *)malloc(count * size);
	if (!s)
		return (NULL);
	ft_bzero(s, count * size);
	return ((void *)s);
}
