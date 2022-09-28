/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:28:39 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/23 14:53:32 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static int	compare_limiter(char *av, char *line)
{
	if (ft_strlen(av) == ft_strlen(line)
		&& !ft_strncmp(line, av, ft_strlen(line)))
		return (1);
	return (0);
}

void	get_heredoc(t_pipex *d)
{
	int		fd_tmp;
	char	*tmp;
	char	*line;

	fd_tmp = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_tmp == -1)
		ft_error(error_msg("here_doc", ": ", strerror(errno), 1), d);
	line = "";
	while (1)
	{
		ft_putstr_fd("here_doc > ", 1);
		line = simpler_gnl(STDIN_FILENO);
		if (line == NULL)
			break ;
		tmp = ft_strjoin(d->av[2], "\n");
		if (compare_limiter(tmp, line) == 1)
			break ;
		else
			ft_putstr_fd(line, fd_tmp);
		free(tmp);
		free(line);
	}
	free(tmp);
	free(line);
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
		d->outfile = open(d->av[d->ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		d->outfile = open(d->av[d->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->outfile == -1)
		error_msg(strerror(errno), ": ", d->av[d->ac - 1], 1);
}
