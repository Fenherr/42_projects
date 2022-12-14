/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:31:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/12/08 10:44:12 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	only_n_option(char *str)
{
	int	i;

	i = 1;
	while (str && str[0] && str[0] == '-' && str[i] == 'n')
		i++;
	if (!str[0] || (str && (str[i] || i == 1)))
		return (0);
	return (1);
}

void	echo_print(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i] && only_n_option(arg[i]) == 1)
		i++;
	j = i;
	while (arg[j])
	{
		printf("%s", arg[j]);
		if (arg[j + 1] != NULL)
			printf(" ");
		j++;
	}
	if (i == 1)
		printf("\n");
}

void	echo_builtin(t_cmd *cmd)
{
	if (cmd->arg[1])
		echo_print(cmd->arg);
	else
		printf("\n");
}
