/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:41:34 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/04/22 13:49:30 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nblen(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*nb;
	int		len;

	len = ft_nblen(n);
	nb = (char *)malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (0);
	nb[len] = '\0';
	while (n != 0)
	{
		nb[len - 1] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (nb);
}

int	ft_printunsigned(unsigned int n)
{
	int		print_len;
	char	*nb;

	print_len = 0;
	if (n == 0)
		print_len += write(1, "0", 1);
	else
	{
		nb = ft_uitoa(n);
		print_len += ft_printstr(nb);
		free(nb);
	}
	return (print_len);
}
