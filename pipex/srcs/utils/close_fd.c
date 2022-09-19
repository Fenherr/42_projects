/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:26:31 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/19 11:40:14 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static void	close_fd_pipe(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < (data->nb_cmd - 1) * 2)
	{
		close(data->pipe[i]);
		i++;
	}
}

void	close_fd(t_pipex *data)
{
	if (data->infile != -1)
		close(data->infile);
	if (data->outfile != -1)
		close(data->outfile);
	close_fd_pipe(data);
}
