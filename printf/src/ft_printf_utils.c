#include "../include/ft_printf.h"

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int	len;
	char	*nb;

	len = 0;
	nb = ft_itoa(n);
	len = ft_printstr(nb);
	free(nb);
	return (len);
}

int	ft_printpercent(void)
{
	ft_putchar('%');
	return (1);
}
