/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:28:16 by aderouba          #+#    #+#             */
/*   Updated: 2022/12/09 15:37:33 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

long long	ft_atoll(const char *nptr)
{
	int			i;
	long long	res;
	long long	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * neg);
}

int	is_longlong_overflow(char *str, int start, int len, int neg)
{
	char	*tmp;

	tmp = ft_substr(str, start, len);
	if ((ft_strcmp(tmp, "9223372036854775807") > 0 && neg == 0)
		|| (ft_strcmp(tmp, "9223372036854775808") > 0 && neg == 1))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

int	is_longlong(char *str)
{
	int		start;
	int		len;

	start = 0;
	if (str[0] == '-' || str[0] == '+')
		start++;
	if (start == 1 && str[start] == '\0')
		return (0);
	while (str[start] == '0')
		start++;
	len = ft_strlen(str);
	if (len == 0 || len - start > 19)
		return (0);
	len = 0;
	while (str[start + len] >= '0' && str[start + len] <= '9')
		len++;
	if (start + len != ft_strlen(str))
		return (0);
	return (!is_longlong_overflow(str, start, len, str[0] == '-'));
}

void	change_exit_status(t_data *data, unsigned char status)
{
	if (data->exit == -1)
	{
		data->exit = (int)status;
		ft_printf("exit\n");
	}
}

void	exit_builtins(t_data *data, t_cmd *cmd)
{
	long long		atoll_res;
	unsigned char	exit_status;

	if (!cmd->arg[1])
	{
		change_exit_status(data, 0);
		return ;
	}
	if (!is_longlong(cmd->arg[1]))
	{
		change_exit_status(data, 2);
		ft_printf_fd("Error: exit: %s:", 2, cmd->arg[1]);
		ft_printf_fd(" numeric argument required\n", 2);
		return ;
	}
	if (cmd->arg[1] && cmd->arg[2])
	{
		ft_printf("exit\n");
		ft_printf_fd("Error: exit: too many arguments\n", 2);
		g_exit_status = 1;
		return ;
	}
	atoll_res = ft_atoll(cmd->arg[1]);
	exit_status = (unsigned char)atoll_res;
	change_exit_status(data, exit_status);
}
