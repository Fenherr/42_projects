/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:29:26 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/27 13:32:54 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_number(char *arg)
{
	int i;

	i = 0;
	if (arg[0] == '-' && arg[1])
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

static int check_limits(char *arg)
{
	if (ft_atoi(arg) > 2147483647 || ft_atoi(arg) < -2147483648)
		return (1);
	return (0);
}

int is_dup(t_stack *stack)
{
	t_stack *tmp;

	while (stack->next)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (tmp->content == stack->content)
			{
				ft_printf("Error\n");
				exit(0);
			}
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

int error(char *arg)
{
	if (is_number(arg) == 1 || check_limits(arg) == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
