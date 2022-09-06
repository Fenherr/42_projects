/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:56:57 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/06 10:39:44 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_pipex
{
	char	*cmd;
	char	*cmd_path;
	char	**path;
	int		infile;
	int		outfile;
	pid_t	pid;
}	t_pipex;

void	ft_error(char *file1, char *file2);