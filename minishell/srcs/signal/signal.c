/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:27:16 by aderouba          #+#    #+#             */
/*   Updated: 2022/12/12 16:51:41 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	prompt_ctrlc_management(int sig)
{
	(void)sig;
	g_exit_status = 130;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ctrlc_management(int sig)
{
	(void)sig;
	g_exit_status = 130;
	printf("\n");
}

void	backslach_management(int sig)
{
	(void)sig;
	g_exit_status = 131;
	ft_printf_fd("Quit (core dumped)\n", 2);
}

void	exit_heredoc(int sig)
{
	(void)sig;
	g_exit_status = 130;
	printf("\n");
	close(0);
}

void	ft_signals(int sig)
{
	if (sig == 1)
	{
		signal(SIGINT, prompt_ctrlc_management);
		signal(SIGQUIT, SIG_IGN);
	}
	if (sig == 2)
	{
		signal(SIGINT, ctrlc_management);
		signal(SIGQUIT, backslach_management);
	}
}
