/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:56:57 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/15 10:29:00 by ngrenoux         ###   ########.fr       */
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
	char	*cmd_path;
	char	**cmd;
	char	**av;
	char	**envp;
	int		*pipe;
	int		*pid;
	int		ac;
	int		infile;
	int		outfile;
	int		nb_cmd;
	int		child;
}	t_pipex;

void	ft_free(char *str, char **strs);
void	ft_error(char *str);
char	*get_cmd(char *cmd, t_pipex *pipex);
t_pipex	ft_init(int ac, char **av, char **envp);