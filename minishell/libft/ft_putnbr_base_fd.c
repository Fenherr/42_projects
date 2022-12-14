/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:32:16 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/16 11:10:16 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_print(long n, int fd, char *base, int base_len)
{
	if (n >= base_len)
		recursive_print(n / base_len, fd, base, base_len);
	ft_putchar_fd(base[n % base_len], fd);
}

void	ft_putnbr_base_fd(int n, int fd, char *base)
{
	long	nb;
	int		base_len;

	base_len = ft_strlen(base);
	if (base_len <= 1)
		return ;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
	}
	recursive_print(nb, fd, base, base_len);
}
