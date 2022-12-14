/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:47:29 by aderouba          #+#    #+#             */
/*   Updated: 2022/12/12 15:25:56 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	test_input_bad_redirection(char *str, int *i, int j)
{
	while (str[j + *i] == '<')
		(*i)++;
	if (*i > 0 && str[j + *i] == '>')
	{
		ft_printf_fd("Error: syntax error near", 2);
		ft_printf_fd(" unexpected token `>'\n", 2);
		return (1);
	}
	else if (*i > 2)
	{
		ft_printf_fd("Error: syntax error near", 2);
		ft_printf_fd(" unexpected token `newline'\n", 2);
		return (1);
	}
	return (0);
}

int	test_output_bad_redirection(char *str, int *i, int j)
{
	while (str[j + *i] == '>')
		(*i)++;
	if (*i > 0 && str[j + *i] == '<')
	{
		ft_printf_fd("Error: syntax error near", 2);
		ft_printf_fd(" unexpected token `<'\n", 2);
		return (1);
	}
	else if (*i > 2)
	{
		ft_printf_fd("Error: syntax error near", 2);
		ft_printf_fd(" unexpected token `>'\n", 2);
		return (1);
	}
	return (0);
}

int	verif_valid_input(char *str)
{
	int		j;
	char	quote;

	j = 0;
	quote = '\0';
	while (str[j])
	{
		while (str[j] && (quote != '\0' || (str[j] != '>' && str[j] != '<')))
		{
			quote = quote_gestion(str[j], quote);
			j++;
		}
		if (str[j] == '\0')
			return (1);
		j++;
		if (str[j] == '\0')
			return (1);
		if (str[j] == str[j - 1])
			j++;
		while (str[j] != '\0' && (str[j] == ' ' || str[j] == '\t'))
			j++;
		if (str[j] == '\0' || str[j] == '>' || str[j] == '<')
			return (0);
	}
	return (1);
}

int	test_bad_redirection(char *str)
{
	int		j;

	if (!is_redirection(str))
		return (0);
	if (!ft_strcmp(str, "<") || !ft_strcmp(str, ">") || !ft_strcmp(str, "<<")
		|| !ft_strcmp(str, ">>") || !verif_valid_input(str))
	{
		ft_printf_fd("Error: invalid redirection\n", 2);
		return (1);
	}
	j = 0;
	while (str[j])
	{
		j = test_bad_redirection2(str, j);
		if (j == -1)
			return (1);
	}
	return (0);
}

int	error_arg(t_cmd *cmd)
{
	if (cmd->name && !ft_strcmp(cmd->name, "pwd") && cmd->arg[1] != NULL)
	{
		if (cmd->arg[1][0] == '-')
		{
			g_exit_status = 2;
			ft_printf_fd("Error: pwd: %s: invalid option\n", 2, cmd->arg[1]);
			return (1);
		}
	}
	if (cmd->name && !ft_strcmp(cmd->name, "env") && cmd->arg[1] != NULL)
	{
		if (cmd->arg[1][0] == '-')
		{
			g_exit_status = 125;
			ft_printf_fd("Error: env: %s: invalid option\n", 2, cmd->arg[1]);
			return (1);
		}
		else
		{
			g_exit_status = 127;
			ft_printf_fd("env: \'%s\': unwanted argument\n", 2, cmd->arg[1]);
			return (1);
		}
	}
	return (0);
}
