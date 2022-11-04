#include "../includes/philo.h"

int	are_you_dead(t_data *data, t_philo philo)
{
	pthread_mutex_lock(&data->reaper);
	if (ft_get_time(data->start) - philo.meal_time > data->time_to_die)
	{
		ft_print_message(data, philo.id, "died");
		data->is_dead = 1;
		pthread_mutex_unlock(&data->reaper);
		return (TRUE);
	}
	pthread_mutex_unlock(&data->reaper);
	return (FALSE);
}

int	the_end(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (are_you_dead(data, data->philo[i]) == TRUE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	ft_check_if_is_dead(t_data *data)
{
	while (!data->all_eat)
	{
		pthread_mutex_lock(&data->meal_check);
		if (the_end(data) == TRUE)
		{
			pthread_mutex_unlock(&data->meal_check);
			usleep(100);
		}
		pthread_mutex_unlock(&data->meal_check);
	}
}