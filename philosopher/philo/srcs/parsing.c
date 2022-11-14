/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:05:33 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/27 12:46:27 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

static int	ft_string_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	ft_out_of_limits(char *str)
{
	if (ft_atoll(str) > 2147483647)
		return (TRUE);
	return (FALSE);
}

int	ft_arg_are_num(char **av)
{
	int	i;

	i = 1;
	while (av[i] && ft_atoi(av[i]) >= 0)
	{
		if (!ft_string_is_digit(av[i]))
			return (FALSE);
		if (ft_out_of_limits(av[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
