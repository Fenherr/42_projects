/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:28:05 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/07 12:17:34 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_space(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && (arg[i] == ' ' || arg[i] == '\t'))
		i++;
	if (arg[i] == '\0')
		return (1);
	return (0);
}

static int	is_number(char *arg)
{
	int	i;

	i = 0;
	if ((arg[0] == '-' || arg[0] == '+') && arg[1])
		i++;
	while (arg[i])
	{
		if ((arg[0] == '-' || arg[0] == '+') && !ft_isdigit(arg[1]))
			return (0);
		else if ((arg[i] == '-' || arg[i] == '+') && ft_isdigit(arg[i + 1])
			&& arg[i - 1] == ' ')
			return (1);
		else if (!ft_isdigit(arg[i]) && arg[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	check_limits(char *arg)
{
	if (ft_atoll(arg) > 2147483647 || ft_atoll(arg) < -2147483648)
		return (1);
	return (0);
}

void	is_dup(t_stack *lst)
{
	int	i;
	int	j;

	i = -1;
	while (++i < lst->len_a)
	{
		j = i;
		while (++j < lst->len_a)
		{
			if (lst->stack_a[j] == lst->stack_a[i])
			{
				ft_putstr_fd("Error\n", 2);
				free_stack(lst);
				exit(0);
			}
		}
	}
}

int	error(char *arg)
{
	if (is_number(arg) == 0 || check_limits(arg) == 1 || check_space(arg) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}
