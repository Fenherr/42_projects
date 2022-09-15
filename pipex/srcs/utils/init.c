/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:48:16 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/15 14:32:19 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static t_pipex	ft_clear_data(void)
{
	t_pipex	pipex;

	pipex.ac = -1;
	pipex.child = -1;
	pipex.nb_cmd = -1;
	pipex.infile = -1;
	pipex.outfile = -1;
	pipex.av = NULL;
	pipex.cmd = NULL;
	pipex.pid = NULL;
	pipex.pipe = NULL;
	pipex.envp = NULL;
	pipex.cmd_path = NULL;
	return (pipex);
}

t_pipex	ft_init(int ac, char **av, char **envp)
{
	t_pipex pipex;
	
	pipex = ft_clear_data();
	pipex.ac = ac;
	pipex.av = av;
	pipex.envp = envp;
	pipex.nb_cmd = ac - 3;
	// pipex.pid = malloc(sizeof * pipex.pid * pipex.nb_cmd);
	// if (!pipex.pid)
	// 	ft_error("PID error");
	// pipex.pipe = malloc(sizeof(pipex.pipe) * 2 * (pipex.nb_cmd - 1));
	// if (!pipex.pipe)
	// 	ft_error("Pipe error");
	return (pipex);
}