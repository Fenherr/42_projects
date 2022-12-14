/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:51:43 by aderouba          #+#    #+#             */
/*   Updated: 2022/12/12 20:01:48 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_file(char *name, int flags)
{
	int	res;

	res = open(name, flags, 0644);
	if (res == -1 || open(name, O_DIRECTORY) != -1)
	{
		ft_printf_fd("Error: %s: No such file or directory\n", 2, name);
		return (-1);
	}
	return (res);
}

void	input_file(t_data *data, t_cmd *cmd, char **name, int heredoc)
{
	if (cmd->fd_in > 2)
		close(cmd->fd_in);
	if (cmd->heredoc)
	{
		unlink(cmd->heredoc);
		free(cmd->heredoc);
		cmd->heredoc = NULL;
	}
	if (heredoc)
		cmd->fd_in = here_doc(data, cmd);
	else
		cmd->fd_in = check_file(*name, O_RDONLY);
	free(*name);
	*name = NULL;
}

void	output_file(t_cmd *cmd, char **name, int append)
{
	if (cmd->fd_out > 2)
		close(cmd->fd_out);
	if (append)
		cmd->fd_out = check_file(*name, O_RDWR | O_APPEND | O_CREAT);
	else
		cmd->fd_out = check_file(*name, O_RDWR | O_TRUNC | O_CREAT);
	free(*name);
	*name = NULL;
}

char	*error_file(t_cmd *cmd, char *res, char **split_res)
{
	if (cmd->fd_in > 2)
		close(cmd->fd_in);
	if (cmd->fd_out > 2)
		close(cmd->fd_out);
	ft_lstr_free(split_res);
	g_exit_status = 1;
	return (res);
}

int	get_fd(t_data *data, t_cmd *cmd, char **name, int file_next)
{
	*name = replace_variable_to_value(data->env, *name);
	if (file_next == 1)
		input_file(data, cmd, name, 0);
	else if (file_next == 2)
		input_file(data, cmd, name, 1);
	else if (file_next == 3)
		output_file(cmd, name, 0);
	else if (file_next == 4)
		output_file(cmd, name, 1);
	return (0);
}
