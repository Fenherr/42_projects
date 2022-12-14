/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:55:40 by aderouba          #+#    #+#             */
/*   Updated: 2022/12/10 12:49:53 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_var(void *var)
{
	t_var	*tmp;

	tmp = (t_var *)var;
	if (tmp->name)
		free(tmp->name);
	if (tmp->value)
		free(tmp->value);
	free(tmp);
}

char	*get_variable_value(t_list *env, char *name)
{
	t_list	*actual;
	t_var	*tmp;

	if (ft_strlen(name) == 0)
		return (ft_strdup("$"));
	if (ft_strcmp(name, "?") == 0)
		return (ft_itoa(g_exit_status));
	actual = env;
	while (actual)
	{
		tmp = (t_var *)actual->content;
		if (ft_strcmp(tmp->name, name) == 0)
		{
			if (!tmp->value)
				return (ft_strdup("\0"));
			return (ft_strdup(tmp->value));
		}
		actual = actual->next;
	}
	return (ft_strdup("\0"));
}

void	add_new_variable(t_list *env, char *name, char *value)
{
	t_list	*new;
	t_var	*tmp;

	tmp = create_new_var(name, value);
	if (!tmp)
		return ;
	new = ft_lstnew(tmp);
	if (new == NULL)
	{
		free_var(tmp);
		return ;
	}
	ft_lstadd_back(&env, new);
}

void	set_variable_value(t_list *env, char *name, char *value)
{
	t_list	*actual;
	t_var	*tmp;

	actual = env;
	while (actual)
	{
		tmp = (t_var *)actual->content;
		if (ft_strcmp(tmp->name, name) == 0)
		{
			if (tmp->value && value == NULL)
				return ;
			if (tmp->value)
				free(tmp->value);
			if (value == NULL)
				tmp->value = NULL;
			else
				tmp->value = ft_strdup(value);
			return ;
		}
		actual = actual->next;
	}
	add_new_variable(env, name, value);
}

void	remove_variable(t_list *env, char *name)
{
	t_list	*actual;
	t_list	*next;

	actual = env;
	next = actual->next;
	if (ft_strcmp(((t_var *)actual->content)->name, name) == 0)
	{
		ft_lstdelone(actual, free_var);
		env = next;
		return ;
	}
	while (next)
	{
		if (ft_strcmp(((t_var *)next->content)->name, name) == 0)
		{
			actual->next = next->next;
			ft_lstdelone(next, free_var);
			return ;
		}
		actual = next;
		next = next->next;
	}
}
