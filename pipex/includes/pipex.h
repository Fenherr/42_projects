/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:56:57 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/12 14:04:34 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "../libft/libft.h"

typedef struct s_pipex
{
	char	*cmd;
	char	*cmd_path;
	char	**path;
	int		pipefd[2];
	int		infile;
	int		outfile;
	pid_t	pid;
}	t_pipex;

void	ft_error_files(char *file1, char *file2);
t_pipex	*ft_init(void);
void	ft_get_cmd_path(char **envp);