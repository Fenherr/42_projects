/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:01:43 by aderouba          #+#    #+#             */
/*   Updated: 2022/12/13 12:22:44 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_minus(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=' && arg[i - 1] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	unset_error(t_cmd *cmd)
{
	int	i;

	i = 1;
	while (cmd->arg[i] != NULL)
	{
		if ((cmd->arg[i][0] == '-' || check_minus(cmd->arg[i])) && i == 1)
		{
			g_exit_status = 2;
			ft_printf_fd("Error: unset: %s: invalid option\n",
				2, cmd->arg[1]);
			return (1);
		}
		else if (bad_name(cmd->arg[i]))
		{
			g_exit_status = 1;
			ft_printf_fd("Error: unset: `%s\': not a valid identifier\n",
				2, cmd->arg[1]);
		}
		i++;
	}
	return (0);
}

void	execute_builtins(t_data *data, t_cmd *cmd)
{
	if (cmd->name && !ft_strcmp(cmd->name, "pwd"))
		print_pwd();
	else if (cmd->name && (!ft_strcmp(cmd->name, "~")
			|| !ft_strcmp(cmd->name, "cd")))
		cd_implement(data->env, cmd);
	else if (cmd->name && !ft_strcmp(cmd->name, "env"))
		env_builtin(data->env);
	else if (cmd->name && !ft_strcmp(cmd->name, "export"))
		export_builtin(data, cmd);
	else if (cmd->name && !ft_strcmp(cmd->name, "unset")
		&& !unset_error(cmd))
		unset_builtin(data, cmd);
	else if (cmd->name && !ft_strcmp(cmd->name, "echo"))
		echo_builtin(cmd);
}

int	modify_env2(t_cmd *cmd)
{
	if (cmd->name && !ft_strcmp(cmd->name, "false"))
	{
		g_exit_status = 1;
		return (1);
	}
	else if (cmd->name && !ft_strcmp(cmd->name, "true"))
	{
		g_exit_status = 0;
		return (1);
	}
	return (0);
}

int	modify_env(t_data *data, t_cmd *cmd)
{
	if (ft_strcmp(cmd->name, "unset") == 0)
	{
		if (!unset_error(cmd))
			unset_builtin(data, cmd);
		return (1);
	}
	if (ft_strcmp(cmd->name, "export") == 0 && cmd->arg[0] != NULL
		&& cmd->arg[1] != NULL)
	{
		export_builtin(data, cmd);
		return (1);
	}
	if (cmd->name && !ft_strcmp(cmd->name, "exit"))
	{
		exit_builtins(data, cmd);
		return (1);
	}
	if (cmd->name && !ft_strcmp(cmd->name, "cd"))
	{
		cd_implement(data->env, cmd);
		return (1);
	}
	return (modify_env2(cmd));
}
