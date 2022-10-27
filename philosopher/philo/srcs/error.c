/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:20:41 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/27 13:47:34 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error_args(void)
{
	printf("Only int for arguments please\n");
	return (ERROR);
}

int	ft_error_syntax(void)
{
	printf("Syntax error :\n");
	printf("True syntax >> ./philo [nb_philophers] [time_to_die] ");
	printf("[time_to_eat] [time_to_sleep] ([time_each_philo_must_eat])\n");
	return (FALSE);
}

int	ft_error_limits(void)
{
	printf("Argument(s) exceed(s) the limit of an int\n");
	return (ERROR);
}
