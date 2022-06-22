#include "do_op.h"

int main(int ac, char **av)
{
	int	first;
	int	second;
	int	result;
	char	ope;

	first = atoi(av[1]);
	second = atoi(av[3]);
	ope = *av[2];
	if (ac == 4)
	{
		if (ope == '+')
			result = first + second;
		else if (ope == '-')
			result = first - second;
		else if (ope == '*')
			result = first * second;
		else if (ope == '/')
			result = first / second;
		else if (ope == '%')
			result = first % second;
		printf("%d\n", result);
	}
	else
		write(1, "\n", 1);
	return (0);
}