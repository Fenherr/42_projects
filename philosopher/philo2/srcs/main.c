#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		nb_error;

	nb_error = 0;
	nb_error = ft_init(&data, ac, av);
	if (nb_error == 0)
		ft_begin(&data);
	else
		ft_error(nb_error);
}