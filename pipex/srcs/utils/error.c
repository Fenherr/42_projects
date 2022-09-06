/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:52:40 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/06 09:54:50 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	ft_error_files(char *file1, char *file2)
{
	t_pipex *pipex;
	
	pipex->infile = open(file1, O_RDONLY);
	pipex->outfile = open(file2, O_CREAT);
	if (pipex->outfile == -1)
		perror(file2);
	else if (pipex->infile == -1)
		perror(file1);
	close(pipex->infile);
	close(pipex->outfile);
	exit(0);
}

void	ft_error(char *file1, char *file2)
{
	ft_error_files(file1, file2);
}