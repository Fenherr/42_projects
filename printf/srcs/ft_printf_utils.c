/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:33:24 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/04/20 15:47:06 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_check_flags(t_print *arr, const char *format, int i)
{
	if (format[i] == '.')
		arr->dot = 1;
	else if (format[i] == '-')
		arr->dash = 1;
	else if (format[i] == '0')
		arr->zero = 1;
	else if (format[i] == ' ')
		arr->sp = 1;
	else if (format[i] == '+')
		arr->sign = 1;
	else if (format[i] == '#')
		arr->hash = 1;
	i++;
}

void	ft_conversion(t_print *arr, const char *format, int i)
{
	if (format[i] == 'c')
		ft_print_char(arr);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_print_nbr(arr);
	else if (format[i] == 'u')
		ft_print_unbr(arr);
	else if (format[i] == 'p')
		ft_print_pointer(arr);
	else if (format[i] == 's')
		ft_print_string(arr);
	else if (format[i] == 'x')
		ft_print_hexamin(arr);
	else if (format[i] == 'X')
		ft_print_hexamaj(arr);
	else if (format[i] == '%')
		ft_putchar('%');
	i++;
}
