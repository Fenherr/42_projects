#include <unistd.h>

int ft_putnbr(int n)
{
	char nb;

	if (n >= 10)
		ft_putnbr(n / 10);
	nb = (n % 10) + '0';
	write(1, &nb, 1);
}

int main(int ac, char **av)
{
	(void)av;

	ft_putnbr(ac - 1);
	write(1, "\n", 1);
	return (0);
}