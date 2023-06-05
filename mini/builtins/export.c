/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:43:55 by yakhay            #+#    #+#             */
/*   Updated: 2023/05/13 16:03:37 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_exp_utilis1(t_export *ex, t_env *list, char **str)
{
	ex->count = 0;
	ex->ptr = malloc((ex->j +1) * sizeof(char));
	while (str[ex->i][ex->count] != '+')
	{
		ex->ptr[ex->count] = str[ex->i][ex->count];
		ex->count++;
	}
	ex->ptr[ex->count] = '\0';
	ex->nod = ft_sherch_key(list, ex->ptr);
	if (ex->nod == NULL)
		ft_lstadd_back(&list, ft_lstnew(ex->ptr,
				ft_strdup(str[ex->i] + ex->j + 2), ft_lstsize(list)));
	else
	{
		if (ex->nod->val != NULL && ex->nod->val[0] != '\0')
			ex->nod->val = ft_strjoin_and_free(ex->nod->val,
					ft_strdup(str[ex->i] + ex->j + 2));
		else
			ex->nod->val = ft_strdup(str[ex->i] + ex->j + 2);
		free(ex->ptr);
	}
}

void	ft_exp_utilis2(t_export *ex, t_env *list, char **str)
{
	ex->count = 0;
	ex->ptr = malloc((ex->j + 2) * sizeof(char));
	while (str[ex->i][ex->count] != '=')
	{
		ex->ptr[ex->count] = str[ex->i][ex->count];
		ex->count++;
	}
	ex->ptr[ex->count] = '\0';
	ex->nod = ft_sherch_key(list, ex->ptr);
	if (ex->nod == NULL)
		ft_lstadd_back(&list, ft_lstnew(ex->ptr,
				ft_strdup(str[ex->i] + ex->j + 2), ft_lstsize(list)));
	else
	{
		free(ex->ptr);
		free(ex->nod->val);
		ex->nod->val = ft_strdup(str[ex->i] + ex->j + 2);
	}
}

void	add_node(t_env *list, char **str, int i)
{
	t_env	*node;

	node = ft_sherch_key(list, str[i]);
	if (node == NULL)
		ft_lstadd_back(&list,
			ft_lstnew(ft_strdup(str[i]), NULL, ft_lstsize(list)));
}

void	ft_norm(t_export *ex, t_env *list, char **str, char c)
{
	if (c == '+')
		ft_exp_utilis1(ex, list, str);
	else
		ft_exp_utilis2(ex, list, str);
}

t_env	*ft_export(t_env *list, char **str)
{
	t_export	ex;

	if (!list)
		list = fill_struct(str);
	ex.tmp = list;
	if (str[1] == NULL)
		return (print_export(list, ex.tmp), list);
	ex.i = 0;
	while (str[++ex.i])
	{
		ex.j = ft_searsh(str[ex.i], '=');
		if (ft_sheack_error(str[ex.i], 1) == -1)
		{
			ft_putstr2(str[ex.i], " not a valid identifier", 2);
			if (!str[ex.i + 1])
				return (g_ecode.exit_staus = 1, list);
			continue ;
		}
		else if (ex.j != -1)
			ft_norm(&ex, list, str, str[ex.i][ex.j]);
		else
			add_node(list, str, ex.i);
	}
	return (ex.tmp = ft_export_sort(&list), g_ecode.exit_staus = 0, list);
}
