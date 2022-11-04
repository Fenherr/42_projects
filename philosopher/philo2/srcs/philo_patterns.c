#include "../includes/philo.h"

void	ft_eating(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	if (data->nb_philo != 1)
	{
		pthread_mutex_lock(&data->fork[philo->l_fork]);
		ft_print_message(data, philo->id, "has taken a fork");
		pthread_mutex_lock(&data->fork[philo->r_fork]);
		ft_print_message(data, philo->id, "has taken a fork");
		pthread_mutex_lock(&data->meal_check);
		ft_print_message(data, philo->id, "is eating");
		philo->meal_time = ft_get_time(data->start);
		pthread_mutex_unlock(&data->meal_check);
		ft_smart_sleep(data, data->time_to_eat);
		philo->nb_ate++;
		pthread_mutex_unlock(&data->fork[philo->l_fork]);
		pthread_mutex_unlock(&data->fork[philo->r_fork]);
	}
}

void	*ft_patterns(void *args)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)args;
	data = philo->data;
	if (philo->id % 2)
		usleep(15000);
	while (!data->is_dead && data->nb_philo != 1)
	{
		ft_eating(philo);
		if (data->all_eat)
			break ;
		ft_print_message(data, philo->id, "is sleeping");
		ft_smart_sleep(data, data->time_to_sleep);
		ft_print_message(data, philo->id, "is thinking");
	}
	return (NULL);
}

void	ft_exit(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->writing);
}

void	ft_begin(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philo;
	while (i < data->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, &ft_patterns, &philo[i]);
		philo[i].meal_time = ft_get_time(data->start);
		i++;
	}
	ft_check_if_is_dead(data);
	ft_exit(data, philo);
}