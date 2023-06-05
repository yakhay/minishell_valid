/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeftah- <smeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:01:17 by smeftah-          #+#    #+#             */
/*   Updated: 2022/10/27 13:00:44 by smeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;
	t_list	*li;

	if (!lst || !(*lst) || !del)
		return ;
	li = *lst;
	l = *lst;
	while (l != NULL)
	{
		li = l -> next;
		ft_lstdelone(l, del);
		l = li;
	}
	*lst = NULL;
}
