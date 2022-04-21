#include "../include/ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_form(va_list args, const char form)
{
	int	print_len;

	print_len = 0;
	if (form == 'c')
		print_len += ft_printchar(va_arg(args, int));
	else if (form == 's')
		print_len += ft_printstr(va_arg(args, char *));
	else if (form == 'p')
		print_len += ft_printptr(va_arg(args, unsigned long int));
	else if (form == 'd' || form == 'i')
		print_len += ft_printnbr(va_arg(args, int));
	else if (form == 'u')
		print_len += ft_printunsigned(va_arg(args, unsigned int));
	else if (form == 'x' || form == 'X')
		print_len += ft_printhexa(va_arg(args, unsigned int), form);
	else if (form == '%')
		print_len += ft_printpercent();
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	print_len;

	i = 0;
	print_len = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_len += ft_form(args, format[i + 1]);
			i++;
		}
		else
			print_len += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}

int	main(void)
{
	ft_printf("Bonjour");
	return (0);
}
