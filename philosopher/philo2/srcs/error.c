#include "../includes/philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_error(int nb_error)
{
	if (nb_error == 1)
		ft_putstr_fd("Error : Wrong amount of arguments\n", 2);
	else if (nb_error == 2)
		ft_putstr_fd("Error : There must be at leat a philosopher\n", 2);
	else if (nb_error == 3)
		ft_putstr_fd("Error : One argument is not correct\n", 2);
}