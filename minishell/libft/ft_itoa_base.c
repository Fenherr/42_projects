/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:56:42 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/16 08:36:17 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*recursive_write(char *str, long nb, char *base, int base_len)
{
	int		i;

	if (nb >= base_len)
		str = recursive_write(str, nb / base_len, base, base_len);
	i = ft_strlen(str);
	str[i] = base[nb % base_len];
	str[i + 1] = '\0';
	return (str);
}

static int	get_size_char(long nb, int base_len)
{
	int	res;

	res = 0;
	if (nb < 0)
	{
		res++;
		nb *= -1;
	}
	while (nb >= base_len)
	{
		nb /= base_len;
		res++;
	}
	return (res + 1);
}

char	*ft_itoa_base(int n, char *base)
{
	long	nb;
	char	*res;
	int		base_len;

	base_len = ft_strlen(base);
	if (base_len <= 1)
		return (NULL);
	nb = n;
	res = malloc(sizeof(char) * (get_size_char(nb, base_len) + 1));
	if (res == NULL)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
		res[1] = '\0';
		return (recursive_write(res, nb, base, base_len));
	}
	res[0] = '\0';
	return (recursive_write(res, nb, base, base_len));
}
