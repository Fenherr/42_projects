/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:38:55 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/27 13:47:44 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_check_nb_arg(int ac)
{
	if (ac < 5 || ac > 6)
		return (ERROR);
	else
		return (SUCCESS);
}

int	ft_check_arg(int ac, char **av)
{
	if (ft_check_nb_arg(ac))
	{
		if (ft_arg_are_digit(av))
		{
			if (!ft_arg_outside_limits(av))
				return (TRUE);
			return (ft_error_limits());
		}
		else
			return (ft_error_args());
	}
	return (ft_error_syntax());
}