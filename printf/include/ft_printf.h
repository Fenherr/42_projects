#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_form(va_list args, const char form);
int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printptr(unsigned long int ptr);
int	ft_printnbr(int n);
int	ft_printunsigned(unsigned int);
int	ft_printhexa(unsigned int nb, const char form);
int	ft_printpercent(void);

int	ft_len_hexa(unsigned int nb);
int	ft_nblen(unsigned int nb);
char	*ft_uitoa(unsigned int n);
void	ft_putstr(char *str);
void	ft_putptr(unsigned int nb);
void	ft_puthexa(unsigned int nb, const char form);

#endif
