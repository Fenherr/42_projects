/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 08:28:30 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/04/20 16:05:34 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_print
{
	va_list	args;
	int		wdt;
	int		zero;
	int		dot;
	int		dash;
	int		len;
	int		sign;
	int		hash;
	int		is_zero;
	int		sp;
}	t_print;

t_print	*ft_initialise_arr(t_print *arr);
void	ft_check_format(t_print *arr, const char *format, int i);
void	ft_check_flags(t_print *arr, const char *format, int i);
void	ft_conversion(t_print *arr, const char *format, int i);
int		ft_printf(const char *format, ...);
