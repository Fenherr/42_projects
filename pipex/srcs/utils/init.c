/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:48:16 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/14 14:28:32 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

t_pipex	*ft_init(int ac, char **av, char **envp)
{
	t_pipex *pipex;
	
	pipex = malloc(sizeof(t_pipex));
	pipex->infile = 0;
	pipex->outfile = 0;
	pipex->ac = ac;
	pipex->av = av;
	pipex->envp = envp;
	pipex->cmd_path = malloc(sizeof(char *));
	return (pipex);
}