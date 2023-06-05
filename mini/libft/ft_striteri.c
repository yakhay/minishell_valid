/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeftah- <smeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:52:01 by smeftah-          #+#    #+#             */
/*   Updated: 2022/10/27 12:10:45 by smeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	d;

	i = 0;
	if (!s || !f)
		return ;
	d = ((unsigned int)ft_strlen(s));
	while (i < d)
	{
		f(i, &s[i]);
		i++;
	}
}
