/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:52:40 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/19 13:57:21 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	ft_error(int erno, t_pipex *data)
{
	if (data)
	{
		close_fd(data);
		if (data->pipe != NULL)
			free(data->pipe);
		if (data->pid != NULL)
			free(data->pid);
		if (data->cmd != NULL || data->cmd_path != NULL)
			ft_free(data->cmd_path, data->cmd);
	}
	if (data->heredoc == 1)
		unlink(".heredoc.tmp");
	exit(erno);
}

int	error_msg(char *str, char *str2, char *str3, int erno)
{
	ft_putstr_fd("pipex : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(str3, 2);
	ft_putchar_fd('\n', 2);
	return (erno);
}
