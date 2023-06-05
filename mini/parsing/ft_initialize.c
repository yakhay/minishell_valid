/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:26:07 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/09 14:15:56 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn.h"

t_info	*ft_initialize(int i)
{
	t_info	*ll;

	ll = malloc(sizeof(t_info));
	if (!ll)
		return (NULL);
	ll->index = i;
	ll->cmd = NULL;
	ll->input = -2;
	ll ->output = -2;
	ll->tok = NULL;
	ll->next = NULL;
	ll->prev = NULL;
	return (ll);
}

char	*ft_last_word(char	*str)
{
	int		i;
	int		j;
	char	*ret;

	i = ft_strlen(str);
	i--;
	j = i;
	while (str[j] == ' ' || (str[j] == '\t'))
		j--;
	while (j >= 0 && str[j] != ' ' && str[j] != '\t')
		j--;
	ret = malloc((i - j + 1));
	if (!ret)
		return (NULL);
	j++;
	i = 0;
	while (str[j] && str[j] != ' ')
		ret[i++] = str[j++];
	ret[i] = '\0';
	return (ret);
}
