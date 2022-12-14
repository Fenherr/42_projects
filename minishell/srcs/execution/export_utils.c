/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:14:56 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/12/13 12:24:42 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	bad_name(char *str)
{
	int	i;

	if ((ft_isalpha(str[0]) == 0 && str[0] != '_')
		|| check_minus(str))
		return (1);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (str[i] == '+' && str[i + 1] != '=')
			return (1);
		i++;
	}
	return (0);
}

int	export_error(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[0] == '-')
		{
			g_exit_status = 2;
			ft_printf_fd("Error: export: %s: invalid option\n",
				2, arg);
			return (1);
		}
		else if (bad_name(arg))
		{
			g_exit_status = 1;
			ft_printf_fd("Error: export: `%s\': not a valid identifier\n",
				2, arg);
			return (1);
		}
		i++;
	}
	return (0);
}

void	if_char_is_plus(char *str, int i, t_data *data)
{
	char	*tmp;
	char	*name;
	char	*value;
	char	*tmp_val;

	name = ft_substr(str, 0, i - 1);
	tmp = get_variable_value(data->env, name);
	tmp_val = ft_substr(str, i + 1, ft_strlen(str) - (i + 1));
	value = ft_strjoin(tmp, tmp_val);
	set_variable_value(data->env, name, value);
	free(tmp);
	free(name);
	free(value);
	free(tmp_val);
}

void	if_char_is_egal(char *str, int i, t_data *data)
{
	char	*variable_name;
	char	*variable_value;

	if (str[i - 1] == '+')
		if_char_is_plus(str, i, data);
	else
	{
		variable_name = ft_substr(str, 0, i);
		variable_value = ft_substr(str, i + 1, ft_strlen(str) - (i + 1));
		set_variable_value(data->env, variable_name, variable_value);
		free(variable_name);
		free(variable_value);
	}
}

int	check_arg_export(t_data *data, char *str)
{
	int		i;

	if (is_in_str(str, '='))
	{
		i = 0;
		while (str[i] != '=' && str[i])
			i++;
		if_char_is_egal(str, i, data);
	}
	else
		set_variable_value(data->env, str, NULL);
	return (0);
}
