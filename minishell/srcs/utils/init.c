/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:09:24 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/12/12 16:43:20 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_data	init_data(void)
{
	t_data	data;

	data.env = NULL;
	data.paths = NULL;
	data.heredoc = NULL;
	data.pids = NULL;
	return (data);
}

t_data	ft_init(char **envp)
{
	t_data	data;

	data = init_data();
	data.env = create_env(envp);
	data.paths = get_paths(data.env);
	data.heredoc = ft_calloc(sizeof(char *), 1);
	data.exit = -1;
	data.pipe_error = -1;
	return (data);
}
