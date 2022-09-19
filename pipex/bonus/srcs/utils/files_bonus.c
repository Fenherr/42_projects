/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:28:39 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/19 15:30:37 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	get_heredoc(t_pipex *d)
{
	int		fd_tmp;
	int		fd_stdin;
	char	*line;

	fd_tmp = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	fd_stdin = dup(STDIN_FILENO);
	if (fd_tmp == -1)
		ft_error(error_msg("here_doc", ": ", strerror(errno), 1), d);
	line = "";
	while (1)
	{
		ft_putstr_fd("here_doc > ", 1);
		line = simpler_gnl(fd_stdin);
		if (line == NULL)
			break ;
		if (ft_strlen(d->av[2]) + 1 == ft_strlen(line)
			&& !ft_strncmp(line, d->av[2], ft_strlen(d->av[2] + 1)))
			close(fd_stdin);
		else
			ft_putstr_fd(line, fd_tmp);
		free(line);
	}
	close(fd_tmp);
}

void	get_infile(t_pipex *data)
{
	if (data->heredoc == 1)
	{
		get_heredoc(data);
		data->infile = open(".heredoc.tmp", O_RDONLY);
		if (data->infile == -1)
			ft_error(error_msg("here_doc", ": ", strerror(errno), 1), data);
	}
	else
	{
		data->infile = open(data->av[1], O_RDONLY, 644);
		if (data->infile == -1)
			error_msg(strerror(errno), ": ", data->av[1], 1);
	}
}

void	get_outfile(t_pipex *d)
{
	if (d->heredoc == 1)
		d->outfile = open(d->av[d->ac - 1], O_WRONLY | O_CREAT | O_APPEND,
				0644);
	else
		d->outfile = open(d->av[d->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->outfile == -1)
		error_msg(strerror(errno), ": ", d->av[d->ac - 1], 1);
}
