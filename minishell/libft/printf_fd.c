/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:55:57 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/21 17:22:10 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_string(char *str, int fd)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", fd);
		return ;
	}
	ft_putstr_fd(str, fd);
}

static void	print_pointer(void *p, int fd)
{
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", fd);
		return ;
	}
	ft_putstr_fd("0x", 1);
	ft_putunbr_base_fd((size_t)p, fd, "0123456789abcdef");
}

static void	print_float(double nb, int fd)
{
	int		intpart;
	float	decpart;

	intpart = nb;
	decpart = nb - (double)intpart;
	decpart *= 1000000.0;
	if (decpart < 0.0)
		decpart *= -1.0;
	ft_putnbr_fd(intpart, fd);
	ft_putstr_fd(".", fd);
	ft_putnbr_fd(decpart, fd);
}

static void	print_param(char c, va_list args, int fd)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), fd);
	else if (c == 's')
		print_string(va_arg(args, char *), fd);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), fd);
	else if (c == 'u')
		ft_putunbr_fd(va_arg(args, unsigned int), fd);
	else if (c == 'f')
		print_float(va_arg(args, double), fd);
	else if (c == 'x')
		ft_putunbr_base_fd(va_arg(args, unsigned int), fd, "0123456798abcdef");
	else if (c == 'b')
		ft_putunbr_base_fd(va_arg(args, unsigned int), fd, "01");
	else if (c == 'p')
		print_pointer(va_arg(args, void *), fd);
	else if (c == '%')
		ft_putchar_fd(c, fd);
}

void	ft_printf_fd(const char *str, int fd, ...)
{
	va_list	args;
	int		i;

	va_start(args, fd);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			print_param(str[i + 1], args, fd);
			i++;
		}
		else
			ft_putchar_fd(str[i], fd);
		i++;
	}
	va_end(args);
}
