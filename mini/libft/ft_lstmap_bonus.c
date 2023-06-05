/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeftah- <smeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:34:49 by smeftah-          #+#    #+#             */
/*   Updated: 2022/10/27 12:36:52 by smeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*ll;

	if (!lst || !f || !del)
		return (NULL);
	l = NULL;
	while (lst != NULL)
	{
		ll = ft_lstnew(f(lst -> content));
		ft_lstadd_back(&l, ll);
		if (!ll)
		{
			ft_lstclear(&l, del);
			return (NULL);
		}
		lst = lst -> next;
	}
	return (l);
}
