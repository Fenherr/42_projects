/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:35:02 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/04/22 15:53:01 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_form(va_list args, const char form);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printptr(unsigned long long ptr);
int		ft_printnbr(int n);
int		ft_printunsigned(unsigned int n);
int		ft_printhexa(unsigned int nb, const char form);
int		ft_printpercent(void);

int		ft_len_hexa(unsigned int nb);
int		ft_nblen(unsigned int nb);
int		ft_len_ptr(unsigned long long nb);
char	*ft_uitoa(unsigned int n);
void	ft_putstr(char *str);
void	ft_putptr(unsigned long long nb);
void	ft_puthexa(unsigned int nb, const char form);

#endif
