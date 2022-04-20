/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 08:45:25 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/04/20 17:23:02 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print	*ft_initialise_arr(t_print *arr)
{
	arr->wdt = 0;
	arr->zero = 0;
	arr->dot = 0;
	arr->sign = 0;
	arr->len = 0;
	arr->hash = 0;
	arr->is_zero = 0;
	arr->dash = 0;
	arr->sp = 0;
	return (arr);
}

void	ft_check_format(t_print *arr, const char *format, int i)
{
	while ((format[i] != 'c' && format[i] != 'd')
		&& (format[i] != 'i' && format[i] != 'u')
		&& (format[i] != 's' && format[i] != 'p')
		&& (format[i] != 'x' && format[i] != 'X'))
		ft_check_flags(arr, format, i);
}

int	ft_print(const char *format, ...)
{
	int		i;
	int		ret;
	t_print	*arr;

	arr = (t_print *)malloc(sizeof(t_print));
	if (!arr)
		return (-1);
	ft_initialise_arr(arr);
	va_start(arr->args, format);
	i = -1;
	ret = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_check_format(arr, format, i + 1);
		else
			ret += write(1, &format[i], 1);
	}
	va_end(arr->args);
	ret += arr->len;
	free (arr);
	return (ret);
}
