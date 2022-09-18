/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:56:57 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/18 20:51:43 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	char	*cmd_path;
	char	**av;
	char	**cmd;
	char	**envp;
	int		*pid;
	int		*pipe;
	int		ac;
	int		child;
	int		nb_cmd;
	int		infile;
	int		outfile;
	int		heredoc;
}	t_pipex;

void	close_fd(t_pipex *data);
void	get_infile(t_pipex *data);
void	get_outfile(t_pipex *data);
void	ft_free(char *str, char **strs);
void	ft_error(int erno, t_pipex *data);
int		ft_pipex(t_pipex *d);
int		error_msg(char *str, char *str2, char *str3, int erno);
char	*get_cmd(char *cmd, t_pipex *data);
t_pipex	ft_init(int ac, char **av, char **envp);

#endif