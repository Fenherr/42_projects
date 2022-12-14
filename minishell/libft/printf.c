/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:55:57 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/16 10:40:03 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_string(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return ;
	}
	ft_putstr_fd(str, 1);
}

static void	print_pointer(void *p)
{
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return ;
	}
	ft_putstr_fd("0x", 1);
	ft_putunbr_base_fd((size_t)p, 1, "0123456789abcdef");
}

static void	print_float(double nb)
{
	int		intpart;
	float	decpart;

	intpart = nb;
	decpart = nb - (double)intpart;
	decpart *= 1000000.0;
	if (decpart < 0.0)
		decpart *= -1.0;
	ft_putnbr_fd(intpart, 1);
	ft_putstr_fd(".", 1);
	ft_putnbr_fd(decpart, 1);
}

static void	print_param(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		print_string(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'f')
		print_float(va_arg(args, double));
	else if (c == 'x')
		ft_putunbr_base_fd(va_arg(args, unsigned int), 1, "0123456798abcdef");
	else if (c == 'b')
		ft_putunbr_base_fd(va_arg(args, unsigned int), 1, "01");
	else if (c == 'p')
		print_pointer(va_arg(args, void *));
	else if (c == '%')
		ft_putchar_fd(c, 1);
}

void	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			print_param(str[i + 1], args);
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
}
