/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:22:40 by aderouba          #+#    #+#             */
/*   Updated: 2022/12/13 09:22:52 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*write_in_here_doc(char *limiter, t_data *data, int nb_cmd)
{
	char	*tmp;
	char	*name;
	int		cpid;
	int		status;

	signal(SIGINT, SIG_IGN);
	cpid = fork_heredoc(limiter, data, nb_cmd);
	waitpid(cpid, &status, 0);
	free(limiter);
	name = NULL;
	if (status == 0 && cpid != -1)
	{
		tmp = ft_itoa(nb_cmd);
		name = ft_strjoin(".heredoc", tmp);
		free(tmp);
	}
	else
		g_exit_status = 130;
	return (name);
}

int	get_start_limiter(char *buf, int start)
{
	char	quote;

	quote = '\0';
	while ((!(buf[start] == '<' && buf[start + 1] == '<') || quote != '\0')
		&& buf[start + 1])
	{
		quote = quote_gestion(buf[start], quote);
		start++;
	}
	if (buf[start] == '\0' || buf[start + 1] == '\0')
		return (-1);
	start += 2;
	while ((buf[start] == ' ' || buf[start] == '\t') && buf[start])
		start++;
	if (buf[start] == '\0')
		return (-1);
	return (start);
}

int	parse_heredoc(t_data *data, char *buf)
{
	char	*tmp;
	int		start;
	int		nb_cmd;

	start = 0;
	nb_cmd = 0;
	while (buf[start] && (data->pipe_error == -1 || nb_cmd < data->pipe_error))
	{
		start = get_start_limiter(buf, start);
		if (start == -1)
			return (1);
		tmp = get_to_write(&start, buf, data, nb_cmd);
		if (tmp == NULL)
		{
			ft_lstr_free(data->heredoc);
			data->heredoc = malloc(sizeof(char *));
			if (data->heredoc)
				data->heredoc[0] = NULL;
			return (0);
		}
		data->heredoc = ft_add_str(data->heredoc, tmp);
		nb_cmd++;
	}
	return (1);
}

char	*get_and_remove_first_heredoc(t_data *data)
{
	char	**heredoc;
	char	*res;
	int		i;

	i = 0;
	while (data->heredoc[i])
		i++;
	if (i == 0)
		return (NULL);
	heredoc = malloc(sizeof(char *) * (i));
	if (heredoc == NULL)
		return (NULL);
	res = data->heredoc[0];
	i = 1;
	while (data->heredoc[i])
	{
		heredoc[i - 1] = data->heredoc[i];
		i++;
	}
	heredoc[i - 1] = NULL;
	free(data->heredoc);
	data->heredoc = heredoc;
	return (res);
}

int	here_doc(t_data *data, t_cmd *cmd)
{
	int		res;
	char	*buf_write;

	buf_write = get_and_remove_first_heredoc(data);
	res = open(buf_write, O_RDONLY);
	cmd->heredoc = buf_write;
	return (res);
}
