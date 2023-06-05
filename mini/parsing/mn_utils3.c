/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:53:15 by smeftah-          #+#    #+#             */
/*   Updated: 2023/05/08 16:22:02 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn.h"

void	del1(t_list **ll)
{
	t_list	*l;
	t_list	*li;

	l = *ll;
	li = *ll;
	while (l)
	{
		li = l->next;
		if (l->file)
			free(l->file);
		if (l->lim)
			free(l->lim);
		if (l->str)
			free(l->str);
		free(l);
		l = li;
	}
	*ll = NULL;
}

void	ft_lstdelone1(t_info **lst, void (*del1)(t_list **))
{
	int	i;

	i = 0;
	if (*lst != NULL && del1 != NULL)
	{
		del1(&(*lst)-> tok);
		while ((*lst)->cmd && (*lst)->cmd[i])
			free((*lst)->cmd[i++]);
		free((*lst)->cmd);
		free (*lst);
	}
}

void	ft_free(t_info **l, char *s, char *s2)
{
	t_info	*tmp;
	t_info	*tmp1;

	tmp = *l;
	tmp1 = *l;
	while (tmp != NULL)
	{
		tmp1 = tmp -> next;
		ft_lstdelone1(&tmp, del1);
		tmp = tmp1;
	}
	*l = NULL;
	free(s);
	free(s2);
}

int	empty_arg(char *str, int j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (!str[i + 1] || str[i + 1] == '\n'))
			j++;
		i++;
	}
	return (j);
}

t_help	ft_init_t_help(void)
{
	t_help	l;

	l.str = NULL;
	l.cut = NULL;
	l.i = 0;
	l.k = 0;
	return (l);
}
