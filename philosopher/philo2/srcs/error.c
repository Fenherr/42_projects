/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:05:33 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/27 12:46:27 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	error_message(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error : ", 8);
	write(2, str, len);
	write(2, "\n", 1);
}

void	ft_error(int error)
{
	if (error == 1)
		error_message("Wrong amount of arguments");
	else if (error == 2)
		error_message("Ther emust be at least a philosohper");
	else if (error == 3)
		error_message("One argument is not correct");
}