/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:19:57 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/12/10 10:08:55 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_pwd(void)
{
	char	*cwd;
	size_t	size;

	size = sizeof(char) * 1024;
	cwd = (char *)malloc(size);
	if (!cwd)
		perror("cwd malloc error");
	if (getcwd(cwd, size) == NULL)
		perror("getcwd error");
	return (cwd);
}

void	print_pwd(void)
{
	char	*cwd;

	cwd = ft_pwd();
	printf("%s\n", cwd);
	free(cwd);
}

void	cd_implement(t_list *env, t_cmd *cmd)
{
	char	*home;
	char	*tmp;

	home = get_variable_value(env, "HOME");
	tmp = ft_pwd();
	if (ft_strcmp(cmd->arg[0], "~") == 0 && cmd->arg[1] == NULL)
		ft_printf("minishell: %s: Is a directory\n", home);
	else if (ft_strcmp(cmd->arg[0], "cd") == 0)
		change_pwd_variable(env, home, cmd, tmp);
	free(home);
}

void	unset_builtin(t_data *data, t_cmd *cmd)
{
	int	i;

	if (!cmd->arg || !cmd->arg[0])
		return ;
	i = 1;
	while (cmd->arg[i])
	{
		remove_variable(data->env, cmd->arg[i]);
		i++;
	}
}

void	env_builtin(t_list *env)
{
	t_list	*actual;
	t_var	*tmp;

	actual = env;
	while (actual)
	{
		tmp = (t_var *)actual->content;
		if (tmp->value && ft_strcmp(tmp->name, "?") != 0)
			ft_printf("%s=%s\n", tmp->name, tmp->value);
		actual = actual->next;
	}
}
