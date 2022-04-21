#include "../include/ft_printf.h"

void	ft_puthexa(unsigned int nb, const char form)
{
	if(nb >= 16)
	{
		ft_puthexa(nb / 16, form);
		ft_puthexa(nb % 10, form);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + 48), 1);
		else
		{
			if (form == 'x')
				ft_putchar_fd((nb - 10 + 97), form);
			if (form == 'X')
				ft_putchar_fd((nb - 10 + 65), form);
		}
	}
}

int	ft_printhexa(unsigned int nb, const char form)
{
	if (nb == 0)
		return (ft_putchar('0'));
	else
		ft_puthexa(nb, form);
	return (ft_len_hexa(nb));
}
