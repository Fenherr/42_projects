/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_are_digit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:50:33 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/27 12:30:39 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_is_digit(int nb)
{
	if (nb >= 48 && nb <= 57)
		return (TRUE);
	else
		return (FALSE);
}

static int	ft_str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_digit(str[i]) == FALSE)
			return (FALSE);
		i++;	
	}
	return (TRUE);
}

int	ft_arg_are_digit(char **av)
{
	int	i;
	
	i = 1;
	while (av[i])
	{
		if (!ft_str_is_digit(av[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	ft_outside_limits(char *str)
{
	if (ft_atoll(str) > 2147483647)
		return (TRUE);
	return (FALSE);
}

int	ft_arg_outside_limits(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_outside_limits(av[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}