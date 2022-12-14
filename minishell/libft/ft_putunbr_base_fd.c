/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:32:16 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/16 10:35:02 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_print(unsigned int n, int fd, char *base,
	unsigned int base_len)
{
	if (n >= base_len)
		recursive_print(n / base_len, fd, base, base_len);
	ft_putchar_fd(base[n % base_len], fd);
}

void	ft_putunbr_base_fd(unsigned int n, int fd, char *base)
{
	unsigned int		base_len;

	base_len = (unsigned int)ft_strlen(base);
	if (base_len <= 1)
		return ;
	recursive_print(n, fd, base, base_len);
}
