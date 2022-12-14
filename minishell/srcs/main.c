/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:50:47 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/12/13 12:29:15 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status = 0;

void	exit_minishell(char *buf, t_data *data)
{
	if (buf)
		free(buf);
	rl_clear_history();
	ft_lstr_free(data->paths);
	ft_lstclear(&data->env, free_var);
	if (data->heredoc)
		free(data->heredoc);
	if (data->exit < 0)
		ft_printf("exit\n");
	unlink(".heredoc");
	if (data->exit >= 0)
		exit(data->exit);
	exit(0);
}

int	is_empty(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] != ' ' && buf[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	parse_and_do_commands(t_data *data, char *buf)
{
	t_cmd	*cmds;

	if (is_empty(buf))
		(void)data;
	else if (!quote_error(buf) && !test_bad_redirection(buf))
	{
		pipe_error(data, buf);
		if (data->pipe_error == -1 && parse_heredoc(data, buf))
		{
			cmds = parse_buf(data, buf, data->paths);
			interprete_cmds(data, cmds);
			free_commands(cmds);
		}
	}
	else
		g_exit_status = 2;
	free(buf);
	ft_lstr_free(data->paths);
}

int	main(int argc, char **argv, char **envp)
{
	char	*buf;
	t_data	data;

	(void)argv;
	if (argc != 1)
		return (0);
	data = ft_init(envp);
	while (1)
	{
		ft_signals(1);
		buf = readline("Minishell: ");
		if (buf == NULL)
			exit_minishell(buf, &data);
		if (ft_strlen(buf) > 0)
			add_history(buf);
		parse_and_do_commands(&data, buf);
		data.paths = get_paths(data.env);
		if (data.exit >= 0)
			exit_minishell(NULL, &data);
	}
	return (0);
}
