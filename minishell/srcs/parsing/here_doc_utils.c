/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:46:52 by aderouba          #+#    #+#             */
/*   Updated: 2022/12/13 09:23:24 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_to_write(int *start, char *buf, t_data *data, int nb_cmd)
{
	int		len;
	char	quote;
	char	*tmp;

	len = 0;
	quote = '\0';
	while (((buf[*start + len] != ' ' && buf[*start + len] != '\t'
				&& buf[*start + len] != '<' && buf[*start + len] != '>')
			|| quote != '\0') && buf[*start + len])
	{
		quote = quote_gestion(buf[*start + len], quote);
		len++;
	}
	tmp = interprete_quote(ft_substr(buf, *start, len));
	tmp = write_in_here_doc(tmp, data, nb_cmd);
	*start += len;
	return (tmp);
}

char	*free_and_do_heredoc(t_data *data, char *limiter, char *to_write)
{
	char	*tmp;

	ft_lstr_free(data->paths);
	ft_lstclear(&data->env, free_var);
	if (data->heredoc)
		ft_lstr_free(data->heredoc);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &exit_heredoc);
		tmp = readline("> ");
		if (g_exit_status == 130)
			break ;
		if (check_buf_heredoc(tmp, limiter) == 1)
			break ;
		tmp = ft_strjoin_free_1st_p(tmp, "\n");
		to_write = ft_strjoin_free_1st_p(to_write, tmp);
		free(tmp);
	}
	return (to_write);
}

void	in_fork_heredoc(t_data *data, char *limiter, char *to_write,
	int nb_cmd)
{
	char	*tmp;
	char	*name;
	int		fd;

	to_write = free_and_do_heredoc(data, limiter, to_write);
	free(limiter);
	if (g_exit_status == 130)
	{
		free(to_write);
		exit(1);
	}
	tmp = ft_itoa(nb_cmd);
	name = ft_strjoin(".heredoc", tmp);
	free(tmp);
	fd = open(name, O_RDWR | O_TRUNC | O_CREAT, 0644);
	free(name);
	if (fd == -1)
	{
		free(to_write);
		exit(1);
	}
	ft_printf_fd(to_write, fd);
	close(fd);
	free(to_write);
	exit(0);
}

int	fork_heredoc(char *limiter, t_data *data, int nb_cmd)
{
	int		cpid;
	char	*to_write;

	to_write = malloc(sizeof(char));
	if (!to_write)
		return (-1);
	to_write[0] = '\0';
	cpid = fork();
	if (cpid == 0)
	{
		in_fork_heredoc(data, limiter, to_write, nb_cmd);
	}
	free(to_write);
	return (cpid);
}
