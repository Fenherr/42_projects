/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:48:16 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/16 14:40:18 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static t_pipex	ft_clear_data(void)
{
	t_pipex	data;

	data.ac = -1;
	data.child = -1;
	data.nb_cmd = -1;
	data.infile = -1;
	data.outfile = -1;
	data.av = NULL;
	data.cmd = NULL;
	data.pid = NULL;
	data.pipe = NULL;
	data.envp = NULL;
	data.cmd_path = NULL;
	return (data);
}

static void	build_pipes(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < data->nb_cmd - 1)
	{
		if (pipe(data->pipe + 2 * i) == -1)
			ft_error("Pipe error");
		i++;
	}
}

t_pipex	ft_init(int ac, char **av, char **envp)
{
	t_pipex	data;

	data = ft_clear_data();
	data.ac = ac;
	data.av = av;
	data.envp = envp;
	data.nb_cmd = ac - 3;
	get_infile(&data);
	get_outfile(&data);
	build_pipes(&data);
	// data.pid = malloc(sizeof * data.pid * data.nb_cmd);
	// if (!data.pid)
	// 	ft_error("PID error");
	// data.pipe = malloc(sizeof(data.pipe) * 2 * (data.nb_cmd - 1));
	// if (!data.pipe)
	// 	ft_error("Pipe error");
	return (data);
}
