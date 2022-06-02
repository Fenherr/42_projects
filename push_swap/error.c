/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:29:26 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/02 15:13:24 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *arg)
{
	int	i;

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

int	check_limits(char *arg)
{
	if (ft_atoi(arg) >= 2147483647 || ft_atoi(arg) <= -2147483648)
		return (1);
	return (0);
}

int	error(char *arg)
{
	if (is_number(arg) == 1 || check_limits(arg) == 1)
		return (1);
	return (0);
}
