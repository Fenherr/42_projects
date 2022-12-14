/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:24:06 by aderouba          #+#    #+#             */
/*   Updated: 2022/12/13 10:27:39 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_command(t_cmd *command)
{
	if (command == NULL)
		return ;
	if (command->name != NULL)
		free(command->name);
	if (command->input != NULL)
		free(command->input);
	if (command->heredoc)
	{
		unlink(command->heredoc);
		free(command->heredoc);
	}
	ft_lstr_free(command->arg);
	if (command->fd_in > 2)
		close(command->fd_in);
	if (command->fd_out > 2)
		close(command->fd_out);
}

t_cmd	empty_command(char *input, int fd_int, int fd_out)
{
	t_cmd	command;

	command.name = NULL;
	command.input = input;
	command.heredoc = NULL;
	command.arg = NULL;
	command.fd_in = fd_int;
	command.fd_out = fd_out;
	return (command);
}

t_cmd	command_not_found(t_cmd *command, char *input, char *input_clean,
	char **split_res)
{
	int	fd;

	fd = -1;
	if (command->name)
	{
		fd = -2 - (ft_strncmp(command->name, "./", 2) == 0);
		if (ft_strncmp(command->name, "./", 2) == 0)
			ft_printf_fd("Error: Permission denied '%s'\n", 2, command->name);
		else
			ft_printf_fd("Error: Command '%s' not found\n", 2, command->name);
	}
	if (!input_clean && split_res)
		command->name = NULL;
	if (command->fd_in > 2)
		close(command->fd_in);
	if (command->fd_out > 2)
		close(command->fd_out);
	command->input = NULL;
	free_command(command);
	if (input_clean)
		free(input_clean);
	ft_lstr_free(split_res);
	return (empty_command(input, fd, fd));
}

t_cmd	get_cmd(t_data *data, char *input, char **paths)
{
	t_cmd	command;
	char	*input_clean;
	char	**split_res;

	if (input == NULL)
		return (empty_command(input, -2, -2));
	command = empty_command(input, 0, 1);
	input_clean = interprete_redirection(data, &command, input);
	if ((ft_strlen(input_clean) == 0 && ft_strlen(input) != 0)
		|| (command.fd_in == -1 && command.fd_out == -1))
		return (command_not_found(&command, input, input_clean, NULL));
	split_res = ft_split_quote(input_clean, " \t");
	if (split_res == NULL || split_res[0] == NULL)
		return (command_not_found(&command, input, input_clean, split_res));
	split_res[0] = replace_variable_to_value(data->env, split_res[0]);
	split_res = redo_split(split_res);
	split_res[0] = interprete_quote(split_res[0]);
	command.name = split_res[0];
	command.arg = get_arg(split_res, paths, data->env);
	free(input_clean);
	if (command.arg == NULL)
		return (command_not_found(&command, input, NULL, split_res));
	free(split_res);
	return (command);
}
