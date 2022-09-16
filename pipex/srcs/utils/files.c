/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:28:39 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/16 10:46:22 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	get_infile(t_pipex *data)
{
	data->infile = open(data->av[1], O_RDONLY);
	if (data->infile == -1)
		ft_error(data->av[1]);
}

void	get_outfile(t_pipex *data)
{
	data->outfile = open(data->av[data->ac - 1], O_WRONLY | O_CREAT | O_TRUNC);
	if (data->outfile == -1)
		ft_error(data->av[data->ac - 1]);
}
