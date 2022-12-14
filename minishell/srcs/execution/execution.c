/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:33:10 by aderouba          #+#    #+#             */
/*   Updated: 2022/12/13 13:03:48 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_and_quit_fork(t_data *data, t_cmd *cmds, int i, char **env_tmp)
{
	if (!env_tmp)
	{
		if (i != -1)
			execute_builtins(data, &cmds[i]);
		free_commands(cmds);
		ft_lstr_free(data->paths);
		ft_lstclear(&data->env, free_var);
		ft_lstr_free(data->heredoc);
		exit(0);
	}
	else
	{
		execve(cmds[i].arg[0], cmds[i].arg, env_tmp);
		ft_lstr_free(env_tmp);
		free_commands(cmds);
		ft_lstr_free(data->paths);
		ft_lstclear(&data->env, free_var);
		ft_lstr_free(data->heredoc);
		exit(5);
	}
}

int	execute_cmd(t_data *data, t_cmd *cmds, int i, int **pipes)
{
	int		cpid;

	ft_signals(2);
	cpid = fork();
	if (cpid == 0)
	{
		if (cmds[i].fd_in > 2)
			dup2(cmds[i].fd_in, STDIN_FILENO);
		if (cmds[i].fd_out > 2)
			dup2(cmds[i].fd_out, STDOUT_FILENO);
		close_fds(&cmds[i], pipes);
		free(data->pids);
		if (!cmds[i].name)
			exec_and_quit_fork(data, cmds, -1, NULL);
		if (is_bultin(cmds[i].name))
			exec_and_quit_fork(data, cmds, i, NULL);
		else
			exec_and_quit_fork(data, cmds, i, get_tab_env(data->env));
	}
	close_fds(&cmds[i], NULL);
	if (!cmds[i].name)
		return (-1);
	return (cpid);
}

void	execution_loop(t_data *data, t_cmd *cmds, int **pipes)
{
	int	i;

	i = 0;
	while (cmds[i].input != NULL)
	{
		data->pids[i] = -2;
		pipe_gestion(cmds, i, pipes[0], pipes[1]);
		if (data->exit == -1 && cmds[i].fd_in > -1 && cmds[i].fd_out > -1
			&& cmds[i].name && modify_env(data, &cmds[i])
			&& !error_arg(&cmds[i]))
			close_fds(&cmds[i], NULL);
		else if (!error_arg(&cmds[i]))
			data->pids[i] = execute_cmd(data, cmds, i, pipes);
		i++;
	}
	close_fds(NULL, pipes);
}

void	waitpid_loop(t_data *data, t_cmd *cmds)
{
	int	i;
	int	status;

	i = -1;
	while (cmds[++i].input != NULL)
	{
		if (data->pids[i] == -1)
			g_exit_status = 127;
		else if (data->pids[i] != -2)
		{
			waitpid(data->pids[i], &status, 0);
			if (status == 255)
				g_exit_status = 126;
			else if (status == 256)
				g_exit_status = 1;
			else if (status == 1280)
			{
				execution_error(cmds[i].arg[0]);
				g_exit_status = 126;
			}
			else if (status != 2 && status != 131 && g_exit_status != 125)
				g_exit_status = 0;
		}
	}
	change_g_status(&cmds[i - 1]);
}

void	interprete_cmds(t_data *data, t_cmd *cmds)
{
	int	pipe1[2];
	int	pipe2[2];
	int	*pipes[2];

	if (!cmds || !cmds[0].input || data->pipe_error != -1)
		return ;
	if (pipe(pipe1) == -1)
		return ;
	pipe2[0] = 0;
	pipe2[1] = 1;
	pipes[0] = pipe1;
	pipes[1] = pipe2;
	data->exit = -1 - (cmds[1].input != NULL);
	if (init_pids(data, cmds, pipes) == 0)
		return ;
	execution_loop(data, cmds, pipes);
	waitpid_loop(data, cmds);
	free(data->pids);
}
