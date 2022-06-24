#include <unistd.h>

int is_blank(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void last_word(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (is_blank(str[i]))
		i--;
	while (str[i] && !is_blank(str[i]))
		i--;
	i++;
	while (str[i] && !is_blank(str[i]))
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		last_word(av[1]);
	write(1, "\n", 1);
	return (0);
}