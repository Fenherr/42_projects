/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:20:44 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/12/09 19:01:17 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	variables_changement(t_list *env, char *tmp)
{
	set_variable_value(env, "OLDPWD", tmp);
	free(tmp);
	tmp = ft_pwd();
	set_variable_value(env, "PWD", tmp);
	free(tmp);
}

void	change_pwd_variable(t_list *env, char *home, t_cmd *cmd, char *tmp)
{
	if (cmd->arg[1] == NULL || ft_strcmp(cmd->arg[1], "~") == 0)
	{
		if (chdir(home) == 0)
			variables_changement(env, tmp);
	}
	else if (ft_strcmp(cmd->arg[0], "cd") == 0 && cmd->arg[1])
	{
		if (chdir(cmd->arg[1]) == 0)
			variables_changement(env, tmp);
		else
		{
			g_exit_status = 1;
			if (access(cmd->arg[1], F_OK) == -1)
				ft_printf_fd("Error: cd: %s: No such file or directory\n", 2,
					cmd->arg[1]);
			else
				ft_printf_fd("cd: permission denied: %s\n", 2,
					cmd->arg[1]);
			free(tmp);
		}
	}
}
