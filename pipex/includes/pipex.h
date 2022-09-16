/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:56:57 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/16 15:05:58 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
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
}	t_pipex;

void	ft_error(char *str);
void	get_infile(t_pipex *data);
void	get_outfile(t_pipex *data);
void	ft_free(char *str, char **strs);
char	*get_cmd(char *cmd, t_pipex *data);
t_pipex	ft_init(int ac, char **av, char **envp);

#endif