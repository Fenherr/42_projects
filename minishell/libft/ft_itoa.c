/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:56:42 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/02 17:13:50 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*recursive_write(char *str, long nb)
{
	int		i;

	if (nb >= 10)
		str = recursive_write(str, nb / 10);
	i = ft_strlen(str);
	str[i] = (nb % 10) + '0';
	str[i + 1] = '\0';
	return (str);
}

static int	get_size_char(long nb)
{
	int	res;

	res = 0;
	if (nb < 0)
	{
		res++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		nb /= 10;
		res++;
	}
	return (res + 1);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*res;

	nb = n;
	res = malloc(sizeof(char) * (get_size_char(nb) + 1));
	if (res == NULL)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
		res[1] = '\0';
		return (recursive_write(res, nb));
	}
	res[0] = '\0';
	return (recursive_write(res, nb));
}
