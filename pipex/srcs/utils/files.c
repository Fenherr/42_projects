/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:28:39 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/20 16:12:49 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	get_infile(t_pipex *data)
{
	data->infile = open(data->av[1], O_RDONLY, 644);
	if (data->infile == -1)
		error_msg(strerror(errno), ": ", data->av[1], 1);
}

void	get_outfile(t_pipex *d)
{
	d->outfile = open(d->av[d->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->outfile == -1)
		error_msg(strerror(errno), ": ", d->av[d->ac - 1], 1);
}
