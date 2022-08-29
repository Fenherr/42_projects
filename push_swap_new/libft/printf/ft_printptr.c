/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:41:07 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/02 13:32:53 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_len_ptr(unsigned long long nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

void	ft_putptr(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_putptr(nb / 16);
		ft_putptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + 48), 1);
		else
			ft_putchar_fd((nb - 10 + 97), 1);
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	print_len;

	print_len = 0;
	if (ptr == 0)
		print_len += write(1, "(nil)", 5);
	else
	{
		print_len += write(1, "0x", 2);
		ft_putptr(ptr);
		print_len += ft_len_ptr(ptr);
	}
	return (print_len);
}
