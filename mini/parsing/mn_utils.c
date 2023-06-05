/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:52:20 by smeftah-          #+#    #+#             */
/*   Updated: 2023/05/08 17:11:52 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn.h"

void	ft_lstadd_back1(t_list **lst, t_list *new)
{
	t_list	*l;

	if (!lst || !new)
		return ;
	l = *lst;
	if ((*lst) == NULL)
	{
		*lst = new;
		return ;
	}
	while (l -> next != NULL)
		l = l -> next;
	l -> next = new;
	new->prev = l;
}

void	ft_lstadd_back_sinfo(t_info **lst, t_info *new)
{
	t_info	*l;

	if (!lst || !new)
		return ;
	l = *lst;
	if ((*lst) == NULL)
	{
		*lst = new;
		return ;
	}
	while (l -> next != NULL)
		l = l -> next;
	l -> next = new;
	new->prev = l;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = (*lst);
	(*lst) = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!(lst))
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

t_list	*ft_lstnew1(int content)
{
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	l -> i = content;
	l->str = NULL;
	l->type = -1;
	l->file = NULL;
	l->input = -2;
	l->output = -2;
	l->lim = NULL;
	l -> next = NULL;
	l->prev = NULL;
	return (l);
}
