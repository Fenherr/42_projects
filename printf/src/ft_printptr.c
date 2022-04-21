#include "../include/ft_printf.h"

void	ft_putptr(unsigned int nb)
{
	if (nb >= 16)
	{
		ft_putptr(nb / 16);
		ft_putptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + 48), 1);
		else
			ft_putchar_fd((nb - 10 + 97), 1);
	}
}

int	ft_printptr(unsigned long int ptr)
{
	int	print_len;

	print_len = 0;
	print_len += write(1, "0x", 1);
	if (ptr == 0)
		print_len += write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		print_len += ft_len_hexa(ptr);
	}
	return (print_len);
}
