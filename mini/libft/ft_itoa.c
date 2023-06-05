/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeftah- <smeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:56:44 by smeftah-          #+#    #+#             */
/*   Updated: 2022/10/23 20:35:03 by smeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	powe(int l, long n)
{
	int	i;
	int	j;

	i = 1;
	j = l;
	while (i < n)
	{
		l *= j;
		i ++;
	}
	return (l);
}

static int	calcul(long *nbr, int *c, int *d)
{
	int		i;
	long	n;

	i = 0;
	*d = 0;
	*c = 0;
	if (*nbr == 0)
		*d = 1;
	if (*nbr < 0)
	{
		*nbr *= -1;
		*c = 1;
	}
	n = *nbr;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*numbre;
	int		i;
	int		c;
	int		j;
	long	n;

	n = (long)nbr;
	i = calcul(&n, &c, &j);
	numbre = (char *) malloc(sizeof(char) * (i + c + j + 1));
	j = 0;
	if (!numbre)
		return (NULL);
	if (c == 1)
		numbre[j++] = '-';
	while (i > 1)
	{
		numbre[j++] = (n / powe(10, i - 1)) + '0';
		n = n % powe(10, (i--) - 1);
	}
	numbre[j++] = n + '0';
	numbre[j] = '\0';
	return (numbre);
}
