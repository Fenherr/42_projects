/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:14:19 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/16 08:50:29 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *nptr, char *base)
{
	int		i;
	int		base_len;
	long	res;
	long	neg;

	base_len = ft_strlen(base);
	if (base_len <= 1)
		return (0);
	i = 0;
	res = 0;
	neg = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (is_in_base(base, nptr[i]) != -1)
	{
		res = res * base_len + is_in_base(base, nptr[i]);
		if ((res > 2147483647 && neg == 1) || (res > 2147483648 && neg == -1))
			return (0);
		i++;
	}
	return (res * neg);
}
