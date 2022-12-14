/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:14:19 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/16 10:05:31 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	get_dec_part(const char *nptr, int neg)
{
	int		i;
	int		j;
	float	res;

	i = 0;
	while (nptr[i] != '.' && nptr[i] != '\0')
		i++;
	if (nptr[i] != '.')
		return (0.0);
	i++;
	j = 0;
	res = 0.0;
	while (nptr[i + j] != '\0')
	{
		res = res * 10.0 + (float)(nptr[i + j] - '0');
		j++;
	}
	while (j > 0)
	{
		res /= 10.0;
		j--;
	}
	if (neg)
		res *= -1.0;
	return (res);
}

float	ft_atof(const char *nptr)
{
	int		intpart;
	float	res;

	intpart = ft_atoi(nptr);
	res = (float)intpart;
	res += get_dec_part(nptr, res < 0);
	return (res);
}
