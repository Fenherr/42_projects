/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:48:16 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/12 10:24:25 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

t_pipex	*ft_init(void)
{
	t_pipex *pipex;
	
	pipex = malloc(sizeof(t_pipex));
	pipex->infile = 0;
	pipex->outfile = 0;
	pipex->cmd = malloc(sizeof(char *));
	pipex->cmd_path = malloc(sizeof(char *));
	pipex->path = (char **)malloc(sizeof(char *));
	return (pipex);
}