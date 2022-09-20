/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:50:06 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/20 11:34:52 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static void	ft_redirect(int input, int output, t_pipex *data)
{
	if (dup2(input, STDIN_FILENO) == -1)
		ft_error(1, data);
	if (dup2(output, STDOUT_FILENO) == -1)
		ft_error(1, data);
}

static void	ft_child(t_pipex *d)
{
	if (d->child == 0)
		ft_redirect(d->infile, d->pipe[1], d);
	else if (d->child == d->nb_cmd - 1)
		ft_redirect(d->pipe[2 * d->child - 2], d->outfile, d);
	else
		ft_redirect(d->pipe[2 * d->child - 2], d->pipe[2 * d->child + 1], d);
	close_fd(d);
	if (d->cmd == NULL || d->cmd_path == NULL)
		ft_error(1, d);
	if (execve(d->cmd_path, d->cmd, d->envp) == -1)
		ft_error(error_msg(d->cmd[0], ": ", strerror(errno), 1), d);
}

static int	ft_parent(t_pipex *d)
{
	pid_t	wpid;
	int		status;
	int		exit_code;

	close_fd(d);
	d->child--;
	exit_code = 1;
	while (d->child >= 0)
	{
		wpid = waitpid(d->pid[d->child], &status, 0);
		if (wpid == d->pid[d->nb_cmd - 1])
		{
			if ((d->child == (d->nb_cmd - 1)) && WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
		}
		d->child--;
	}
	free(d->pipe);
	free(d->pid);
	return (exit_code);
}

int	ft_pipex(t_pipex *d)
{
	int	exit_code;

	d->child = 0;
	while (d->child < d->nb_cmd)
	{
		d->cmd = ft_split(d->av[d->child + 2 + d->heredoc], ' ');
		if (!d->cmd)
			ft_error(error_msg("unexpected error", "", "", 1), d);
		d->cmd_path = get_cmd(d->cmd[0], d);
		d->pid[d->child] = fork();
		if (d->pid[d->child] == -1)
			ft_error(error_msg("fork", ": ", strerror(errno), 1), d);
		else if (d->pid[d->child] == 0)
			ft_child(d);
		ft_free(d->cmd_path, d->cmd);
		d->child++;
	}
	exit_code = ft_parent(d);
	if (d->heredoc == 1)
		unlink(".heredoc.tmp");
	return (exit_code);
}
