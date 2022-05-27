/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:16:45 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/02 12:22:26 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_checkminmax(int n)
{
	if (n == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int					i;
	int					sign;
	unsigned long long	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] <= '\r' && nptr[i] >= '\t'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57 && nptr)
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	if (i > 19 || nbr >= 9223372036854775808ULL)
		return (ft_checkminmax(sign));
	return (nbr * sign);
}
