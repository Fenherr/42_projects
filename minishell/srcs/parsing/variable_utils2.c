/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:55:40 by aderouba          #+#    #+#             */
/*   Updated: 2022/12/05 09:53:34 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_name_envp(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && str[len] != '=')
		len++;
	return (ft_substr(str, 0, len));
}

char	*get_value_envp(char *str)
{
	int	i;
	int	len;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
		i++;
	if (str[i] == '\0')
		return (NULL);
	i++;
	len = i;
	while (str[i + len] != '\0')
		len++;
	return (ft_substr(str, i, len));
}

t_var	*create_var(t_list *env, char **envp, int i)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	if (var == NULL)
	{
		ft_lstclear(&env, free_var);
		return (NULL);
	}
	var->name = get_name_envp(envp[i]);
	var->value = get_value_envp(envp[i]);
	return (var);
}

t_var	*create_new_var(char *name, char *value)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	if (var == NULL)
		return (NULL);
	var->name = ft_strdup(name);
	if (value == NULL)
		var->value = NULL;
	else
		var->value = ft_strdup(value);
	return (var);
}
