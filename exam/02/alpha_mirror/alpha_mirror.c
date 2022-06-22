#include <unistd.h>

char ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char *alpha_mirror(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a' || str[i] == 'A')
			str[i] += 25;
		else if (str[i] > 'a' && str[i] < 'z')
			str[i] = 'z' - (str[i] - 'a');
		else if (str[i] > 'A' && str[i] < 'Z')
			str[i] = 'Z' - (str[i] - 'A');
		else if (str[i] == 'z' || str[i] == 'Z')
			str[i] -= 25;
		i++;
	}
	return (str);
}

int main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
		ft_putstr(alpha_mirror(av[1]));
	write(1, "\n", 1);
	return (0);
}