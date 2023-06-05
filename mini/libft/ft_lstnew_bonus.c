/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:25:11 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/07 20:19:19 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_env	*ft_lstnew(char	*key, char *val, int index)
{
	t_env	*khay;

	khay = (t_env *)malloc(sizeof(t_env));
	if (!khay)
		return (NULL);
	khay->key = key;
	khay->val = val;
	khay->index = index;
	khay->next = NULL;
	return (khay);
}

//#include <stdio.h>
//int main()
//{
//	int c = 4;
//	printf("%d",*((int *)ft_lstnew(&c)->content));
//}
