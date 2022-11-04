#include "../includes/philo.h"

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->writing, NULL);
		pthread_mutex_init(&data->fork[i], NULL);
		pthread_mutex_init(&data->meal_check, NULL);
		pthread_mutex_init(&data->reaper, NULL);
		i++;
	}
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i;
		data->philo[i].nb_ate = 0;
		data->philo[i].l_fork = i;
		data->philo[i].r_fork = (i + 1) % data->nb_philo;
		data->philo[i].meal_time = 0;
		data->philo[i].data = data;
		i++;
	}
}

int	ft_init(t_data *data, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->all_eat = 0;
	data->is_dead = 0;
	if (data->nb_philo < 1)
		return (2);
	if (data->nb_philo > 250 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0)
		return (3);
	if (ac == 6 && ft_atoi(av[5]))
		data->meal_goal = ft_atoi(av[5]);
	else if (ac == 6 && ft_atoi(av[5]) < 1)
		return (3);
	else
		data->meal_goal = -1;
	init_mutex(data);
	init_philo(data);
	return (0);
}